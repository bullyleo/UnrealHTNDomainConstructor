// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SWidget.h"
#include "Widgets/Input/STextComboBox.h"
#include "UnrealClient.h"
#include "PropertyEditor/Public/IDetailCustomization.h"

class IPropertyHandle;

//--------------------------------------------------------------
// World State��Operation�ɗp����Enum�A�Z�b�g�̏ڍ׃p�l���̃��C�A�E�g���`����
//--------------------------------------------------------------
class FHTNPrimitiveTaskCustomDetails : public IDetailCustomization
{
public:
	// ����̏ڍ׃p�l���̃��C�A�E�g�N���X�C���X�^���X���쐬����
	static TSharedRef<IDetailCustomization> MakeInstance();

	// �ڍ׃p�l���̃��C�A�E�g���`����
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

private:
	// ���C�A�E�g�p�[�c�̉������擾����
	EVisibility GetEnumValueVisibility() const;

	// �f���Q�[�g
	void OnTaskOperatorKeyIDChanged();
	void OnOperationParamKeyIDChanged();
	void OnTaskOperatorValueComboChange(int32 Index);
	void OnOperationParamValueComboChange(int32 Index);
	TSharedRef<SWidget> OnGetTaskOperatorEnumValueContent() const;
	TSharedRef<SWidget> OnGetOperationParamEnumValueContent() const;
	FText GetTaskOperatorCurrentEnumValueDesc() const;
	FText GetOperationParamCurrentEnumValueDesc() const;

	TSharedPtr<IPropertyHandle> TaskOperatorValueValueProperty;
	TSharedPtr<IPropertyHandle> TaskOperatorValueIDProperty;
	TSharedPtr<IPropertyHandle> OperationParamValueProperty;
	TSharedPtr<IPropertyHandle> OperationParamKeyIDProperty;

	// ���C�A�E�g�̍\�z�ɕK�v�ȃA�Z�b�g�̃L���b�V��
	UEnum* CachedTaskOperatorEnumAsset;
	UEnum* CachedOperationParamEnumAsset;

	// KeyName �ɂ���đI�����ꂽ�񋓒l
	TArray<FString> TaskOperatorPropValues;
	TArray<FString> OperationParamPropValues;
};
