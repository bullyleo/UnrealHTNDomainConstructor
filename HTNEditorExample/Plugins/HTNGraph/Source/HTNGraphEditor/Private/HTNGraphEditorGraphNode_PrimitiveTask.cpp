// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HTNGraphEditorGraphNode_PrimitiveTask.h"
#include "HTNGraphEditorTypes.h"
#include "HTNGraphNode.h"

UHTNGraphEditorGraphNode_PrimitiveTask::UHTNGraphEditorGraphNode_PrimitiveTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	DefaultNodeName = "Primitive Task Node";
}

void UHTNGraphEditorGraphNode_PrimitiveTask::AllocateDefaultPins()
{
	// Primitive Task�͎q�m�[�h�������Ȃ��̂ŃC���v�b�g�s���̂�
	CreatePin(EGPD_Input, UHTNGraphEditorTypes::PinCategory_MultipleNodes, TEXT("In"));
}
