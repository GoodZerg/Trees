// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTreeInterface.h"
#include "AVL_Node.h"
#include "Tree_AVL.generated.h"

/**
 * 
 */
UCLASS()
class TREEPROJECT_API ATree_AVL : public AActor, public IBaseTreeInterface {
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AAVL_Node> NodeType;

	UFUNCTION(BlueprintCallable)
	virtual void InsertElement(int key) override;

	virtual void DeleteElement(int key) override;
};
