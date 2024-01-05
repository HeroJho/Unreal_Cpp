// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/ABAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UABAnimInstance::UABAnimInstance()
{
	MoveingThreshould = 3.f;
	JumpingThreshould = 100.f;


}

// PlayerPawn�� �����Ǹ鼭 ȣ��Ǵ� �ʱ�ȭ �Լ�
void UABAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Owner = Cast<ACharacter>(GetOwningActor());
	if (Owner)
	{
		Movement = Owner->GetCharacterMovement();
	}

}

// Anim Tick �Լ�
void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);


	if (Movement)
	{
		Velocity = Movement->Velocity;
		GroundSpeed = Velocity.Size2D(); // �ӵ� ũ�� ��
		bIsIdle = GroundSpeed < MoveingThreshould; // �Ӱ谪���� ���ٸ�
		bIsFalling = Movement->IsFalling();
		bIsJumping = bIsFalling & (Velocity.Z > JumpingThreshould);
		// 0000 0001       0000 0001
	}

}
