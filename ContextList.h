// ContextList.h
// Created by Ning Hou on 11/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file ContextList.h*/
/** This ContextList class creates a ContextList object which is a
 * singly linkedlist that holds strings.
 */

#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string before;
    string after;
    Node* next;
};

/** Definiton of a class of ContextList.*/
class ContextList
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    
public:
    // constructors
    // default constructor
    // Creates an empty ContextList.
    ContextList();
    
    /** Creates a ContextList object that stores the before and after contents.
     * @param newBefore the before context string
     * @param newAfter the after context string
     */
    ContextList(const string newBefore, const string newAfter);
    
    /** Creates a ContextList object that copies the specified ContextList other.
     * @param other a reference of the other ContextList
     */
    ContextList(const ContextList& other);
    
    // Deconstructor
    ~ContextList();
    
    // methods
    /** Returns the size of this ContextList.
     * @return int the number of the Nodes this ContextList holds.
     */
    int numDigits() const;
    
    /** Returns the value of head of this ContextList.
     * @return Node* a pointer to the head of this ContextList
     */
    Node* getHead() const;
    
    /** Returns the value of tail of this ContextList.
     * @return Node* a pointer to the tail of this ContextList
     */
    Node* getTail() const;
    
    /** Returns a string representation of the before context.
     * @param index the location of the Node
     * @return string a string representation of the before context
     */
    string getBefore(int index) const;
    
    /** Returns a string representation of the after context.
     * @param index the location of the Node
     * @return string a string representation of the after context
     */
    string getAfter(int index) const;
    
    /** Returns true if this ContextList is empty, false otherwise.
     * @return bool true if this ContextList is empty, false otherwise
     */
    bool isEmpty();
    
    /** Deletes all Nodes in this ContextList and sets size to 0.
     */
    void clear();
    
    /** Inserts a Node with specified value at the end of this ContextList.
     * @param newBefore the before context string
     * @param newAfter the after context string
     */
    void insertTail(const string newBefore, const string newAfter);
    
    /** Removes the last Node of this ContextList.
     */
    void removeTail();
    
    /** Displays all before and after contexts in this ContextList with format.
     */
    void display() const;
};

