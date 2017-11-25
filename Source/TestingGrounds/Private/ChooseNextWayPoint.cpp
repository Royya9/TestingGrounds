// Free to Play. By SoNa Games.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	APatrollingGuard* MyAI = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());

	if (!MyAI)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cast Failed on PatrollingGuard"));
		return EBTNodeResult::Aborted; 
	}
	
	int32 NextIndex = (Index + 1) % (MyAI->TargetPointsCPP.Num());
	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, MyAI->TargetPointsCPP[Index]);
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index = %i and Next Index is %i"), Index, NextIndex);

	return EBTNodeResult::Succeeded;
}


