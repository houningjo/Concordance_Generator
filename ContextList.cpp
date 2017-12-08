// ContextList.cpp
// Created by Ning Hou on 10/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file ContextList.h*/
/** This ContextList class creates a ContextList object which is a
 * singly linkedlist that holds strings.
 */

#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <string>
#include "ContextList.h"

using namespace std;

// constructors
// default constructor
// Creates an empty ContextList.
ContextList::ContextList(){
}

/** Creates a ContextList object that stores the before and after contents.
 * @param newBefore the before context string
 * @param newAfter the after context string
 */
ContextList::ContextList(const string newBefore, const string newAfter){

    insertTail(newBefore, newAfter);
}

/** Creates a ContextList object that copies the specified ContextList other.
 * @param other a reference of the other ContextList
 */
ContextList::ContextList(const ContextList& other){
    Node* currPtr = other.getHead();
    
    while(currPtr != nullptr){
        insertTail(currPtr->before, currPtr->after);
        currPtr = currPtr->next;
    }   
}

// Deconstructor
ContextList::~ContextList(){
    clear();
}

/** Returns the size of this ContextList.
 * @return int the number of the Nodes this ContextList holds.
 */
int ContextList::numDigits() const{
	
    return size;
}

/** Returns the value of head of this ContextList.
 * @return Node* a pointer to the head of this ContextList
 */
Node* ContextList::getHead() const{
	
    return head;
}

/** Returns the value of tail of this ContextList.
 * @return Node* a pointer to the tail of this ContextList
 */
Node* ContextList::getTail() const{
	
    return tail;
}

/** Returns a string representation of the before context.
 * @param index the location of the Node
 * @return string a string representation of the before context
 */
string ContextList::getBefore(int index) const{
    
    // empty ContextList
    if(size == 0)
        throw invalid_argument("ContextList is empty");
    
    // index out of boundry
    if(index < 0 || index > size)
        throw invalid_argument("Invalid index");
    
    Node* currPtr = head;
    for(int hop = 0; hop < index; hop++){
        currPtr = currPtr->next;
    }
    
    return currPtr->before;
    
}

/** Returns a string representation of the after context.
 * @param index the location of the Node
 * @return string a string representation of the after context
 */
string ContextList::getAfter(int index) const{
    // empty ContextList
    if(size == 0)
        throw invalid_argument("ContextList is empty");
    
    // index out of boundry
    if(index < 0 || index > size)
        throw invalid_argument("Invalid index");
    
    Node* currPtr = head;
    for(int hop = 0; hop < index; hop++){
        currPtr = currPtr->next;
    }
    
    return currPtr->after;
}

/** Returns true if this ContextList is empty, false otherwise.
 * @return bool true if this ContextList is empty, false otherwise
 */
bool ContextList::isEmpty(){
	
    return size == 0;
}

/** Deletes all Nodes in this ContextList and sets size to 0.
 */
void ContextList::clear(){
    Node* garbage = head;
    while(garbage != nullptr){
		
        Node* theNext = garbage -> next;
        garbage->before = "";
        garbage->after = "";
        garbage->next = nullptr;
        delete garbage;
        garbage = theNext;
    }
    
    size = 0;
    head = nullptr;
    tail = nullptr;    
}

/** Inserts a Node with specified value at the end of this ContextList.
 * @param newBefore the before context string
 * @param newAfter the after context string
 */
void ContextList::insertTail(const string newBefore, const string newAfter){
    // creates a new node
    Node* newNode;
    newNode = new Node;
    newNode->before = newBefore;
    newNode->after = newAfter;
    newNode->next = nullptr;
    
    // check for empty ContextList    
    if(tail != nullptr){
        tail->next = newNode;
    }
    tail = newNode;

    if(head == nullptr){
        head = tail;
    }
    
    size++;    
}

/** Removes the last Node of this ContextList.
 */
void ContextList::removeTail(){
    // do nothing when it's an empty ContextList
    if(isEmpty()){
        return;
    }
    
    // general case
    Node* currPtr = tail;
    currPtr->before = "";
    currPtr->after = "";
    currPtr->next = nullptr;
    
    
    // check if currPtr was the only Node in ContextList
    if(tail != nullptr){
        tail->next = nullptr;
    }else{
        currPtr = nullptr;
    }
    
    delete currPtr;
    size--;   
}

/** Displays all before and after contexts in this ContextList with format.
 */
void ContextList::display() const{
    
    Node* currPtr = head;
    while(currPtr != nullptr){
        
        cout << setw(50);
        cout << currPtr->before << " ";
        cout << currPtr->after << " " << endl;
        currPtr = currPtr->next;
    }
}


