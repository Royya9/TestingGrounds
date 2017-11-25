// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Patrol Locations")
	TArray<AActor*>TargetPointsCPP;
	
	
};
