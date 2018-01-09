// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TESTINGGROUNDS_API AGun : public AActor
{
	GENERATED_BODY()

	/* Gun Mesh*/
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USkeletalMeshComponent* MyGun;

	/*Gun Muzzle Location*/
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USceneComponent* GunMuzzleLocation;

public:	
	// Sets default values for this actor's properties
	AGun();

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector GunOffset;

	/*Projectile Class to Spawn*/
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class ABallProjectile> ProjectileClass;

	/*Sound to play when Gun is fired*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class USoundBase* FireSound;

	/*Anim Montage to play when Gun is fired*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class UAnimMontage* FireAnimation;

	class UAnimInstance* AnimInstance;

	/*Fires a Projectile*/
	void OnFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
