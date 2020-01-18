// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "HTNGraphEditorGraphNode.h"
#include "HTNGraphEditorGraphNode_PrimitiveTask.generated.h"

//--------------------------------------------------------------
// �O���t�ɕ\�������uPrimitive�m�[�h�v��\���N���X
//--------------------------------------------------------------
UCLASS()
class UHTNGraphEditorGraphNode_PrimitiveTask : public UHTNGraphEditorGraphNode
{
	GENERATED_BODY()

public:
	UHTNGraphEditorGraphNode_PrimitiveTask(const FObjectInitializer& ObjectInitializer);

	virtual void AllocateDefaultPins() override;
};
