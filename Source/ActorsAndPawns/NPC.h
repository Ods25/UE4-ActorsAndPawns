// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"

UCLASS()
class ACTORSANDPAWNS_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();
	// This is the NPC's message that he has to tell us. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage) //This makes NpcMessage editable in the blueprints
		FString NpcMessage;
	// When you create a blueprint from this class, you want to be  able to edit that message in blueprints, that's why we have the EditAnywhere and BlueprintReadWrite  properties. 
	
	// This is the NPC's name 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString name;


	// The sphere that the player can collide with 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		USphereComponent* ProxSphere;  //And now we've declared an extra bounding sphere volume named ProxSphere, which detects when the player is near the NPC

	//Proximity Sphere function
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void Prox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//We shouldn't need Prox_Implementation, however we're getting errors saying Prox is not found, the following declaration is the fix.
	virtual int Prox_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Sets default values for this character's properties
	ANPC(const FObjectInitializer& ObjectInitializer);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};


//Just gonna add this down here, whenever we create a blueprint of the NPC object, we are effectively creaating a new NPC in-game. 