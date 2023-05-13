// Fill out your copyright notice in the Description page of Project Settings.


#include "AstronautCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AAstronautCharacter::AAstronautCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AAstronautCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAstronautCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult* Hit = new FHitResult();
	FVector Start = GetActorLocation();
	FVector End = Start + FVector(20, 0, 0);
	GetWorld()->LineTraceSingleByChannel(*Hit, Start, End, ECC_Visibility);
	AActor* hitActor = Hit->GetActor();
	if (hitActor) {
		UE_LOG(LogTemp, Warning, TEXT(""), Hit);

	}
}

// Called to bind functionality to input
void AAstronautCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AAstronautCharacter::Forward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AAstronautCharacter::Right);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AAstronautCharacter::Jump);
	
}
//to do a forward movement
	void AAstronautCharacter::Forward(float AxisValue) {
	AddMovementInput(GetActorForwardVector()*AxisValue);
}
	//to do a right left movment
void AAstronautCharacter::Right(float AxisValue) {
	AddMovementInput(GetActorRightVector() * AxisValue);
}

//to do a jumping
void AAstronautCharacter::Jump() {
	
	if (Jump_Montage) {
		PlayAnimMontage(Jump_Montage); //playing he animation montage
		ACharacter::Jump();
	}
}


