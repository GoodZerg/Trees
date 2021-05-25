// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTreeInterface.h"
#include "RB_Node.h"
#include "Tree_RB.generated.h"

UCLASS()
class TREEPROJECT_API ATree_RB : public AActor, public IBaseTreeInterface {
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ARB_Node> NodeType;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void InsertElement(int key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void DeleteElement(int key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetVisibility(bool vis);
};
