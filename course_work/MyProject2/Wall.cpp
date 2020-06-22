#include "Components/PrimitiveComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"
#include "Net/UnrealNetwork.h"

#include "Wall.h"

AWall::AWall()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

}

void AWall::BeginPlay()
{
		

}

void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWall::ServerFunction_Implementation(float Damage) {
}

bool AWall::ServerFunction_Validate(float Damage) {
	return true;
}