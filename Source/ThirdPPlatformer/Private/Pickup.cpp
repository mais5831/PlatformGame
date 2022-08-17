// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "../MyCharacter.h"
#include "Kismet/GameplayStatics.h"

APickup::APickup()
{
	// Set up the mesh for the pickup, and set the item name, help text and item value
	InteractableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	InteractableMesh->SetSimulatePhysics(true);

	ItemName = FString("Enter an item name here...");
	InteractableHelpText = FString("Please E to pick item up.");
	Value = 0;
}

void APickup::BeginPlay()
{
	InteractableHelpText = FString::Printf(TEXT("%s: Pick E to pick up."), *ItemName);
}

void APickup::Interact_Implementation()
{
	AMyCharacter* Character = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	// Put code here that places the item into the character's inventory.

	OnPickedUp();
}

void APickup::Use_Implementation()
{
	GLog->Log("Use() from base pickup class : YOU SHOULD NOT BE SEEING THIS");
}

void APickup::OnPickedUp()
{
	InteractableMesh->SetVisibility(false);
	InteractableMesh->SetSimulatePhysics(false);
	InteractableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}