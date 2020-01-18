// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIGraphTypes.h"
#include "Modules/ModuleInterface.h"
#include "Toolkits/IToolkitHost.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "AssetTypeActions_Base.h"

class FWorkflowCentricApplication;

DECLARE_LOG_CATEGORY_EXTERN(LogHTNGraphEditor, Log, All);

//--------------------------------------------------------------
// �G�f�B�^���W���[���N���X
// ���W���[���ǂݍ��ݎ��A�V���b�g�_�E�����̐U�镑���A�O���t�G�f�B�^�C���X�^���X�̍쐬�������������s��
//--------------------------------------------------------------
class FHTNGraphEditorModule : public IModuleInterface, public IHasMenuExtensibility, public IHasToolBarExtensibility
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** Creates an instance of HTN Graph editor.  Only virtual so that it can be called across the DLL boundary. */
	virtual TSharedRef<FWorkflowCentricApplication> CreateHTNGraphEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, class UObject* Object);

	/** Gets the extensibility managers for outside entities to extend static mesh editor's menus and toolbars */
	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() override { return MenuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() override { return ToolBarExtensibilityManager; }

	TSharedPtr<struct FGraphNodeClassHelper> GetClassCache() { return ClassCache; }

	/** HTHGraphEditor app identifier string */
	static const FName HTNGraphEditorAppIdentifier;

private:
	TSharedPtr<FExtensibilityManager> MenuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;

	/** Asset type actions */
	TArray<TSharedPtr<class FAssetTypeActions_Base>> ItemDataAssetTypeActions;

	TSharedPtr<struct FGraphNodeClassHelper> ClassCache;

};
