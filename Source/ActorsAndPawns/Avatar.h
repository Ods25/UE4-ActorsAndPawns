// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"

UCLASS()//The UCLASS() macro basically makes your C++ code class available in the UE4 editor.
class ACTORSANDPAWNS_API AAvatar : public ACharacter
{
	GENERATED_BODY() //The GENERATED_BODY() macro copiesand pastes code that UE4 needs to make your class function properly as a UE4 class.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; //This is an override of a virtual function

public:	
	int32 Hp;
	int32 MaxHp;
	AAvatar();
	// Called every frame

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; //This is an override of a virtual function in the APawn base class.
	
	// New! These 2 new member function declarations 
	// they will be used to move our player around! 

	void MoveForward(float amount);
	void MoveRight(float amount);
	void Yaw(float amount);
	void Pitch(float amount);

};
