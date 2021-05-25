// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree_Treap.h"

bool checkTreap(ABaseNodeInterface* elem, int64_t key) {
  if (elem == nullptr) {
    return false;
  }
  if (elem->key == key) {
    return true;
  }
  return (checkTreap(elem->right, key) || checkTreap(elem->left, key));
}

void ATree_Treap::InsertElement_Implementation(int key) {
  if (checkTreap(Head, key)) return;
  if (this->Head == nullptr) {
    Head = GetWorld()->SpawnActor<ATreap_Node>(NodeType);
    Head->key = key;
    dynamic_cast<ATreap_Node*>(Head)->prior = rand();
  } else {
    ATreap_Node* new_node = GetWorld()->SpawnActor<ATreap_Node>(NodeType);
    new_node->key = key;
    new_node->prior = rand();
    new_node->left = nullptr;
    new_node->right = nullptr;
    ABaseNodeInterface* left_tree, * right_tree;
    splitTree(dynamic_cast<ATreap_Node*>(Head), key, left_tree, right_tree);
    Head = mergeTree(left_tree, new_node);
    Head = mergeTree(dynamic_cast<ATreap_Node*>(Head), right_tree);
  }
  ReFindH();
}

void ATree_Treap::DeleteElement_Implementation(int key) {
  if (!checkTreap(Head, key)) return;
  ABaseNodeInterface* left_tree, * right_tree;
  ABaseNodeInterface* left_tree_second, * right_tree_second;

  splitTree(dynamic_cast<ATreap_Node*>(Head), key, left_tree, right_tree);
  splitTree(dynamic_cast<ATreap_Node*>(right_tree), key + 1, left_tree_second, right_tree_second);

  left_tree_second->Destroy();

  Head = mergeTree(left_tree, right_tree_second);

  ReFindH();
}

void ATree_Treap::SetVisibility_Implementation(bool vis) {
  SetVisibilityElem(vis, Head);
}

void ATree_Treap::splitTree(ATreap_Node* point_tree, int64_t key, ABaseNodeInterface*& left, ABaseNodeInterface*& right) {
  if (point_tree == nullptr) {
    left = nullptr;
    right = nullptr;
    return;
  }
  if (point_tree->key < key) {
    splitTree(dynamic_cast<ATreap_Node*>(point_tree->right), key, point_tree->right, right);
    left = point_tree;
  }
  else {
    splitTree(dynamic_cast<ATreap_Node*>(point_tree->left), key, left, point_tree->left);
    right = point_tree;
  }
}

ABaseNodeInterface* ATree_Treap::mergeTree(ABaseNodeInterface* left, ABaseNodeInterface* right) {
  if (left == nullptr) {
    return right;
  }
  if (right == nullptr) {
    return left;
  }
  if (dynamic_cast<ATreap_Node*>(left)->prior > dynamic_cast<ATreap_Node*>(right)->prior) {
    left->right = mergeTree(left->right, right);
    return left;
  } else {
    right->left = mergeTree(left, right->left);
    return right;
  }
}
