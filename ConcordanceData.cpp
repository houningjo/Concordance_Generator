// ConcordanceData.cpp
// Created by Ning Hou on 10/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file ConcordanceData.h*/
/** This ConcordanceData class creates a ConcordanceData object that holds
 * a key word string and a LinkedList of contexts.
 */

#include <string>
#include "ContextList.h"
#include "ConcordanceData.h"
using namespace std;


ConcordanceData::ConcordanceData(){
}

/** Creates a new ConcordanceData object with specified key, before,
 * and after context string.
 * @param otherKey a keyword string
 * @param before a before string
 * @param after an after string
 */
ConcordanceData::ConcordanceData(const string otherKey, const string before, const string after){
    key = otherKey;
    
    this->contextList.insertTail(before, after);
    
}

/** Updates this ConcordanceData with a specified before and after
 * string. 
 * @param before a before string
 * @param after an after string
 */
void ConcordanceData::update(const string before, const string after){
	
    contextList.insertTail(before, after);
}

/** Returns true if this ConcordanceData is greater than other 
 * ConcordanceData, false otherwise
 * @param other the other ConcordanceData
 * @return true if this ConcordanceData is greater than other
 * ConcordanceData, false otherwise
 */
bool ConcordanceData::operator > (const ConcordanceData& other){
    
    if(key > other.key){
        return true;
    }
    
    return false;
}

/** Returns true if this ConcordanceData is equal to other 
 * ConcordanceData, false otherwise
 * @param other the the reference of the other ConcordanceData
 * @return true if this ConcordanceData is equal to other
 * ConcordanceData, false otherwise
 */
bool ConcordanceData::operator ==(const ConcordanceData& other){
    
    if(key == other.key){
        return true;
    }
    
    return false;
}

/** Returns true if this ConcordanceData is smaller than other 
 * ConcordanceData, false otherwise
 * @param other the the reference of the other ConcordanceData
 * @return true if this ConcordanceData is smaller than other
 * ConcordanceData, false otherwise
 */
bool ConcordanceData::operator <(const ConcordanceData& other){
    
    if(key < other.key){
        return true;
    }
    
    return false;
}

/** Assigns a specified ConcordanceData to this ConcordanceData.
 * @param other the reference of the other ConcordanceData
 * @return ConcordanceData& a reference to this ConcordanceData
 */
const ConcordanceData& ConcordanceData::operator = (const ConcordanceData& other){
    // same value
    if (this == &other){
        return *this;
    }
    
    this->key = other.key;
 
    this->contextList.clear();
    
    Node *curr = other.contextList.getHead();
    
    // copy all contexts
    while(curr != nullptr){
        this->contextList.insertTail(curr->before, curr->after);
        curr = curr->next;
    }
    
    return *this;
}

/** Output the context of this ConcordanceData object.
 * @param output the reference of the output stream
 * @param theContextList the reference of this ContextList
 * @return ostream& a reference of the output stream
 */
ostream& operator << (ostream& output, const ConcordanceData& other){

    other.contextList.display();
    
    return output;
}
    

