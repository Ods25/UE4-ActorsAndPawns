// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxHp = 100;
	Hp = 100;
}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent); //Here we are checking the PlayerInputComponent
	PlayerInputComponent->BindAxis("Forward", this, &AAvatar::MoveForward); //Bind the input named "Forward" to MoveForward()
	PlayerInputComponent->BindAxis("Strafe", this, &AAvatar::MoveRight);//Bind the input named "Strafe" to MoveRight()
	PlayerInputComponent->BindAxis("Yaw", this, &AAvatar::Yaw); //same
	PlayerInputComponent->BindAxis("Pitch", this, &AAvatar::Pitch); //same
}

void AAvatar::MoveForward(float amount)
{
	// Don't enter the body of this function if Controller is 
	// not set up yet, or if the amount to move is equal to 0 
	if (Controller && amount) //Controller object defined in APawn base class
	{
		FVector fwd = GetActorForwardVector();
		// we call AddMovementInput to actually move the 
		// player by `amount` in the `fwd` direction 
		AddMovementInput(fwd, amount); //AddMovementInput function defiend in APawn base class.
	} //Avatar class < ACharacter < APawn. 
}

void AAvatar::MoveRight(float amount)
{
	if (Controller && amount) //Controller object defined in APawn base class
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);//AddMovementInput function defiend in APawn base class.
	}
}

void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(200.f * amount * GetWorld()->GetDeltaSeconds()); //High level function, does what it says on the tin.
} //Argument for amount is multiplied by 200, representing the mouse's sensitivity. 
//Although we should really avoid hardcoding this and instead adding a float member to the AAvatar class
// GetWorld()->GetDeltaSeconds() gives us the amount of time that passed between the last frame and this frame.
//It isn't a lot, around 16 ms if the game is 60fps

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}


//Now we have player input and control. 

//When we want to add a new functionality, all we have to do is:
/*
1.Bind your key or mouse actions by going to Settings | Project Settings | Input.
2.Add a member function to run when that key is pressed.
3.Add a line to SetupPlayerInputComponent, connecting the name of the bound input to the member function we want to run when that key is pushed.
*/