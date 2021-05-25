// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseNodeInterface.h"
#include "Treap_Node.generated.h"

/**
 * 
 */
UCLASS()
class TREEPROJECT_API ATreap_Node : public ABaseNodeInterface
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ATreap_Node> NodeType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int prior = 0;
};
