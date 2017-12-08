// BST.h
// Created by Ning Hou on 11/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file BST.h*/
/** This BST template creates a template for a Binary Search Tree.
 */

#pragma once
#include <stdio.h>
//#include "BNode.h"
//#include <iostream>
using namespace std;

/** Definiton of a template of BST.*/
template <class T>
class BST {

struct BSTNode{
    T item;
    BSTNode* left;
    BSTNode* right;

};
    
private:

    BSTNode* root = nullptr;
    
    // helper methods
    /** Returns true if sucessfully insert a BSTNode with specified value in
     * this BST template, false otherwise.
     * @param root the root of this BST template
     * @param value the specified value
     * @return bool true if successfully insert a BSTNode with specified value
     * in this BST template, false otherwise
     */
    bool insertHelper(BSTNode*& root, const T& value);
    
    /** Returns a pointer to the BSTNode with specified value found in this BST,
     * nullptr if value not found.
     * @param root the root of this BST template
     * @param value the specified value
     * @return BSTNode<T>* a pointer to the BSTNode with specified value,
     * nullptr if value not found
     */
    BSTNode* findHelper(BSTNode* root, const T& value) const;
    
    /** Returns a pointer to the BSTNode holding the largest value in this BST.
     * @param root the root of this BST template
     * @return BSTNode<T>* a pointer to the BSTNode holds the largest value,
     * nullptr if empty BST
     */
    BSTNode* findMax(BSTNode* root) const;
    
    /** Returns a pointer to the BSTNode holding the smallest value in this BST.
     * @param root the root of this BST template
     * @return BSTNode<T>* a pointer to the BSTNode holds the smallest value,
     * nullptr if empty BST
     */
    BSTNode* findMin(BSTNode* root) const;
    
    /** Returns a pointer to the new root in this BST, nullptr if BST is empty.
     * @param root the root of this BST template
     * @param value the specified value
     * @return BSTNode<T>* a pointer to the new root in this BST, nullptr if BST is empty
     */
    BSTNode* removeHelper(BSTNode*& root, const T value);
    
    /** Removes all BSTNodes in this BST in postorder.
     * @param theRoot the root of this BST template
     */
    void clearHelper(BSTNode*& theRoot);
    
    /** Displays all BSTNode in inorder.
     * @param root the root of this BST template
     */
    void inorderPrint(BSTNode* root);
    
public:
    
    BST();
    
    ~BST();
    
    /** Returns true if sucessfully insert a BSTNode with specified value in
     * this BST template, false otherwise.
     * @param value the specified value
     * @return bool true if successfully insert a BSTNode with specified value
     * in this BST template, false otherwise
     */
    bool insert(const T& value);
    
    /** Returns a pointer to the specified value in this BSTNode found in this BST,
     * nullptr if value not found.
     * @param value the specified value
     * @return T* a pointer to the specified value in this BSTNode,
     * nullptr if value not found
     */
    T* find(const T& value) const;
    
    /** Returns a pointer to the new root in this BST, nullptr if BST is empty.
     * @param value the specified value
     * @return BSTNode<T>* a pointer to the new root in this BST, nullptr if BST is empty
     */
    BSTNode* remove(const T value);
    
    /** Removes all BSTNodes in this BST in postorder.
     */
    void clear();
    
    /** Displays all BSTNode in inorder.
     */
    void display();
    
};

#include "BST.cpp"




