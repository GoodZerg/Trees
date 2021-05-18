// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseNodeInterface.h"
#include "AVL_Node.generated.h"

/**
 * 
 */
UCLASS()
class TREEPROJECT_API AAVL_Node : public ABaseNodeInterface
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AAVL_Node> NodeType;

	int AVL_height = 0;

	int getHeight(AAVL_Node* p);

	int bfactor(AAVL_Node* p);

	void fixheight(AAVL_Node* p);

	AAVL_Node* rotateright(AAVL_Node* p);

	AAVL_Node* rotateleft(AAVL_Node* q);

	AAVL_Node* balance(AAVL_Node* p);

	AAVL_Node* insert(AAVL_Node* p, int k);

};
