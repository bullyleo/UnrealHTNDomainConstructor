// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraphSchema.h"
#include "AIGraphTypes.h"
#include "AIGraphSchema.h"
#include "EdGraphSchema_HTNGraph.generated.h"

class FSlateRect;
class UEdGraph;

// Auto Arrange�i��������j�A�N�V����
USTRUCT()
struct FHTNGraphSchemaAction_AutoArrange : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY();

	FHTNGraphSchemaAction_AutoArrange()
		: FEdGraphSchemaAction() {}

	FHTNGraphSchemaAction_AutoArrange(FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping)
		: FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), MoveTemp(InToolTip), InGrouping)
	{}

	//~ Begin FEdGraphSchemaAction Interface
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
	//~ End FEdGraphSchemaAction Interface
};


/**
* �G�f�B�^��ŉE�N���b�N�����Ƃ��ɕ\�������R���e�L�X�g���j���[�̐U�镑����m�[�h�Ԃ̐ڑ����`����
*/
UCLASS(MinimalAPI)
class UEdGraphSchema_HTNGraph : public UAIGraphSchema
{
	GENERATED_BODY()

public:
	UEdGraphSchema_HTNGraph(const FObjectInitializer& ObjectInitializer);

	//~ Begin EdGraphSchema Interface

	// �V�����O���t���������ꂽ���̊���m�[�h��ݒ肷��
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
	// �O���t���E�N���b�N��������s�����h���b�O�������[�X�����Ƃ��Ɏ��s�ł��邷�ׂẴA�N�V�������擾����
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	// �s���Ԃ̐ڑ��ۂ�ݒ肷��
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	// FConnectionDrawingPolicy �̃C���X�^���X���쐬����
	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;


	virtual bool IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const override
	{
		return CurrentCacheRefreshID != InVisualizationCacheID;
	}
	virtual int32 GetCurrentVisualizationCacheID() const override
	{
		return CurrentCacheRefreshID;
	}
	virtual void ForceVisualizationCacheClear() const override
	{
		++CurrentCacheRefreshID;
	}
	//~ End EdGraphSchema Interface

private:
	// �R���e�L�X�g���j���[�ł̃A�N�V�����f�[�^���\�z����
	void ConstructGraphContextActionData(UClass* GatherClass, UClass* TargetClass, UClass* GenerateNodeClass, FString CategoryName, FGraphNodeClassHelper* ClassCache, FGraphContextMenuBuilder& ContextMenuBuilder) const;

private:
	// ID for checking dirty status of node titles against, increases whenever 
	static int32 CurrentCacheRefreshID;
};
