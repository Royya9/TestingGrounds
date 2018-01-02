// Free to Play. By SoNa Games.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolComponent.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	/*APatrollingGuard* MyAI = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());*/

	PatrolComponent = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolComponent>();

	if (!PatrolComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cast Failed on PatrolComponent in ChooseNextWayPoint.cpp"));
		return EBTNodeResult::Failed; 
	}

	if (PatrolComponent->GetPatrolPoints().Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: %s is missing Patrol Points"), *OwnerComp.GetAIOwner()->GetPawn()->GetName());
		return EBTNodeResult::Failed;
	}
	
	int32 NextIndex = (Index + 1) % (PatrolComponent->GetPatrolPoints().Num());
	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolComponent->GetPatrolPoints()[Index]);
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index = %i and Next Index is %i"), Index, NextIndex);

	return EBTNodeResult::Succeeded;
}


