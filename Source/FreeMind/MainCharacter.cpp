// Fill out your copyright notice in the Description page of Project Settings.




#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlayerLocation = FVector::ZeroVector;
	EndRayLocation = FVector::ZeroVector;

	CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CharacterMesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	StartPosition = GetActorLocation();

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FindPlatform();
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
	//PlayerInputComponent->BindAction("Switch", IE_Pressed, this, &AMainCharacter::SwitchDimetion);
	PlayerInputComponent->BindAction("KillSelf", IE_Pressed, this, &AMainCharacter::Damage);

}

void AMainCharacter::MoveForward(float Val)
{
	if (bInsanityDimenson)
	{

	}
	else
	{
		AddMovementInput(GetActorForwardVector(), Val * Speed);
	}


}

void AMainCharacter::MoveRight(float Val)
{
	

	if (bInsanityDimenson)
	{
		AddMovementInput(-FVector::XAxisVector, Val * Speed);
	}
	else
	{
		AddMovementInput(GetActorRightVector(), Val * Speed);

	}
	
}

void AMainCharacter::LookX(float Val) {
	AddControllerYawInput(Val * LookSpeed);
}

void AMainCharacter::LookY(float Val) {
	AddControllerPitchInput(-Val * LookSpeed);
}

void AMainCharacter::DoJump()
{
	Jump();

}

//joachim sanity
void AMainCharacter::LowerSanity() {
	if ((SanityAmount - 3) >= 0) {
		SanityAmount -= 3;
	}
	else {
		SanityAmount = 0;
	}

}

void AMainCharacter::RaiseSanity() {
	if ((SanityAmount + 3) <= 100) {
		SanityAmount += 3;
	}
	else {
		SanityAmount = 100;
	}
}

void AMainCharacter::FindPlatform() {
	//PlayerLocation = GetActorLocation();
	//EndRayLocation = PlayerLocation;
	//EndRayLocation.Z -= 150;

	//FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	//FHitResult hit{};
	//
	//bool bHit = GetWorld()->LineTraceSingleByChannel(
	//	hit,
	//	PlayerLocation,
	//	EndRayLocation,
	//	FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldDynamic),
	//	TraceParams
	//);
	//
	//if (bHit) {
	//	FString temp = hit.GetActor()->GetName();
	//	UE_LOG(LogTemp, Warning, TEXT("%s"), *temp);
	//}
	//
}

void AMainCharacter::Damage()
{
	if ((Health - 1) > 0) {
		Health -= 1;
		UE_LOG(LogTemp, Warning, TEXT("Health subtracted"));

	}
	else
	{
		GameOver();
		UE_LOG(LogTemp, Warning, TEXT("Respawned"));
		Health = 5;

	}
}

void AMainCharacter::GameOver()
{
	SetActorLocation(StartPosition);
}