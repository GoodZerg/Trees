// Fill out your copyright notice in the Description page of Project Settings.


#include "Splay_Node.h"

ASplay_Node* ASplay_Node::rightRotate(ASplay_Node* x) {
  ASplay_Node* y = dynamic_cast<ASplay_Node*>(x->left);
  x->left = y->right;
  y->right = x;
  return y;
}

ASplay_Node* ASplay_Node::leftRotate(ASplay_Node* x) {
  ASplay_Node* y = dynamic_cast<ASplay_Node*>(x->right);
  x->right = y->left;
  y->left = x;
  return y;
}

ASplay_Node* ASplay_Node::splay(ASplay_Node* root, int k) {

  if (root == nullptr || root->key == k) return root;
 
  if (root->key > k) {
    if (root->left == nullptr) return root;

    
    if (root->left->key > k) /* Zig-Zig */ {
      root->left->left = splay(dynamic_cast<ASplay_Node*>(root->left->left), k);
      root = rightRotate(root);
    } else if (root->left->key < k) /* Zig-Zag */ {
      root->left->right = splay(dynamic_cast<ASplay_Node*>(root->left->right), k);
 
      if (root->left->right != nullptr)
        root->left = leftRotate(dynamic_cast<ASplay_Node*>(root->left));
    }

    return (root->left == nullptr) ? root : rightRotate(root);
  } else {

    if (root->right == nullptr) return root;

    if (root->right->key > k) /* Zag-Zig */ {
      root->right->left = splay(dynamic_cast<ASplay_Node*>(root->right->left), k);
      if (root->right->left != nullptr)
        root->right = rightRotate(dynamic_cast<ASplay_Node*>(root->right));
    } else if (root->right->key < k) /* Zag-Zag */ {
      root->right->right = splay(dynamic_cast<ASplay_Node*>(root->right->right), k);
      root = leftRotate(root);
    }

    return (root->right == nullptr) ? root : leftRotate(root);
  }
}


ASplay_Node* ASplay_Node::insert(ASplay_Node* root, int k) {

  root = splay(root, k);
  if (root->key == k) return root;

  ASplay_Node* newnode = GetWorld()->SpawnActor<ASplay_Node>(NodeType);
  newnode->key = k;

  if (root->key > k) {
    newnode->right = root;
    newnode->left = root->left;
    root->left = nullptr;
  } else {
    newnode->left = root;
    newnode->right = root->right;
    root->right = NULL;
  }

  return newnode;
}

ASplay_Node* ASplay_Node::delete_(ASplay_Node* root, int k) {

  if (root == nullptr)return nullptr;

  root = splay(root, k);

  if (k != root->key) return root;

  ASplay_Node* p = root;
  if (root->left == nullptr) {
    root = dynamic_cast<ASplay_Node*>(root->right);
  } else {
    root = splay(dynamic_cast<ASplay_Node*>(root->left), k);
    root->right = p->right;
  }

  p->Destroy();

  return root;
}