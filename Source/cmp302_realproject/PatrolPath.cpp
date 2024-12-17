// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolPath.h"

// Sets default values
APatrolPath::APatrolPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

FVector APatrolPath::GetPatrolPoint(int const i) const
{
	return PatrolPoints[i];
}

int APatrolPath::Num() const
{
	return PatrolPoints.Num();
}


