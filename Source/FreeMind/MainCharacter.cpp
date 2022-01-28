// Fill out your copyright notice in the Description page of Project Settings.




#include "Components/StaticMeshComponent.h"

#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CharacterMesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("ForwardAxis", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("RightAxis", this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookX", this, &AMainCharacter::LookX);
	PlayerInputComponent->BindAxis("LookY", this, &AMainCharacter::LookY);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::DoJump);
}

void AMainCharacter::MoveForward(float Val)
{
	AddMovementInput(GetActorForwardVector(), Val * Speed);

}

void AMainCharacter::MoveRight(float Val)
{
	
		AddMovementInput(GetActorRightVector(), Val * Speed);

	
}

void AMainCharacter::LookX(float Val)
{
	AddControllerYawInput(Val * LookSpeed);
}

void AMainCharacter::LookY(float Val)
{
	AddControllerPitchInput(-Val * LookSpeed);
}

void AMainCharacter::DoJump()
{
	Jump();

}



