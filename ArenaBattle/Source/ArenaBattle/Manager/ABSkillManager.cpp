// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/ABSkillManager.h"
#include "Item/ABBoom.h"

UABSkillManager::UABSkillManager()
{
	static ConstructorHelpers::FClassFinder<AABBoom> BombClassRef(TEXT("/Script/Engine.Blueprint'/Game/ArenaBattle/Blueprint/Item/BP_Boom.BP_Boom_C'"));
	if (BombClassRef.Class)
	{
		BombClass = BombClassRef.Class;
	}
}

void UABSkillManager::CreateBomb(AActor* OwnerActor, FTransform SpawnTransform)
{


	AABBoom* ABBoom = GetWorld()->SpawnActorDeferred<AABBoom>(BombClass, SpawnTransform);
	if (ABBoom)
	{
		ABBoom->SetProperty(OwnerActor, 5);
		ABBoom->FinishSpawning(SpawnTransform);
	}


}
