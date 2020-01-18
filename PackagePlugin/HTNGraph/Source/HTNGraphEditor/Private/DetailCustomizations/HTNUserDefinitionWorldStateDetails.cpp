// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HTNUserDefinitionWorldStateDetails.h"
#include "HTNGraphNode_PrimitiveTask.h"
#include "HTNGraph.h"
#include "HTNComponent.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/SWidget.h"
#include "Engine/GameViewportClient.h"
#include "Editor/EditorPerProjectUserSettings.h"
#include "Textures/SlateIcon.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "DetailWidgetRow.h"
#include "DetailLayoutBuilder.h"
#include "IPropertyUtilities.h"
#include "PropertyEditing.h"

#define LOCTEXT_NAMESPACE "HTNUserDefinitionWorldStateDetails"

TSharedRef<IPropertyTypeCustomization> FHTNUserDefinitionWorldStateDetails::MakeInstance()
{
	return MakeShareable(new FHTNUserDefinitionWorldStateDetails);
}

//#include "GameFramework/Character.h"
void FHTNUserDefinitionWorldStateDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	MyWorldStateKeyValueProperty = StructPropertyHandle->GetChildHandle(TEXT("WorldStateKeyValue"));

	WorldStateKeyValues.Reset();

	TArray<UObject*> MyObjects;
	StructPropertyHandle->GetOuterObjects(MyObjects);
	for (int32 i = 0; i < MyObjects.Num(); i++)
	{
		// �ڍ׃p�l���̃��C�A�E�g�� UHTNGraphNode�N���X ����������Enum�A�Z�b�g�ɑ΂��ēK�p�����
		UHTNGraphNode* NodeOb = Cast<UHTNGraphNode>(MyObjects[i]);
		if (NodeOb)
		{
			//CachedWorldStateEnumAsset = NodeOb->WorldStateEnumAsset;
			CachedWorldStateEnumAsset = NodeOb->GetTreeAsset()->WorldStateEnumAsset;
			break;
		}

		UHTNComponent* Component = Cast<UHTNComponent>(MyObjects[i]);
		if (Component)
		{
			CachedWorldStateEnumAsset = Component->GetWorldStateEnum();
			break;
		}
	}

	if (CachedWorldStateEnumAsset)
	{
		// EnumAsset�̍��ږ����擾��ComboBox�̃��j���[�G���g���Ɏg�p����
		for (int32 i = 0; i < CachedWorldStateEnumAsset->NumEnums() - 1; i++)
		{
			FString DisplayedName = CachedWorldStateEnumAsset->GetDisplayNameTextByIndex(i).ToString();
			WorldStateKeyValues.Add(DisplayedName);
		}
	}
}

void FHTNUserDefinitionWorldStateDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	// WorldStateKeyValue �ɂ��Ă�Slate��p���ăJ�X�^�}�C�Y����
	// ����́u���[�U�[�w���EnumAsset�v�̓��e�𔽉f����ComboBox���쐬���A��������l��I����������ɂ���������
	StructBuilder.AddCustomRow(LOCTEXT("TypeRow", "TypeRow"))
		.NameContent()
		[
			//SNew(STextBlock)
			//.Text(LOCTEXT("Title", "World State Key"))
			MyWorldStateKeyValueProperty->CreatePropertyNameWidget()
		]
		.ValueContent()
		[
			SNew(SComboButton)
			.OnGetMenuContent(this, &FHTNUserDefinitionWorldStateDetails::OnGetKeyContent)
			.IsEnabled(this, &FHTNUserDefinitionWorldStateDetails::IsEditingEnabled)
			.ContentPadding(FMargin(2.0f, 2.0f))
			.ButtonContent()
			[
				SNew(STextBlock)
				.Text(this, &FHTNUserDefinitionWorldStateDetails::GetCurrentKeyDesc)
				.Font(IDetailLayoutBuilder::GetDetailFont())
			]
		];
}

TSharedRef<SWidget> FHTNUserDefinitionWorldStateDetails::OnGetKeyContent() const
{
	FMenuBuilder MenuBuilder(true, NULL);

	for (int32 Idx = 0; Idx < WorldStateKeyValues.Num(); Idx++)
	{
		FUIAction ItemAction(FExecuteAction::CreateSP(const_cast<FHTNUserDefinitionWorldStateDetails*>(this), &FHTNUserDefinitionWorldStateDetails::OnKeyComboChange, Idx));
		MenuBuilder.AddMenuEntry(FText::FromString(WorldStateKeyValues[Idx]), TAttribute<FText>(), FSlateIcon(), ItemAction);
	}

	return MenuBuilder.MakeWidget();
}

FText FHTNUserDefinitionWorldStateDetails::GetCurrentKeyDesc() const
{
	FPropertyAccess::Result Result = FPropertyAccess::Fail;
	int32 CurrentIntValue = INDEX_NONE;

	if (CachedWorldStateEnumAsset)
	{
		Result = MyWorldStateKeyValueProperty->GetValue(CurrentIntValue);
	}

	return (Result == FPropertyAccess::Success && WorldStateKeyValues.IsValidIndex(CurrentIntValue))
		? FText::FromString(WorldStateKeyValues[CurrentIntValue])
		: FText::GetEmpty();
}

void FHTNUserDefinitionWorldStateDetails::OnKeyComboChange(int32 Index)
{
	MyWorldStateKeyValueProperty->SetValue(Index);
}

bool FHTNUserDefinitionWorldStateDetails::IsEditingEnabled() const
{
	return true;
}

#undef LOCTEXT_NAMESPACE
