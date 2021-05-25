// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseNodeInterface.h"
#include "Splay_Node.generated.h"

/**
 * 
 */
UCLASS()
class TREEPROJECT_API ASplay_Node : public ABaseNodeInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASplay_Node> NodeType;

	ASplay_Node* rightRotate(ASplay_Node* x);

	ASplay_Node* leftRotate(ASplay_Node* x);

	ASplay_Node* splay(ASplay_Node* root, int k);

	ASplay_Node* insert(ASplay_Node* root, int k);

	ASplay_Node* delete_(ASplay_Node* root, int k);

};
