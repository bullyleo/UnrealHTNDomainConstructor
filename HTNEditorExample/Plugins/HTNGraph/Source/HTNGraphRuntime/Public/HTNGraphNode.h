// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HTNGraphNode.generated.h"


//--------------------------------------------------------------
// 
//--------------------------------------------------------------
USTRUCT(BlueprintType)
struct FUserDefinitionWorldState
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, Category = "HTN")
        int32 WorldStateKeyValue;

    bool operator==(const FUserDefinitionWorldState& Rhs) const 
    {
        return WorldStateKeyValue == Rhs.WorldStateKeyValue;
    }

    // TMap�̃L�[�Ƃ��Ďg�p����ꍇ�́uGetTypeHash�֐��v�Ɓu�������Z�q�v��K����������K�v������
    FORCEINLINE uint32 GetTypeHash() const
    {
        return WorldStateKeyValue;
    }
};

// �����TMap�̃L�[�Ƃ��Ďg�p����ꍇ�ɂ͕K�{
FORCEINLINE uint32 GetTypeHash(const FUserDefinitionWorldState Item)
{
    return Item.GetTypeHash();
}



//--------------------------------------------------------------
// HTN�ɓo�ꂷ��m�[�h���̂��̂̐U�镑����������N���X
//--------------------------------------------------------------
UCLASS()
class HTNGRAPHRUNTIME_API UHTNGraphNode : public UObject
{
	GENERATED_BODY()
public:
    // �������G�f�B�^�ŕҏW����ƃm�[�h�̖��O���ύX�����B
    UPROPERTY(EditAnywhere, Category = "HTN")
        FString NodeName;

private:
    /** source asset */
    UPROPERTY()
        class UHTNGraph* TreeAsset;

    /** parent node */
    UPROPERTY()
        class UHTNGraphNode_Composite* ParentNode;

    /** depth first index (execution order) */
    uint16 ExecutionIndex;

    /** depth in tree */
    uint8 TreeDepth;

public:
    UHTNGraphNode(const FObjectInitializer& ObjectInitializer);

    /** fill in data about tree structure */
    void InitializeNode(class UHTNGraphNode_Composite* InParentNode, uint16 InExecutionIndex, uint8 InTreeDepth);

    /** initialize any asset related data */
    virtual void InitializeFromAsset(class UHTNGraph& Asset);

    // ���̃m�[�h�̐U�镑���ɕK�v�ȃf�[�^����������
    // ��FPrimitive Task��Operator�̃Z�b�g��Effect�̐ݒ�
    virtual void ConstructTaskBuilder(struct FHTNBuilder_Domain& DomainBuilder) {};

    /** @return tree asset */
    FORCEINLINE UHTNGraph* GetTreeAsset() const { return TreeAsset; }

    /** @return execution index */
    FORCEINLINE uint16 GetExecutionIndex() const { return ExecutionIndex; }

    /** @return string containing description of this node with all setup values */
    virtual FString GetStaticDescription() const;

#if WITH_EDITOR
    /** Get the name of the icon used to display this node in the editor */
    virtual FName GetNodeIconName() const { return NAME_None; }
#endif

	FString GetNodeName() const { return NodeName.Len() ? NodeName : GetClass()->GetName(); }
};


inline FString UHTNGraphNode::GetStaticDescription() const
{
    // short type name
    FString TypeDesc = GetClass()->GetName();
    const int32 ShortNameIdx = TypeDesc.Find(TEXT("_"));
    if (ShortNameIdx != INDEX_NONE)
    {
        TypeDesc = TypeDesc.Mid(ShortNameIdx + 1);
    }

    return TypeDesc;

}

