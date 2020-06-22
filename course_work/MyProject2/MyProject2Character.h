#pragma once
#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "MyProject2Character.generated.h"

class UTextRenderComponent;

UCLASS(config=Game)
class AMyProject2Character : public APaperCharacter
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* SideViewCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animations)
	class UPaperFlipbook* RunningAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* TriggerCapsule;
	
	void UpdateAnimation();
	UFUNCTION( BlueprintCallable)
		void Resourses(float res);
	void MoveRight(float Value);

	void UpdateCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	FVector knockback;
public:
	AMyProject2Character();
	UFUNCTION( BlueprintCallable)
	void TakeDamagePerson(float DamageAmount);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
	float HitPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float Trees;

	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	UFUNCTION(Reliable, Server, WithValidation)
		void ServerFunction(float Damage);
	void ServerFunction_Implementation(float Damage);
	bool ServerFunction_Validate(float Damage);
};
