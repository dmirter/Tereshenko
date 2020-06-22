#pragma once
#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "NPC.generated.h"
class ASpawnWall;
class ASpawnNPC;

UCLASS()
class MYPROJECT2_API ANPC : public APaperCharacter
{
	GENERATED_BODY()

public:
	ANPC();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;


	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* RunningAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* IdleAnimation;

	UFUNCTION( BlueprintCallable)
	void Home();
	ASpawnWall* avatar;
	virtual void Tick(float DeltaSeconds) override;
	bool GoHome;
	ASpawnNPC* notavatar;
	UFUNCTION(Reliable, Server, WithValidation)
		void ServerFunction();
	void ServerFunction_Implementation();
	bool ServerFunction_Validate();
	

};
