// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_incrementPatrolIndex.h"
#include "NPC_AIController.h"
#include "NPC.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

UBTTask_incrementPatrolIndex::UBTTask_incrementPatrolIndex(FObjectInitializer const& ObjectInitializer) : 
	UBTTask_BlackboardBase{ ObjectInitializer }
{
	NodeName = TEXT("Increment Patrol Index yaaaabo");//im tired boss im tired of these files n functions maine
}

EBTNodeResult::Type UBTTask_incrementPatrolIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//only time im explaining this chain bc its the same logic over n over, getting ai controller, then trying to get the npc, then im getting the blackboard component then im doing stuff w all that
	if (auto* const cont = Cast<ANPC_AIController>(OwnerComp.GetAIOwner()))
	{

		if (auto* const npc = Cast<ANPC>(cont->GetPawn()))
		{
			if (auto* const blackboardComp = OwnerComp.GetBlackboardComponent())
			{
				auto const nPoints = npc->getPatrolPath()->Num();
				auto const min = 0;
				auto const max = nPoints - 1;
				auto   i = blackboardComp->GetValueAsInt(GetSelectedBlackboardKey());

				// go reverse if we want
				if (directionalBi)
				{
					if (i >= max && Dir == EDirectionType::forward)
					{
						Dir = EDirectionType::reverse;
					}
					else if (i == max && Dir == EDirectionType::reverse)
					{
						Dir = EDirectionType::forward;
					}
				}
				// if forward increment blackboard key, else deincrement, modular remainer to stop it going out of range i believe (i was told this was a good idea to do)
				blackboardComp->SetValueAsInt(GetSelectedBlackboardKey(), (Dir == EDirectionType::forward ? ++i : --i) % nPoints);

				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;


			}
		}
	}
	return EBTNodeResult::Failed;
}
