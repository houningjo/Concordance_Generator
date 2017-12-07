// LinkedList.h
// Created by Ning Hou on 10/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file LinkedList.h*/
/** This LinkedList class creates a linkedList object which is a
 * singly linked list.
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

/** Definiton of a class of LinkedList.*/
class LinkedList
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    
public:
    // constructors
    // default constructor
    /** Creates an empty LinkedList. */
    LinkedList();
    
    /** Creates a LinkedList object that holds one Node with
    * the before and after contents.
    * @param newBefore the string representation of before context
    * @param newAfter the string representation of after context
    */
    LinkedList(const string newBefore, const string newAfter);
    
    /** Creates a deep copy of the specified LinkedList.
    * @param other the reference of the specified LinkedList
    */
    LinkedList(const LinkedList& other);
    
    // Deconstructor
    ~LinkedList();
    
    // methods
    /** Returns the number of the Node in this LinkedList.
    * @return the number of the Node in this LinkedList
    */
    int numDigits() const;
    
    /** Returns a pointer of the head of this LinkedList.
    * @return Node* a pointer of the head of this LinkedList
    */
    Node* getHead() const;
    
    /** Returns a pointer of the tail of this LinkedList.
    * @return Node* a pointer of the tail of this LinkedList
    */
    Node* getTail() const;
    
    /** Retruns a string representation of the before context at 
     * a specified location index.
     * Throw an exception if this LinkedList is empty.
     * Throw an exception the index is smaller than 0 or 
     * index is greater or eaqual to size.
     * @param index the specified location
     * @return string a string representation of the before context
     * at a specified location
     */
    string getBefore(int index) const;
    
    /** Retruns a string representation of the after context at 
     * a specified location index.
     * Throw an exception if this LinkedList is empty.
     * Throw an exception the index is smaller than 0 or 
     * index is greater or eaqual to size.
     * @param index the specified location
     * @return string a string representation of the after context
     * at a specified location
     */
    string getAfter(int index) const;
    
    /** Returns true if this LinkedList is empty, false otherwise.
    * @return bool true if this LinkedList is empty, false otherwise
    */
    bool isEmpty();
    
    /** Deletes all Nodes in this LinkedList and sets size to 0.
    */
    void clear();
    
    /** Inserts a Node with specified before and after value 
    * at the end of this linkedList.
    * @param newBefore the before context
    * @param newAfter the after context
    */
    void insertTail(const string newBefore, const string newAfter);
    
    /** Removes the last Node of this LinkedList.
    */
    void removeTail();
    
    /** Displays all before and after context in this LinkedList.
    */
    void display();
};

