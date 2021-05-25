// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree_Splay.h"

void ATree_Splay::InsertElement_Implementation(int key) {
  if (this->Head == nullptr) {
    Head = GetWorld()->SpawnActor<ASplay_Node>(NodeType);
    Head->key = key;
  } else {
    this->Head = dynamic_cast<ASplay_Node*>(this->Head)->insert(dynamic_cast<ASplay_Node*>(this->Head), key);
  }
  ReFindH();
}

void ATree_Splay::DeleteElement_Implementation(int key) {
  this->Head = dynamic_cast<ASplay_Node*>(this->Head)->delete_(dynamic_cast<ASplay_Node*>(this->Head), key);
  ReFindH();
}

void ATree_Splay::SetVisibility_Implementation(bool vis) {
  SetVisibilityElem(vis, Head);
}
