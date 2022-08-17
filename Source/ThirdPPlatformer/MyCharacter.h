// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Public/Interactable.h"
#include "Public/Pickup.h"
#include "MyCharacter.generated.h"

UCLASS()
class THIRDPPLATFORMER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float AxisVal);
	void MoveRight(float AxisVal);

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	float Reach;
	/* Toggles the inventory*/
	void ToggleInventory();

	/* Interacts with the current Interactable, provided there is one.*/
	void Interact();

	/* Checks for interactable items directly in front of the player using a line trace, called on a per tick basis.*/
	void CheckForInteractables();
};
