// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTreeInterface.h"

/*// Sets default values
UBaseTreeInterface::UBaseTreeInterface()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void UBaseTreeInterface::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UBaseTreeInterface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

int pow2(int a) {
	int ans = 1;
	for (size_t i = 0; i < a; i++) {
		ans *= 2;
	}
	return ans;
}

void IBaseTreeInterface::SetVisibilityElem(bool vis, ABaseNodeInterface* p) {
	if (p == nullptr) return;
	p->SetActorHiddenInGame(!vis);
	SetVisibilityElem(vis, p->left);
	SetVisibilityElem(vis, p->right);
}


void IBaseTreeInterface::ReFindH() {

	if (!this->Head->IsValidLowLevel() || this->Head == nullptr) return;


	max_h = FindSubTreeH(Head, -1);

	biggest_level_size = min_size * pow2(max_h);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("max_h: %i, biggest_level_size: %i"), max_h, biggest_level_size));
	Head->SetActorLocation(FVector(0, 0, 0));
	SetChildsLocations(Head);
}


int IBaseTreeInterface::FindSubTreeH(ABaseNodeInterface* p, int lastH) {
	if (p == nullptr) return lastH;
	p->hight = lastH + 1;
	int a = FindSubTreeH(p->left, lastH + 1);
	int b = FindSubTreeH(p->right, lastH + 1);
	return a > b ? a : b;
}

void IBaseTreeInterface::SetChildsLocations(ABaseNodeInterface* p) {
	if (p == nullptr) return;
	FVector parent_location = p->GetActorLocation();
	p->leftSpline->ClearSplinePoints();
	p->rightSpline->ClearSplinePoints();
	if (p->left != nullptr) {
		p->left->SetActorLocation(FVector(parent_location.X - (biggest_level_size/pow2(p->left->hight)), parent_location.Y, parent_location.Z - shift_height));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("left: %i"), p->left->key));
		//p->leftSpline->SetHiddenInGame(false);
		//p->leftSpline->SetDrawDebug(true);
		p->leftSpline->AddSplinePointAtIndex(p->GetActorLocation() - FVector(0,10,0), 0, ESplineCoordinateSpace::Local);
		p->leftSpline->AddSplinePointAtIndex(p->left->GetActorLocation() - FVector(0, 10, 0), 1, ESplineCoordinateSpace::Local);
		SetChildsLocations(p->left);
	}
	if (p->right != nullptr) {
		p->right->SetActorLocation(FVector(parent_location.X + (biggest_level_size / pow2(p->right->hight)), parent_location.Y, parent_location.Z - shift_height));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("right: %i"), p->right->key));
		//p->rightSpline->SetHiddenInGame(false);
		//p->rightSpline->SetDrawDebug(true);
		p->rightSpline->AddSplinePointAtIndex(p->GetActorLocation() - FVector(0, 10, 0), 0, ESplineCoordinateSpace::Local);
		p->rightSpline->AddSplinePointAtIndex(p->right->GetActorLocation() - FVector(0, 10, 0), 1, ESplineCoordinateSpace::Local);
		SetChildsLocations(p->right);
	}
}
