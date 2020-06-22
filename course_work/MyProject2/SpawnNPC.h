#pragma once
#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/Actor.h"
#include "SpawnNPC.generated.h"
UCLASS()
class MYPROJECT2_API ASpawnNPC : public AActor
{
	GENERATED_BODY()
public:	
	ASpawnNPC();
	FTimerHandle time;
	virtual void Tick(float DeltaSeconds) override;
	UFUNCTION( BlueprintCallable)
	void SpawnCharacter();
	void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> Spawn;
	UFUNCTION(Reliable, Server, WithValidation)
	void ServerFunction();
	void ServerFunction_Implementation();
	bool ServerFunction_Validate();
};

