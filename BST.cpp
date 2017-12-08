// BST.cpp
// Created by Ning Hou on 11/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file BST.cpp*/
/** This BST template creates a template for a Binary Search Tree.
 */

#include "BST.h"
#include <iostream>
using namespace std;
    
// helper methods
/** Returns true if sucessfully insert a BSTNode with specified value in
 * this BST template, false otherwise.
 * @param root the root of this BST template
 * @param value the specified value
 * @return bool true if successfully insert a Node with specified value
 * in this BST template, false otherwise
 */
template <class T>
bool BST<T>::insertHelper(BSTNode*& root, const T& value){
    // base case, insert to an empty BST
    if(root == nullptr){
        root = new BSTNode;
        root->item = value;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }
    
    if(root->item > value){
        return insertHelper(root->left, value);
    }
    
    if(root->item == value){
        return false;
    }
    
    return insertHelper(root->right, value);
}

/** Returns a pointer to the BSTNode with specified value found in this BST,
 * nullptr if value not found.
 * @param root the root of this BST template
 * @param value the specified value
 * @return BSTNode<T>* a pointer to the BSTNode with specified value,
 * nullptr if value not found
 */
template <class T>
typename BST<T>::BSTNode* BST<T>::findHelper(BSTNode* root, const T& value) const{
    //base case, didn't find value
    if(root == nullptr){
        return nullptr;
    }
    
    // base case, current BSTNode is the value
    if(root->item == value){
        return root;
    }
    
    // value < current BSTNode
    if(root->item > value){
        return findHelper(root->left, value);
    }
    
    // value > current BSTNode
    return findHelper(root->right, value);
}

/** Returns a pointer to the BSTNode holding the largest value in this BST.
 * @param root the root of this BST template
 * @return BSTNode<T>* a pointer to the BSTNode holds the largest value,
 * nullptr if empty BST
 */
template <class T>
typename BST<T>::BSTNode* BST<T>::findMax(BSTNode* root) const{
    // empty tree
    if(root == nullptr){
        return nullptr;
    }
    // no right child
    else if(root->right == nullptr){
        return root;
    }
    
    return findMax(root->left);   
}

/** Returns a pointer to the BSTNode holding the smallest value in this BST.
 * @param root the root of this BST template
 * @return BSTNode<T>* a pointer to the BSTNode holds the smallest value,
 * nullptr if empty BST
 */
template <class T>
typename BST<T>::BSTNode* BST<T>::findMin(BSTNode* root) const{
    // empty tree
    if(root == nullptr){
        return nullptr;
    }
    // no left child
    else if(root->left == nullptr){
        return root;
    }
    
    return findMin(root->right);
}

/** Returns a pointer to the new root in this BST, nullptr if BST is empty.
 * @param root the root of this BST template
 * @param value the specified value
 * @return BSTNode<T>* a pointer to the new root in this BST, nullptr if BST is empty
 */
template <class T>
typename BST<T>::BSTNode* BST<T>::removeHelper(BSTNode*& root, const T value){
    BSTNode* temp;
    
    // empty tree
    if(root == nullptr){
        return nullptr;
    }
    // value is smaller than root
    else if(root->item > value){
        root->left = removeHelper(root->left, value);
    }
    // value is larger than root
    else if(root->item < value){
        root->right = removeHelper(root->right, value);
    }
    // has both children
    else if(root->left != nullptr && root->right != nullptr){
        // finds the smallest in right subtree
        temp = findMin(root->right);
        
        // sets root to new value
        root->item = temp->item;
        root->right = removeHelper(root->right, root->item);
    }
    // has only one child
    else{
        temp = root;
        if(root->left == nullptr){
            root = root->right;
        }
        else if(root->right == nullptr){
            root = root->left;
        }
        delete temp;
    }
    
    return root;
}

/** Removes all BSTNodes in this BST in postorder.
 * @param theRoot the root of this BST template
 */
template <class T>
void BST<T>::clearHelper(BSTNode*& theRoot){
    // empty tree
    if(theRoot == nullptr)
        return;
    
    // clear left child
    clearHelper(theRoot->left);
    // clear right child
    clearHelper(theRoot->right);
    
    // delete root
    theRoot->left = nullptr;
    theRoot->right = nullptr;
    theRoot = nullptr;
    delete theRoot;
}

/** Displays all BSTNode in inorder.
 * @param root the root of this BST template
 */
template <class T>
void BST<T>::inorderPrint(BSTNode* root){
    if (root == nullptr)
        return;
    
    inorderPrint(root->left);
    cout<< root->item;
    inorderPrint(root->right);
}

template <class T>
BST<T>::BST(){}

template <class T>
BST<T>::~BST(){
    clear();
}

/** Returns true if sucessfully insert a BSTNode with specified value in
 * this BST template, false otherwise.
 * @param value the specified value
 * @return bool true if successfully insert a BSTNode with specified value
 * in this BST template, false otherwise
 */
template <class T>
bool BST<T>::insert(const T& value){
	
    return insertHelper(root, value);
}

/** Returns a pointer to the specified value in this BSTNode found in this BST,
 * nullptr if value not found.
 * @param value the specified value
 * @return T* a pointer to the specified value in this BSTNode,
 * nullptr if value not found
 */
template <class T>
T* BST<T>::find(const T& value) const{

      return &(findHelper(root, value))->item;
}

/** Returns a pointer to the new root in this BST, nullptr if BST is empty.
 * @param value the specified value
 * @return BSTNode<T>* a pointer to the new root in this BST, nullptr if BST is empty
 */
template <class T>
typename BST<T>::BSTNode* BST<T>::remove(const T value){
	
    return removeHelper(root, value);
}

/** Removes all BSTNodes in this BST in postorder.
 */
template <class T>
void BST<T>::clear(){
	
    clearHelper(root);
}

/** Displays all BSTNode in inorder.
 */
template <class T>
void BST<T>::display(){
	
    inorderPrint(root);
    cout << endl;
}







