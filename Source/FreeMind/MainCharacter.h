// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class FREEMIND_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// my desig

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LookSpeed = 1.f;

	UFUNCTION(BlueprintCallable)
		void MoveForward(float Val);

	UFUNCTION(BlueprintCallable)
		void MoveRight(float Val);
	
	UFUNCTION(BlueprintCallable)
		void LookX(float Val);

	UFUNCTION(BlueprintCallable)
		void LookY(float Val);

	UFUNCTION(BlueprintCallable)
		void DoJump();

	//Joachim sanity bar
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Sanity")
		int SanityAmount;

	void LowerSanity();
	void RaiseSanity();

	void FindPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Location")
	FVector PlayerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Location")
	FVector EndRayLocation;
};
