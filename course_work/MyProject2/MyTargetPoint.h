#pragma once
#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "MyTargetPoint.generated.h"

UCLASS()
class MYPROJECT2_API AMyTargetPoint : public ATargetPoint
{
	GENERATED_BODY()
		AMyTargetPoint();
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> ActorToSpawn;

	UFUNCTION()
		void Spawn();
	UFUNCTION(Reliable, Server, WithValidation)
	void ServerFunction();
	void ServerFunction_Implementation();
	bool ServerFunction_Validate();
	FTimerHandle handle1;
};
