// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseNodeInterface.h"
#include "BaseTreeInterface.generated.h"


UINTERFACE(MinimalAPI, Blueprintable)
class UBaseTreeInterface : public UInterface
{
	GENERATED_BODY()
};


class TREEPROJECT_API IBaseTreeInterface {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties

	virtual void InsertElement(int key) = 0;// PURE_VIRTUAL(UBaseTreeInterface::InsertElement, );

	virtual void DeleteElement(int key) = 0;// PURE_VIRTUAL(UBaseTreeInterface::DeleteElement, );

	void ReFindH();

	int FindSubTreeH(ABaseNodeInterface* p, int lastH);

	void SetChildsLocations(ABaseNodeInterface* p);

	ABaseNodeInterface* Head = nullptr;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	const int min_size = 150;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	const int shift_height = 150;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int max_h = 0;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int biggest_level_size = 0;

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};