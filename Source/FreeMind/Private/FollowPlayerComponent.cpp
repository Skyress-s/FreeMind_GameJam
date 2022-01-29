// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "FollowPlayerComponent.h"

// Sets default values for this component's properties
UFollowPlayerComponent::UFollowPlayerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFollowPlayerComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerActor = UGameplayStatics::GetPlayerPawn(this, 0);
	// ...
	
}


// Called every frame
void UFollowPlayerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PlayerActor)
	{
		GetOwner()->SetActorLocation(PlayerActor->GetActorLocation() + Offset);
	}

	// ...
}

