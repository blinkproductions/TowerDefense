// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Enemy.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../Components/HealthComponent.h"
#include "../Widgets/ArmorAndHealthBarWidget.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ATD_Enemy::ATD_Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetupAttachment(SpringArm);
	
	ArmorAndHealthWidget = CreateDefaultSubobject<UWidgetComponent>("WidgetComponent");
	ArmorAndHealthWidget->SetupAttachment(GetRootComponent());

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ATD_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATD_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateHealth();
}

// Called to bind functionality to input
void ATD_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

