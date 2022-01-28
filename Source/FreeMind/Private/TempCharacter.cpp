// Fill out your copyright notice in the Description page of Project Settings.


#include "TempCharacter.h"

// Sets default values
ATempCharacter::ATempCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SanityAmount = 100;

}

// Called when the game starts or when spawned
void ATempCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATempCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATempCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Lower", IE_Pressed, this, &ATempCharacter::LowerSanity);
	InputComponent->BindAction("Raise", IE_Pressed, this, &ATempCharacter::RaiseSanity);
}

void ATempCharacter::LowerSanity() {
	if ((SanityAmount - 3) >= 0) {
		SanityAmount -= 3;
	}
	else {
		SanityAmount = 0;
	}

}

void ATempCharacter::RaiseSanity() {
	if ((SanityAmount + 3) <= 100) {
		SanityAmount += 3;
	}
	else {
		SanityAmount = 100;
	}
}

