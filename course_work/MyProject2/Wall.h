#pragma once
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

class AEnemy;

UCLASS()
class MYPROJECT2_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	AWall();
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
	UCapsuleComponent* BaseCollisionComponent;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Reliable, Server, WithValidation)
		void ServerFunction(float Damage);
	void ServerFunction_Implementation(float Damage);
	bool ServerFunction_Validate(float Damage);
};
