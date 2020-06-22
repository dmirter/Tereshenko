#include "Wall.h"
#include "Engine/World.h"
#include "SpawnWall.h"
#include "NPC.h"
#include "Net/UnrealNetwork.h"

ASpawnWall::ASpawnWall()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;

}

void ASpawnWall::Tick(float DeltaSeconds) {
    Super::Tick(DeltaSeconds);
}
void ASpawnWall::SpawnWall()
{
    if (Role < ROLE_Authority)
    {
        ServerFunction();

        return;
    }

  if (Spawn) {
   UWorld* world = GetWorld();
            if (world) {
              world->SpawnActor<AActor>(Spawn, GetActorLocation(), GetActorRotation());
             
            }
  }
    
}
void ASpawnWall::ServerFunction_Implementation() {
    SpawnWall();
}

bool ASpawnWall::ServerFunction_Validate() {
    return true;
}