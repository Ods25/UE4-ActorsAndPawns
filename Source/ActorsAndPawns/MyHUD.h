// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Kismet/GameplayStatics.h"
#include "Avatar.h"
#include "MyHUD.generated.h"



//Each message we want to display will have:
    //An FString var for the msg
    //A float variable for the time to display it
    //An FColor variable for the color of the message
struct Message
{
    FString message;
    float time;
    FColor color;


    Message() //default constructor
    {
        // Set the default time. 
        time = 5.f;
        color = FColor::White;
    }

    Message(FString iMessage, float iTime, FColor iColor)
    {
        message = iMessage;
        time = iTime;
        color = iColor;
    } 

};





/**
 * 
 */
UCLASS()
class ACTORSANDPAWNS_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:
    // The font used to render the text in the HUD. 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
        UFont* hudFont;
    //An array of messages for display
    TArray<Message> messages;
    // Add this function to be able to draw to the HUD
    virtual void DrawHUD() override;
    //A func to be able to add a msg to display
    void addMessage(Message msg);
    void DrawMessages();
    void DrawHealthbar();
};
