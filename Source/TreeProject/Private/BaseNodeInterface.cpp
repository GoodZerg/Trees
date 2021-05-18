// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNodeInterface.h"

#include "Components/StaticMEshComponent.h"

// Sets default values
ABaseNodeInterface::ABaseNodeInterface()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));

	
	Sprite->AttachTo(Root);
	//Sprite->SetRelativeLocation(FVector(0.0f, 0.0f, -7.0f));

	//Sprite->SetSprite(ConstructorHelpers::FObjectFinder<UPaperSprite>
	//	(TEXT("PaperSprite'/Game/2DSideScroller/Sprites/PrototypingSprite.PrototypingSprite'")).Object);
	//Sprite = Cast<UPaperSpriteComponent>(StaticLoadObject(UPaperSpriteComponent::StaticClass(), NULL, TEXT("PaperSprite'/Game/2DSideScroller/Sprites/PrototypingSprite.PrototypingSprite'")));

	//Sprite = CreateDefaultSubobject<UPaperSprite>(TEXT("Sprite"));
	
	//Sprite->AddToRoot();

	//Mesh->AttachTo(Root);
}

ABaseNodeInterface::ABaseNodeInterface(int key) {

	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	//Sprite = Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("/TreeProject/Content/2DSideScroller/Sprites/Ledge.uasset")));

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));



	Sprite->AttachTo(Root);
	//Sprite = Cast<UPaperSpriteComponent>(StaticLoadObject(UPaperSpriteComponent::StaticClass(), NULL, TEXT("PaperSprite'/Game/2DSideScroller/Sprites/PrototypingSprite.PrototypingSprite'")));
	//Sprite->SetTexture

//	Sprite->SetSprite(ConstructorHelpers::FObjectFinder<UPaperSprite>
	//	(TEXT("PaperSprite'/Game/2DSideScroller/Sprites/PrototypingSprite.PrototypingSprite'")).Object);

	//Sprite->SetSprite(dynamic_cast<UPaperSpriteComponent>(UPaperSpriteComponent::StaticClass(), StaticLoadObject(TEXT("/TreeProject/Content/2DSideScroller/Sprites/Ledge.uasset"))));
	//Sprite->AddToRoot();

	//Mesh->AttachTo(Root);

	this->key = key;
}

// Called when the game starts or when spawned
void ABaseNodeInterface::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseNodeInterface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

