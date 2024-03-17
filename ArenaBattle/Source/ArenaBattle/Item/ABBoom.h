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

public:
	void Boom();

	// Components
protected:
	UPROPERTY(VisibleAnywhere, Category = Boom)
	TObjectPtr<class USphereComponent> Collision;

	UPROPERTY(VisibleAnywhere, Category = Boom)
	TObjectPtr<class UStaticMeshComponent> Mesh;

	// Propertys
protected:
	UPROPERTY(VisibleAnywhere, Category = Boom)
	float BoomTime;

};
