#include <MyProject2\NPC.h>
#include "Wall.h"
#include "SpawnNPC.h"
#include "Engine/Engine.h"

#include "Net/UnrealNetwork.h"

ASpawnNPC::ASpawnNPC()
{
    PrimaryActorTick.bCanEverTick = true;
   
    bReplicates = true;

}

void ASpawnNPC::Tick(float DeltaSeconds) {
    Super::Tick(DeltaSeconds);

 

}
void ASpawnNPC::BeginPlay() {
    if (Role < ROLE_Authority)
    {
        ServerFunction();
        return;
    }

    SpawnCharacter();
}
void ASpawnNPC::SpawnCharacter()
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

void ASpawnNPC::ServerFunction_Implementation() {
    SpawnCharacter();
}

bool ASpawnNPC::ServerFunction_Validate() {
        return true;
  
}
