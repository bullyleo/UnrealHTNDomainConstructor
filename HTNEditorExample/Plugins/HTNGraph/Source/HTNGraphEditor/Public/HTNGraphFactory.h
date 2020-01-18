// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "HTNGraphFactory.generated.h"

//--------------------------------------------------------------
// HTNGraphEditor�A�Z�b�g�𐶐�����t�@�N�g��
// Content Browser��Add New�������Ƃ��ɌĂ΂��B
//--------------------------------------------------------------
UCLASS()
class HTNGRAPHEDITOR_API UHTNGraphFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UHTNGraphFactory(const FObjectInitializer& ObjectInitializer);

private:
	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
	// End of UFactory interface

};
