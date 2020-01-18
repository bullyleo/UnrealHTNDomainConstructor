// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/IToolkitHost.h"
#include "AssetTypeActions_Base.h"


//--------------------------------------------------------------
// HTNGraphEditor�A�Z�b�g�ɂ��ẴA�N�V�������`����
//--------------------------------------------------------------
class FAssetTypeActions_HTNGraphEditor : public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_HTNGraphEditor", "HTN Graph"); }
	// �A�C�R���̔w�i�F
	virtual FColor GetTypeColor() const override { return FColor(0,255,255); }
	// ����AssetTypeAction���T�|�[�g����A�Z�b�g�N���X���w�肷��
	virtual UClass* GetSupportedClass() const override;
	// �A�Z�b�g���J�������ɋN������G�f�B�^���쐬����
	virtual void OpenAssetEditor( const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>() ) override;
	// AddNew�ŕ\�������A�Z�b�g�̃J�e�S�����w��
	virtual uint32 GetCategories() override;
};
