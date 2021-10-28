// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerUnit.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
APlayerUnit::APlayerUnit()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	UnitMesh->SetupAttachment(GetRootComponent());

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>("SceneComponentForMuzzle");
	MuzzleLocation->SetupAttachment(GetRootComponent());

	Arrow = CreateDefaultSubobject<UArrowComponent>("ArrowComponent");
	Arrow->SetupAttachment(MuzzleLocation);

	TargetArea = CreateDefaultSubobject<USphereComponent>("SphereCollisionComponent");
	TargetArea->SetupAttachment(GetRootComponent());

	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void APlayerUnit::BeginPlay()
{
	Super::BeginPlay();

	//InitializePickup(UnitTemplate->GetClass());
}

// Called every frame
void APlayerUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}