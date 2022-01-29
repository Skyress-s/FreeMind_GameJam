// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DimensionBlendComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FREEMIND_API UDimensionBlendComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDimensionBlendComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors | 3DLocation")
	FVector ThreeDSpace;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors | 2DLocation")
	FVector TwoDSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors | OldYLocation")
	float OldY;

};
