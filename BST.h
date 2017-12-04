// BST.h
// Created by Ning Hou on 11/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file BST.h*/
/** This BST template creates a template for a Binary Search Tree.
 */

#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

/** Definiton of a template of BST.*/
template <class T>
class BST {

struct Node{
    T item;
    Node* left;
    Node* right;

};
    
private:

    Node* root = nullptr;
    
    // helper methods
    /** Returns true if sucessfully insert a Node with specified value in
     * this BST template, false otherwise.
     * @param root the root of this BST template
     * @param value the specified value
     * @return bool true if successfully insert a Node with specified value
     * in this BST template, false otherwise
     */
    bool insertHelper(Node*& root, const T value){
        // base case, insert to an empty BST
        if(root == nullptr){
            root = new Node;
            root->item = value;
            root->left = nullptr;
            root->right = nullptr;
            return true;
        }
        
        if(root -> item > value){
            return insertHelper(root -> left, value);
        }
        if(root -> item == value){
            return false;
        }
        
        return insertHelper(root -> right, value);
    }
    
    /** Returns a pointer to the Node with specified value found in this BST,
     * nullptr if value not found.
     * @param root the root of this BST template
     * @param value the specified value
     * @return Node<T>* a pointer to the Node with specified value,
     * nullptr if value not found
     */
    Node* findHelper(Node* root, const T value) const{
        //base case, didn't find value
        if(root == nullptr){
            return nullptr;
        }
        
        // base case, current node is the value
        if(root -> item == value){
            return root;
        }
        
        // value < current node
        if(root -> item > value){
            return findHelper(root -> left, value);
        }
        
        // value > current node
        return findHelper(root -> right, value);
    }
    
    /** Returns a pointer to the Node holding the largest value in this BST.
     * @param root the root of this BST template
     * @return Node<T>* a pointer to the Node holds the largest value,
     * nullptr if empty BST
     */
    Node* findMax(Node* root) const{
        // empty tree
        if(root == nullptr){
            return nullptr;
        }
        // no right child
        else if(root -> right == nullptr){
            return root;
        }
        
        return findMax(root -> left);
        
    }
    
    /** Returns a pointer to the Node holding the smallest value in this BST.
     * @param root the root of this BST template
     * @return Node<T>* a pointer to the Node holds the smallest value,
     * nullptr if empty BST
     */
    Node* findMin(Node* root) const{
        // empty tree
        if(root == nullptr){
            return nullptr;
        }
        // no left child
        else if(root -> left == nullptr){
            return root;
        }
        
        return findMin(root -> right);
    }
    
    /** Returns a pointer to the new root in this BST, nullptr if BST is empty.
     * @param root the root of this BST template
     * @param value the specified value
     * @return Node<T>* a pointer to the new root in this BST, nullptr if BST is empty
     */
    Node* removeHelper(Node*& root, const T value){
        Node* temp;
        
        // empty tree
        if(root == nullptr){
            return nullptr;
        }
        // value is smaller than root
        else if(root -> item > value){
            root -> left = removeHelper(root -> left, value);
        }
        // value is larger than root
        else if(root -> item < value){
            root -> right = removeHelper(root -> right, value);
        }
        // has both children
        else if(root -> left != nullptr && root -> right != nullptr){
            // finds the smallest in right subtree
            temp = findMin(root -> right);
            // sets root to new value
            root -> item = temp -> item;
            root -> right = removeHelper(root -> right, root -> item);
        }
        // has only one child
        else{
            temp = root;
            if(root -> left == nullptr){
                root = root -> right;
            }
            else if(root -> right == nullptr){
                root = root -> left;
            }
            delete temp;
        }
        
        return root;
    }
    
    /** Removes all Nodes in this BST in postorder.
     * @param theRoot the root of this BST template
     */
    void clearHelper(Node*& theRoot){
        // empty tree
        if(theRoot == nullptr)
            return;
        // clear left child
        clearHelper(theRoot -> left);
        // clear right child
        clearHelper(theRoot -> right);
        // delete root
        theRoot -> left = nullptr;
        theRoot -> right = nullptr;
        theRoot = nullptr;
        delete theRoot;
    }
    
    /** Displays all Node in inorder.
     * @param root the root of this BST template
     */
    void inorderPrint(Node* root){
        if (root == nullptr)
            return;
        
        inorderPrint(root->left);
        cout<<root -> item << ' ';
        inorderPrint(root->right);
    }
    
public:
    
    BST(){}
    
    ~BST(){
        clear();
    }
    
    /** Returns true if sucessfully insert a Node with specified value in
     * this BST template, false otherwise.
     * @param value the specified value
     * @return bool true if successfully insert a Node with specified value
     * in this BST template, false otherwise
     */
    bool insert(const T value){
        return insertHelper(root, value);
    }
    
    /** Returns a pointer to the Node with specified value found in this BST,
     * nullptr if value not found.
     * @param value the specified value
     * @return Node<T>* a pointer to the Node with specified value,
     * nullptr if value not found
     */
    Node* find(const T value) const{
        return findHelper(root, value);
    }
    
    /** Returns a pointer to the new root in this BST, nullptr if BST is empty.
     * @param value the specified value
     * @return Node<T>* a pointer to the new root in this BST, nullptr if BST is empty
     */
    Node* remove(const T value){
        return removeHelper(root, value);
    }
    
    /** Removes all Nodes in this BST in postorder.
     */
    void clear(){
        clearHelper(root);
    }
    
    /** Displays all Node in inorder.
     */
    void display(){
        inorderPrint(root);
        cout << endl;
    }
    
};





