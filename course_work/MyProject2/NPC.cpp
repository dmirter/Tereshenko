#include "NPC.h"
#include "PaperFlipbookComponent.h"
#include "Engine/Engine.h"
#include "SpawnWall.h"
#include "SpawnNPC.h"
#include "Wall.h"
#include "Components/InputComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <MyProject2\TargetPoint1.h>
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>
#include "Net/UnrealNetwork.h"

ANPC::ANPC()

{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	GetCharacterMovement()->MaxFlySpeed = 400.0f;

	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;
	Speed = 20; 
	HitPoints = 20;
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;
	GoHome = false;
}

void ANPC::BeginPlay()
{
	Super::BeginPlay();

	if (Role < ROLE_Authority)
	{
		ServerFunction();
		return;
	}
	TSubclassOf<ASpawnWall> ClassToFind;
	ClassToFind = ASpawnWall::StaticClass();
	avatar = Cast<ASpawnWall>(UGameplayStatics::GetActorOfClass(GetWorld(), ClassToFind));
}

void ANPC::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
		const FVector PlayerVelocity = GetVelocity();
		const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();
		float TravelDirection = PlayerVelocity.X;
		UPaperFlipbook* DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? RunningAnimation : IdleAnimation;
		if (GetSprite()->GetFlipbook() != DesiredAnimation)
		{
			GetSprite()->SetFlipbook(DesiredAnimation);
		}

		if (GoHome == false) {
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
		if(TravelDirection < 0.0f)
		{
			RootComponent->SetWorldRotation(FRotator(0.0f, 180.0f, 0.0f));
		}
		else if (TravelDirection > 0.0f)
		{
			RootComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
		}

}

void ANPC::Home() {
	
	GoHome = true;
	TSubclassOf<ASpawnNPC> ClassToFind;
	ClassToFind = ASpawnNPC::StaticClass();
	notavatar = Cast<ASpawnNPC>(UGameplayStatics::GetActorOfClass(GetWorld(), ClassToFind));
}
void ANPC::ServerFunction_Implementation() {
	BeginPlay();
}

bool ANPC::ServerFunction_Validate() {
	return true;
}