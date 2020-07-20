// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HTNGraphNode.h"
#include "HTNDomain.h"
#include "HTNGraphNode_PrimitiveTask.generated.h"


//--------------------------------------------------------------
// World State�֓K�p�������
//--------------------------------------------------------------
USTRUCT()
struct FHTNEffectParam
{
	GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, Category = "HTN")
        FUserDefinitionWorldState UserDefinitionWorldStateKey;

	UPROPERTY(EditAnywhere, Category = "AI|HTN")
		EHTNWorldStateOperation Operation;

	UPROPERTY(EditAnywhere, Category = "AI|HTN")
		int32 RhsValue;
};

//--------------------------------------------------------------
// Primitive Task�m�[�h
// ���̃m�[�h�͖��[�Ȃ̂Ŏq�������Ƃ͏o���Ȃ�
//--------------------------------------------------------------

UCLASS()
class HTNGRAPHRUNTIME_API UHTNGraphNode_PrimitiveTask : public UHTNGraphNode
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Category = "HTN", meta = (EditCondition = "WorldStateEnumAsset"))
        int32 TaskOperatorValue;
    UPROPERTY(EditAnywhere, Category = "HTN", meta = (EditCondition = "OperatorEnumAsset"))
        int32 OperationParamValue;
    UPROPERTY(EditAnywhere, Category = "HTN")
        TArray<FHTNEffectParam> Effects;

public:
    UHTNGraphNode_PrimitiveTask(const FObjectInitializer& ObjectInitializer);

    virtual void ConstructTaskBuilder(struct FHTNBuilder_Domain& DomainBuilder) override;

#if WITH_EDITOR
    /** Get the name of the icon used to display this node in the editor */
    virtual FName GetNodeIconName() const override;
#endif
};
