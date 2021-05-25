// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTreeInterface.h"
#include "Treap_Node.h"
#include "Tree_Treap.generated.h"

UCLASS()
class TREEPROJECT_API ATree_Treap : public AActor, public IBaseTreeInterface {
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ATreap_Node> NodeType;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void InsertElement(int key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void DeleteElement(int key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetVisibility(bool vis);

private:
	void splitTree(ATreap_Node* point_tree, int64_t key, ABaseNodeInterface*& left, ABaseNodeInterface*& right);

	ABaseNodeInterface* mergeTree(ABaseNodeInterface* left, ABaseNodeInterface* right);
};
