// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree_AVL.h"


void ATree_AVL::InsertElement(int key) {
  if (this->Head == nullptr) {
    Head = GetWorld()->SpawnActor<AAVL_Node>(NodeType);
    Head->key = key;
    //Head->hight = 1;
  } else {
    dynamic_cast<AAVL_Node*>(this->Head)->insert(dynamic_cast<AAVL_Node*>(this->Head), key);
  }
  ReFindH();
}

void ATree_AVL::DeleteElement(int key) {
  ;
}