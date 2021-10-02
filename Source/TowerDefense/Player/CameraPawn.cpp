// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	RootComponent = RootScene;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArm->TargetArmLength = 1000.f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 20.f;
	SpringArm->SetRelativeRotation(FRotator(-50.f, 0.f,0.f));
	SpringArm->SetupAttachment(RootScene);

	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetupAttachment(SpringArm);
	
	Margin = 40.f;
	CameraPanSpeed = 10.f;
	CurrentArmLength = 0.f;
	ZoomRate = 15.f;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<APlayerController>(GetController());
	
	PC->bShowMouseCursor = true;

	CurrentArmLength = SpringArm->TargetArmLength;
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PC->GetViewportSize(ScreenSizeX, ScreenSizeY); // can be optimized by having a set dimension for screen

	FMath::Clamp(GetActorLocation().X, 0.f, 800.f);
	FMath::Clamp(GetActorLocation().Y, 0.f, 800.f);
	AddActorWorldOffset(GetCameraPanDirection() * CameraPanSpeed);
	
	//PanMoveCamera(GetCameraPanDirection());
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("CameraZoom", this, &ACameraPawn::ZoomCamera);
}

FVector ACameraPawn::GetCameraPanDirection()
{
	float MousePosX;
	float MousePosY;

	float CamDirectionX = 0.f;
	float CamDirectionY = 0.f;

	if(PC->GetMousePosition(MousePosX,MousePosY))
	{
		if (MousePosX <= Margin)
		{
			CamDirectionX = -1;
		}

		if (MousePosY <= Margin)
		{
			CamDirectionY = -1;
		}

		if(MousePosX >= ScreenSizeX - Margin)
		{
			CamDirectionX = 1;
		}

		if (MousePosY >= ScreenSizeY - Margin)
		{
			CamDirectionY = 1;
		}
	}

	
	
	return FVector(CamDirectionX, CamDirectionY, 0.f);
}

void ACameraPawn::PanMoveCamera(FVector PanDirection)
{
	if (PanDirection == FVector::ZeroVector)
	{
		return;
	} else
	{
		AddActorWorldOffset(GetCameraPanDirection() * CameraPanSpeed);	
	}
}

void ACameraPawn::ZoomCamera(float Val)
{
	CurrentArmLength = (Val * ZoomRate) + CurrentArmLength;

	SpringArm->TargetArmLength = CurrentArmLength;
}
