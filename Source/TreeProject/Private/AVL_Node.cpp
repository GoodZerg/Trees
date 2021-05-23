// Fill out your copyright notice in the Description page of Project Settings.


#include "AVL_Node.h"
#include "..\Public\AVL_Node.h"

int AAVL_Node::getHeight(AAVL_Node* p) {
  return p ? p->AVL_height : 0;
}

int AAVL_Node::bfactor(AAVL_Node* p) {
  return getHeight(dynamic_cast<AAVL_Node*>(p->right)) 
    - getHeight(dynamic_cast<AAVL_Node*>(p->left));
}

void AAVL_Node::fixheight(AAVL_Node* p) {
  int hl = getHeight(dynamic_cast<AAVL_Node*>(p->left ));
  int hr = getHeight(dynamic_cast<AAVL_Node*>(p->right));
  p->AVL_height = (hl > hr ? hl : hr) + 1;
}

AAVL_Node* AAVL_Node::rotateright(AAVL_Node* p) {
  AAVL_Node* q = dynamic_cast<AAVL_Node*>(p->left);
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

AAVL_Node* AAVL_Node::rotateleft(AAVL_Node* q) {
  AAVL_Node* p = dynamic_cast<AAVL_Node*>(q->right);
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}

AAVL_Node* AAVL_Node::balance(AAVL_Node* p) {
  fixheight(p);
  if (bfactor(p) == 2) {
    if (bfactor(dynamic_cast<AAVL_Node*>(p->right)) < 0)
      p->right = rotateright(dynamic_cast<AAVL_Node*>(p->right));
    return rotateleft(p);
  }
  if (bfactor(p) == -2) {
    if (bfactor(dynamic_cast<AAVL_Node*>(p->left)) > 0)
      p->left = rotateleft(dynamic_cast<AAVL_Node*>(p->left));
    return rotateright(p);
  }
  return p;
}

AAVL_Node* AAVL_Node::insert(AAVL_Node* p, int k) {
  if (!p) {
    AAVL_Node* newNode = GetWorld()->SpawnActor<AAVL_Node>(NodeType);
    newNode->key = k;
    return newNode;
  }
  if (k < p->key)
    p->left = insert(dynamic_cast<AAVL_Node*>(p->left), k);
  else
    p->right = insert(dynamic_cast<AAVL_Node*>(p->right), k);
  return balance(p);
}

AAVL_Node* AAVL_Node::findmin(AAVL_Node* p) {
  return p->left ? findmin(dynamic_cast<AAVL_Node*>(p->left)) : p;
}

AAVL_Node* AAVL_Node::removemin(AAVL_Node* p) {
  if (p->left == nullptr)
    return dynamic_cast<AAVL_Node*>(p->right);
  p->left = removemin(dynamic_cast<AAVL_Node*>(p->left));
  return balance(p);
}

AAVL_Node* AAVL_Node::remove(AAVL_Node* p, int k) {
  if (!p) return nullptr;
  if (k < p->key) {
    p->left = remove(dynamic_cast<AAVL_Node*>(p->left), k);
  }  else if (k > p->key) {
    p->right = remove(dynamic_cast<AAVL_Node*>(p->right), k);
  } else {
    AAVL_Node* q = dynamic_cast<AAVL_Node*>(p->left);
    AAVL_Node* r = dynamic_cast<AAVL_Node*>(p->right);
    p->Destroy();
    if (!r) return q;
    AAVL_Node* min = findmin(r);
    min->right = removemin(r);
    min->left = q;
    return balance(min);
  }
  return balance(p);
}
