#include "SpawnResourses.h"
#include "Net/UnrealNetwork.h"

ASpawnResourses::ASpawnResourses()
{
	PrimaryActorTick.bCanEverTick = true;
    SpawnTimer = false;
    time = 0;
    bReplicates = true;

}

void ASpawnResourses::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnResourses::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (SpawnTimer == false) {
        time += DeltaTime;
    }
    if (time > 10.0) {
        SpawnTimer = true;
    }
}

float ASpawnResourses::SpawnResourses()
{
    if (Role < ROLE_Authority)
    {
        ServerFunction();
        return 0;
    }
    ServerFunction();

    if (SpawnTimer == true) {
        SpawnTimer = false;
        time = 0;
        return 10;
    }
    return 0;
}
void ASpawnResourses::ServerFunction_Implementation() {
    SpawnResourses();
}

bool ASpawnResourses::ServerFunction_Validate() {
    return true;
}