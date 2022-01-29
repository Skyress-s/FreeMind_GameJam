// Fill out your copyright notice in the Description page of Project Settings.


#include "DimensionBlendComponent.h"

// Sets default values for this component's properties
UDimensionBlendComponent::UDimensionBlendComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	ThreeDSpace = FVector::ZeroVector;
	TwoDSpace = FVector::ZeroVector;

	


	// FVector is stores as X, Y, Z
	// ...
}


// Called when the game starts
void UDimensionBlendComponent::BeginPlay()
{
	Super::BeginPlay();
	SwapDimensions();
	// ...
	
	
	
}


// Called every frame
void UDimensionBlendComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UDimensionBlendComponent::SwapDimensions() {
	ThreeDSpace = GetOwner()->GetActorLocation();

	TwoDSpace = ThreeDSpace;
	TwoDSpace.Y = 0.f;

	OldY = ThreeDSpace.Y;
}

