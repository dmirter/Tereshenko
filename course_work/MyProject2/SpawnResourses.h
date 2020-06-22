#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnResourses.generated.h"

UCLASS()
class MYPROJECT2_API ASpawnResourses : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnResourses();

protected:
	virtual void BeginPlay() override;
	
	bool SpawnTimer;
	float time;
	UFUNCTION( BlueprintCallable)
		float SpawnResourses();
public:	
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(Reliable, Server, WithValidation)
		void ServerFunction();
	void ServerFunction_Implementation();
	bool ServerFunction_Validate();
};
