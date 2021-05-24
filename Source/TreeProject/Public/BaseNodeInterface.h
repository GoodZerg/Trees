// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "Components/SplineComponent.h"
#include "BaseNodeInterface.generated.h"

UCLASS()
class TREEPROJECT_API ABaseNodeInterface : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseNodeInterface();

	ABaseNodeInterface(int key);

	ABaseNodeInterface* left  = nullptr; 

	ABaseNodeInterface* right = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int key = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int hight = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	UPaperSpriteComponent* Sprite;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USplineComponent* leftSpline;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USplineComponent* rightSpline;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
