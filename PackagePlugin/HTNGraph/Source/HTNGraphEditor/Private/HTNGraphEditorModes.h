// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Docking/TabManager.h"
#include "HTNGraphEditor.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"
#include "WorkflowOrientedApp/ApplicationMode.h"

//--------------------------------------------------------------
// HTNGraphEditor�̕ҏW���[�h�̓�����`
//--------------------------------------------------------------
class FHTNGraphEditorApplicationMode : public FApplicationMode
{
public:
	FHTNGraphEditorApplicationMode(TSharedPtr<class FHTNGraphEditor> InHTNGraphEditor);

	virtual void RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;

protected:
	TWeakPtr<class FHTNGraphEditor> HTNGraphEditor;

	// HTNGraphEditor�̕ҏW���[�h�Ő����\�ȃ^�u�̃Z�b�g
	FWorkflowAllowedTabSet HTNGraphEditorTabFactories;
};
