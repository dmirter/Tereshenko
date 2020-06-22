#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "MyTargetPoint.h"
#include "Net/UnrealNetwork.h"

AMyTargetPoint::AMyTargetPoint(){
	bReplicates = true;

}

void AMyTargetPoint::BeginPlay()
{
	if (Role < ROLE_Authority)
	{
		ServerFunction();

		return;
	}	UWorld* WRLD = GetWorld();
	WRLD->GetTimerManager().SetTimer(handle1, this, &AMyTargetPoint::Spawn, 5.0f, true);
}
void AMyTargetPoint::Spawn() {
	

	UWorld* WRLD = GetWorld();
	FVector location = GetActorLocation();
	FRotator rotation = GetActorRotation();
	WRLD->SpawnActor(ActorToSpawn, &location, &rotation);

}
void AMyTargetPoint::ServerFunction_Implementation() {
	BeginPlay();
}

bool AMyTargetPoint::ServerFunction_Validate() {
	return true;
}