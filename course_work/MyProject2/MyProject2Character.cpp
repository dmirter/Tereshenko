#include "MyProject2Character.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"
#include "Net/UnrealNetwork.h"


AMyProject2Character::AMyProject2Character()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	
	GetCapsuleComponent()->SetCapsuleHalfHeight(40.0f);
	GetCapsuleComponent()->SetCapsuleRadius(20.0f);
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 200.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 150.0f);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	

	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	SideViewCameraComponent->OrthoWidth = 1400.0f;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	CameraBoom->SetUsingAbsoluteRotation(true);
	SideViewCameraComponent->bUsePawnControlRotation = false;
	SideViewCameraComponent->bAutoActivate = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;
	Trees = 0;

	HitPoint = 100;
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;
}




void AMyProject2Character::UpdateAnimation()
{
	
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

	UPaperFlipbook* DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? RunningAnimation : IdleAnimation;
	if( GetSprite()->GetFlipbook() != DesiredAnimation 	)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}
void AMyProject2Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateCharacter();	
}



void AMyProject2Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyProject2Character::MoveRight);
}

void AMyProject2Character::MoveRight(float Value)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}



void AMyProject2Character::UpdateCharacter()
{
	UpdateAnimation();
	const FVector PlayerVelocity = GetVelocity();	
	float TravelDirection = PlayerVelocity.X;
	if (Controller != nullptr)
	{

		if (TravelDirection < 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0, 180.0f, 0.0f));
		}
		else if (TravelDirection > 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	}
}
void AMyProject2Character::TakeDamagePerson(float Damage)

{
	if (Role < ROLE_Authority)
	{
		ServerFunction(Damage);
		return;
	}

	const float ActualDamage = Damage;

	if (ActualDamage > 0.f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "-10 HP");

		HitPoint -= ActualDamage;
		if (HitPoint <= 0.f)
		{
			APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			DisableInput(PlayerController);

		}
	}
	
}
void AMyProject2Character::BeginPlay()
{
	Super::BeginPlay();

}
void AMyProject2Character::Resourses(float res) {
	
	const float Resourses = res;
	Trees += Resourses;
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Resourse + %f"), Trees));
}
void AMyProject2Character::ServerFunction_Implementation(float Damage) {
	TakeDamagePerson(Damage);
}

bool AMyProject2Character::ServerFunction_Validate(float Damage) {
	return true;
}
