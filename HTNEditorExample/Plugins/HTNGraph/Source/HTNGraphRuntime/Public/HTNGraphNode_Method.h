// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HTNGraphNode.h"
#include "HTNGraphNode_PrimitiveTask.h"
#include "HTNGraphNode_Composite.h"
#include "HTNPlanner.h" // HTN Planner plugin
#include "HTNGraphNode_Method.generated.h"

//--------------------------------------------------------------
// Method�̎q�m�[�h��W�J���邽�߂̎��O�����f�[�^
//--------------------------------------------------------------
USTRUCT()
struct FHTNMethodCondition
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, Category = "HTN")
        FUserDefinitionWorldState MethodWorldState;

    UPROPERTY(EditAnywhere, Category = "AI|HTN")
        EHTNWorldStateCheck Check;

    // �ڍ׃p�l���̍��ڕҏW�\�t���O
    UPROPERTY(/*EditAnywhere, Category = "AI|HTN"*/)
        bool bCanEditValue;

    // Editable only if bCanEditValue is True.
    UPROPERTY(EditAnywhere, meta = (EditCondition = "bCanEditValue"), Category = "AI|HTN" )
        int32 Value;
};


//--------------------------------------------------------------
// �������̃m�[�h���܂Ƃ߂�.
// MethodConditions�̌��ʂɂ���Ďq�m�[�h��W�J���邩���肷��.
// �uComposite�m�[�h�v�uPrimitive Task�m�[�h�v�݂̂��q�ɂ��邱�Ƃ��o���� 
//--------------------------------------------------------------
UCLASS()
class HTNGRAPHRUNTIME_API UHTNGraphNode_Method : public UHTNGraphNode_Composite
{
	GENERATED_BODY()
public:

    UPROPERTY(EditAnywhere, Category = "HTN")
        TArray<FHTNMethodCondition> MethodConditions;

public:
    UHTNGraphNode_Method(const FObjectInitializer& ObjectInitializer);

    virtual void ConstructMethodBuilder(struct FHTNBuilder_Domain& DomainBuilder, struct FHTNBuilder_CompositeTask& CompositeTaskBuilder) override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

};
