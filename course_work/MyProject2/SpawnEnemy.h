#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEnemy.generated.h"

UCLASS()
class MYPROJECT2_API ASpawnEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnEnemy();
	bool SpawnTimer;
	float time;
	UFUNCTION(BlueprintCallable)
		void Spawn();
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> ToSpawn;
	UPROPERTY()
		FTimerHandle SpawnTimerHandle;
protected:
	virtual void BeginPlay() override;
	int i;
public:	
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(Reliable, Server, WithValidation)
		void ServerFunction();
	void ServerFunction_Implementation();
	bool ServerFunction_Validate();
};
