// Free to Play. By SoNa Games.

#include "Gun.h"
#include "BallProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"


// Sets default values
AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = false;

	MyGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	MyGun->bCastDynamicShadow = false;
	MyGun->CastShadow = false;
	MyGun->SetupAttachment(RootComponent);

	GunMuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Gun MuzzleLocation"));
	GunMuzzleLocation->SetupAttachment(MyGun);
	GunMuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGun::OnFire()
{
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();

		const FRotator SpawnRotation = GunMuzzleLocation->GetComponentRotation();

		//const FVector SpawnLocation = ((GunMuzzleLocation != nullptr) ? GunMuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
		const FVector SpawnLocation = GunMuzzleLocation->GetComponentLocation();

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

		UE_LOG(LogTemp, Warning, TEXT("SpawnLocation is %s"), *SpawnLocation.ToString());
	}

	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	if (FireAnimation != NULL)
	{
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}

	}
}

