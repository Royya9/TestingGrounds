// Free to Play. By SoNa Games.

#include "PatrolComponent.h"

TArray<AActor*> UPatrolComponent::GetPatrolPoints() const
{
	return TargetPoints;
}

