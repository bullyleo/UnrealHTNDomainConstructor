// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "AIGraph/Classes/AIGraph.h"
#include "HTNGraphEditorGraph.generated.h"


//--------------------------------------------------------------
// HTNGraphEditor�ł̓�����`����.
// ��F�s���̍Ĕz�u�����A�m�[�h���s���̌���
//--------------------------------------------------------------
UCLASS()
class UHTNGraphEditorGraph : public UAIGraph
{
	GENERATED_BODY()

public:
	UHTNGraphEditorGraph(const FObjectInitializer& ObjectInitializer);

	enum EUpdateFlags
	{
		RebuildGraph = 0,
		ClearDebuggerFlags = 1,
		KeepRebuildCounter = 2,
	};

	/** increased with every graph rebuild, used to refresh data from subtrees */
	UPROPERTY()
	int32 ModCounter;

	UPROPERTY()
	bool bIsUsingModCounter;

	virtual void OnCreated() override;
	virtual void OnLoaded() override;
	void OnSave();

	virtual void UpdateVersion() override;
	virtual void MarkVersion() override;
	virtual void UpdateAsset(int32 UpdateFlags = 0) override;

	void InitializeGraphNodeInstance(const class UHTNGraphEditorGraphNode_Root* RootNode);
	void CreateHTNGraphFromGraph(class UHTNGraphEditorGraphNode* RootEdNode);
	void SpawnMissingNodes();
	void UpdatePinConnectionTypes();
	void ReplaceNodeConnections(UEdGraphNode* OldNode, UEdGraphNode* NewNode);
	void RebuildExecutionOrder();
	void RebuildChildOrder(UEdGraphNode* ParentNode);

	void AutoArrange();

protected:

#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif
};
