// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_findPatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class CMP302_REALPROJECT_API UBTTask_findPatrolPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	explicit UBTTask_findPatrolPoint(FObjectInitializer const& ObjectInitalizer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
private:
	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FBlackboardKeySelector PatrolPathVectorKey;
};
