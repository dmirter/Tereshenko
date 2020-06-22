#pragma once
#include "CoreMinimal.h"
#include <Runtime\Engine\Classes\Components\SphereComponent.h>
#include "PaperCharacter.h"
#include "Components/BoxComponent.h"
#include "Enemy.generated.h"

class AMyProject2Character;
class ATargetPoint1;


UCLASS()
class MYPROJECT2_API AEnemy : public APaperCharacter
{
	GENERATED_BODY()

public:
	AEnemy();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BaseAttackDamage;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool Back;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* AttackRangeSphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* RunningAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* JumpAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* IdleAnimation;
	AMyProject2Character* avatar;
	UPROPERTY()
		FTimerHandle SpawnTimerHandle;

protected:
	virtual void BeginPlay() override;
public:	
	ATargetPoint1* notavatar;
	UFUNCTION(BlueprintCallable)
	float InflictDamage();
	virtual void Tick(float DeltaSeconds) override;
	UFUNCTION( BlueprintCallable)
		void Destroy();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(Reliable, Server, WithValidation)
		void ServerFunction();
	void ServerFunction_Implementation();
	bool ServerFunction_Validate();
};
