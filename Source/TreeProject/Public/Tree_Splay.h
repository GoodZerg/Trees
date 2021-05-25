// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTreeInterface.h"
#include "Splay_Node.h"
#include "Tree_Splay.generated.h"

UCLASS()
class TREEPROJECT_API ATree_Splay : public AActor, public IBaseTreeInterface {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASplay_Node> NodeType;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void InsertElement(int key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void DeleteElement(int key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetVisibility(bool vis);

};
