// LinkedList.cpp
// Created by Ning Hou on 10/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file LinkedList.h*/
/** This LinkedList class creates a DlinkedList object which is a
 * singly linked list.
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

// constructors
// default constructor
/** Creates an empty LinkedList. */
LinkedList::LinkedList(){
}

/** Creates a LinkedList object that holds one Node with
* the before and after contents.
* @param newBefore the string representation of before context
* @param newAfter the string representation of after context
*/
LinkedList::LinkedList(const string newBefore, const string newAfter){

    insertTail(newBefore, newAfter);
}

/** Creates a deep copy of the specified LinkedList.
* @param other the reference of the specified LinkedList
*/
LinkedList::LinkedList(const LinkedList& other){
    Node* currPtr = other.getHead();
    while(currPtr != nullptr){
        insertTail(currPtr -> before, currPtr -> after);
        currPtr = currPtr -> next;
    }
}

// Deconstructor
LinkedList::~LinkedList(){
    clear();
}

// methods
/** Returns the number of the Node in this LinkedList.
* @return the number of the Node in this LinkedList
*/
int LinkedList::numDigits() const{
    return size;
}

/** Returns a pointer of the head of this LinkedList.
* @return Node* a pointer of the head of this LinkedList
*/
Node* LinkedList::getHead() const{
    return head;
}

/** Returns a pointer of the tail of this LinkedList.
* @return Node* a pointer of the tail of this LinkedList
*/
Node* LinkedList::getTail() const{
    return tail;
}

/** Retruns a string representation of the before context at 
 * a specified location index.
 * Throw an exception if this LinkedList is empty.
 * Throw an exception the index is smaller than 0 or 
 * index is greater or eaqual to size.
 * @param index the specified location
 * @return string a string representation of the before context
 * at a specified location
 */
string LinkedList::getBefore(int index) const{
    
    // empty LinkedList
    if(size == 0)
        throw invalid_argument("LinkedList is empty");
    
    // index out of boundry
    if(index < 0 || index > size)
        throw invalid_argument("Invalid index");
    
    Node* currPtr = head;
    for(int hop = 0; hop < index; hop++){
        currPtr = currPtr -> next;
    }
    
    return currPtr -> before;
    
}

/** Retruns a string representation of the after context at 
 * a specified location index.
 * Throw an exception if this LinkedList is empty.
 * Throw an exception the index is smaller than 0 or 
 * index is greater or eaqual to size.
 * @param index the specified location
 * @return string a string representation of the after context
 * at a specified location
 */
string LinkedList::getAfter(int index) const{
    // empty LinkedList
    if(size == 0)
        throw invalid_argument("LinkedList is empty");
    
    // index out of boundry
    if(index < 0 || index > size)
        throw invalid_argument("Invalid index");
    
    Node* currPtr = head;
    for(int hop = 0; hop < index; hop++){
        currPtr = currPtr -> next;
    }
    
    return currPtr -> after;
}

/** Returns true if this LinkedList is empty, false otherwise.
* @return bool true if this LinkedList is empty, false otherwise
*/
bool LinkedList::isEmpty(){
    return size == 0;
}

/** Deletes all Nodes in this LinkedList and sets size to 0.
*/
void LinkedList::clear(){
    Node* garbage = head;
    while(garbage != nullptr){
        Node* theNext = garbage -> next;
        garbage -> before = "";
        garbage -> after = "";
        garbage -> next = nullptr;
        delete garbage;
        garbage = theNext;
    }
    
    size = 0;
    head = nullptr;
    tail = nullptr;
}

/** Inserts a Node with specified before and after value 
* at the end of this linkedList.
* @param newBefore the before context
* @param newAfter the after context
*/
void LinkedList::insertTail(const string newBefore, const string newAfter){
    // creates a new node
    Node* newNode;
    newNode = new Node;
    newNode -> before = newBefore;
    newNode -> after = newAfter;
    newNode -> next = nullptr;
    
    // check for empty DLinkedList
    
    if(tail != nullptr){
        tail -> next = newNode;
    }
    tail = newNode;

    if(head == nullptr){
        head = tail;
    }
    size++;
    
}

/** Removes the last Node of this LinkedList.
*/
void LinkedList::removeTail(){
    // do nothing when it's an empty DLinkedList
    if(isEmpty()){
        return;
    }
    
    // general case
    Node* currPtr = tail;
    currPtr -> before = "";
    currPtr -> after = "";
    currPtr -> next = nullptr;
    
    
    // check if currPtr was the only Node in DLinkedList
    if(tail != nullptr){
        tail -> next = nullptr;
    }else{
        currPtr = nullptr;
    }
    delete currPtr;
    size--;
    
}

/** Displays all before and after context in this LinkedList.
*/
void LinkedList::display(){
    Node* currPtr = head;
    while(currPtr != nullptr){
        cout << currPtr -> before << " " << currPtr -> after << " " << endl;
        currPtr = currPtr -> next;
    }
}


