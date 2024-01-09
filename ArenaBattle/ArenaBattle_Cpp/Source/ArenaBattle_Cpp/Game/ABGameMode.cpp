// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"


AABGameMode::AABGameMode()
{
	//// Ŭ���� ������ _C ���̱�
	//static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(
	//	TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));
	//if (ThirdPersonClassRef.Class)
	//{
	//	DefaultPawnClass = ThirdPersonClassRef.Class;
	//}

	// Ŭ���� ������ _C ���̱�
	static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(
		TEXT("/Game/ArenaBattle/Blueprint/BP_AB_CharacterPlayer.BP_AB_CharacterPlayer_C"));
	if (ThirdPersonClassRef.Class)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}

	// ����Ʈ ��Ʈ�ѷ� ����
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerRef(
		TEXT("/Script/ArenaBattle_Cpp.ABPlayerController"));
	if (PlayerControllerRef.Class)
	{
		PlayerControllerClass = PlayerControllerRef.Class;
	}

}
