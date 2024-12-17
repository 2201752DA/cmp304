// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindRandom.h"

#include "NavigationSystem.h"
#include "NPC_AIController.h"

UBTTask_FindRandom::UBTTask_FindRandom(FObjectInitializer const& ObjectInitializer) : UBTTask_BlackboardBase{ ObjectInitializer }
{
	NodeName = TEXT("Find Random Location In NavMesh");
}

EBTNodeResult::Type UBTTask_FindRandom::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{


	if (auto* const cont = Cast<ANPC_AIController>(OwnerComp.GetAIOwner())) {

		if (auto* const variableName_m = cont->GetPawn()) {

			auto const origin = variableName_m->GetActorLocation();

			if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation loc;
				if (NavSys->GetRandomPointInNavigableRadius(origin, SearchRadius, loc))

				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), loc.Location);


				}

				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}

