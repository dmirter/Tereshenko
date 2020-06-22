#pragma once
#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "SpawnWall.generated.h"

UCLASS()
class MYPROJECT2_API ASpawnWall : public ATargetPoint
{
	GENERATED_BODY()
		ASpawnWall();

	virtual void Tick(float DeltaSeconds) override;
	UFUNCTION( BlueprintCallable)
		void SpawnWall();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> Spawn;
	UFUNCTION(Reliable, Server, WithValidation)
		void ServerFunction();
	void ServerFunction_Implementation();
	bool ServerFunction_Validate();

};
