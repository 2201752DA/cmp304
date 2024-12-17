// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_findPatrolPoint.h"
#include "NPC_AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "NPC.h"

UBTTask_findPatrolPoint::UBTTask_findPatrolPoint(FObjectInitializer const& ObjectInitializer) : UBTTask_BlackboardBase{ ObjectInitializer }
{
	NodeName = TEXT("Find The Patrol Point");
}

EBTNodeResult::Type UBTTask_findPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{


	if (auto* const cont = Cast<ANPC_AIController>(OwnerComp.GetAIOwner()))
	{

		if (auto* const blackboardComp = OwnerComp.GetBlackboardComponent())
		{
			auto const patrolPoint = blackboardComp->GetValueAsInt(GetSelectedBlackboardKey());


			if (auto* npc = Cast<ANPC>(cont->GetPawn()))
			{
				//icl this bit was confusing but because the patrol points location is relative to the actor in the scene i am converting it to be its global pos and setting THAT to be the blackboard key value in these lines weird asf but thats what i think is right
				auto const Point = npc->getPatrolPath()->GetPatrolPoint(patrolPoint);
				auto const globalPoint = npc->getPatrolPath()->GetActorTransform().TransformPosition(Point);
				blackboardComp->SetValueAsVector(PatrolPathVectorKey.SelectedKeyName, globalPoint);

				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}


		}
	}
	return EBTNodeResult::Failed;
}
