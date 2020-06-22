#include "PaperFlipbookComponent.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>
#include <MyProject2\MyProject2Character.h>
#include <MyProject2\TargetPoint1.h>
#include "Net/UnrealNetwork.h"

#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"
#include "Engine/Engine.h"

#include "Components/BoxComponent.h"
#include "GameFramework/DamageType.h"
#include "UObject/UObjectGlobals.h"
#include "Enemy.h"

AEnemy::AEnemy()
{
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	PrimaryActorTick.bCanEverTick = true;
	Speed = 20; 
	GetCharacterMovement()->bOrientRotationToMovement = false;
	HitPoints = 20; 
	BaseAttackDamage = 1; 
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;
	Back = false;
}
void AEnemy::BeginPlay()
{

	Super::BeginPlay();
	if (Role < ROLE_Authority)
	{
		ServerFunction();
		return;
	}
	avatar = Cast<AMyProject2Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UWorld* world = GetWorld();
	world->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AEnemy::Destroy, 10.0f, true);
}

void AEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	const FVector EnemyVelocity = GetVelocity();
	const float EnemySpeedSqr = EnemyVelocity.SizeSquared();
	float TravelDirection = EnemyVelocity.X;
	
	UPaperFlipbook* DesiredAnimation = (EnemySpeedSqr > 0.0f) ? RunningAnimation : IdleAnimation;
	if (GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}

	if (Back == false) {
		if (!avatar) return;

		FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
		toPlayer.Normalize();
		AddMovementInput(toPlayer, Speed * DeltaSeconds);


	}
	else {
		FVector toPlayer = notavatar->GetActorLocation() - GetActorLocation();
		toPlayer.Normalize();
		AddMovementInput(toPlayer, Speed * DeltaSeconds);

	}
	
	if (TravelDirection < 0.0f)
	{
		RootComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (TravelDirection > 0.0f)
	{
		RootComponent->SetWorldRotation(FRotator(0.0f, 180.0f, 0.0f));
	}

	
}

void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
float AEnemy::InflictDamage()
{
	if (Role < ROLE_Authority)
	{
		ServerFunction();
		return 0;
	}

	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController != nullptr)
	{
		const float DamageAmount = 10.0f;
		return DamageAmount;
	}

	return 0;
}
void AEnemy::Destroy()
{
	
	Back = true;
	
	TSubclassOf<ATargetPoint1> ClassToFind;
	ClassToFind = ATargetPoint1::StaticClass();
	notavatar = Cast<ATargetPoint1>(UGameplayStatics::GetActorOfClass(GetWorld(), ClassToFind));
}
void AEnemy::ServerFunction_Implementation() {
	BeginPlay();
	InflictDamage();
}

bool AEnemy::ServerFunction_Validate() {
	return true;
}