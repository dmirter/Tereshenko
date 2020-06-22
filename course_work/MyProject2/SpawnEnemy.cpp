#include <MyProject2\Enemy.h>
#include <MyProject2\TimeOfDayHandler.h>
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnEnemy.h"

ASpawnEnemy::ASpawnEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
    i = 1;
    bReplicates = true;
}

void ASpawnEnemy::BeginPlay()
{
    if (Role < ROLE_Authority)
    {
        ServerFunction();
        return;
    }

    UWorld* world = GetWorld();
    world->GetTimerManager().SetTimer(SpawnTimerHandle, this,&ASpawnEnemy::Spawn, 2.0f, true);
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASpawnEnemy::Spawn()
{

        if (ToSpawn) {
            UWorld* world = GetWorld();
            if (world) {
                for (int j=i; j > 0; j--) {
                    world->SpawnActor<AActor>(ToSpawn, GetActorLocation(), GetActorRotation());
                }
                i++;

            }
      
        }
}
void ASpawnEnemy::ServerFunction_Implementation() {
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Server SpawnEnemy")));
    BeginPlay();
}

bool ASpawnEnemy::ServerFunction_Validate() {
    return true;
}