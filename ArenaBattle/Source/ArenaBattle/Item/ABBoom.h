// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABBoom.generated.h"

UCLASS()
class ARENABATTLE_API AABBoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABBoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

// GetSet
public:
	TWeakObjectPtr<AActor> GetOwnerMadeMe() { return OwnerMadeMe; }
	
	void SetProperty(TWeakObjectPtr<AActor> _OwnerMadeMe, int _BoomLineDis);

protected:
	UFUNCTION(NetMulticast, reliable)
	void NetMulticastRPC_Boom();
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void BoomLine();
	void Boom(FVector BoomLocation);
	void BoomEffect(FVector BoomLocation);

	// Components
protected:
	UPROPERTY(VisibleAnywhere, Category = Boom)
	TObjectPtr<class USphereComponent> Collision;

	UPROPERTY(VisibleAnywhere, Category = Boom)
	TObjectPtr<class UStaticMeshComponent> Mesh;

	// Propertys
protected:
	TWeakObjectPtr<AActor> OwnerMadeMe;
	
	UPROPERTY(EditAnywhere, Category = Boom)
	float BoomTime;
	UPROPERTY(EditAnywhere, Category = Boom)
	float AttackRadius;
	UPROPERTY(EditAnywhere, Category = Boom)
	TObjectPtr<class UParticleSystem> Particle;

	FTimerHandle LineBoomTimerHandle;
	
	UPROPERTY(Replicated)
	int BoomLineDis;
	
	int BoomLineCnt;
	FVector FirstLocation;
	
};
