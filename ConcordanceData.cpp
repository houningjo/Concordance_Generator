// ConcordanceData.cpp
// Created by Ning Hou on 10/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file ConcordanceData.h*/
/** This ConcordanceData class creates a ConcordanceData object that holds
 * a key word string and a LinkedList of contexts.
 */

#include <string>
#include "LinkedList.h"
#include "ConcordanceData.h"
using namespace std;


ConcordanceData::ConcordanceData(){
}

ConcordanceData::ConcordanceData(const string otherKey, const string before, const string after){
    key = otherKey;
    
    this->contextList.insertTail(before, after);
    
}

void ConcordanceData::update(const string before, const string after){
    contextList.insertTail(before, after);
}

bool ConcordanceData::operator > (const ConcordanceData& other){
    if(key > other.key){
        return true;
    }
    return false;
}

bool ConcordanceData::operator ==(const ConcordanceData& other){
    if(key == other.key){
        return true;
    }
    return false;
}

bool ConcordanceData::operator <(const ConcordanceData& other){
    if(key < other.key){
        return true;
    }
    return false;
}

const ConcordanceData& ConcordanceData::operator = (const ConcordanceData& other){
    // avoids self assignment
    if (this == &other){
        return *this;
    }
    this->key = other.key;
    
    this->contextList.clear();
    
    Node *curr = other.contextList.getHead();
    
    // traverse each node in the copyFrom
    // create a node in this with the digit value
    // of copyFrom
    while(curr != nullptr){
        this->contextList.insertTail(curr->before, curr->after);
        curr = curr->next;
    }
    
    return *this;
}

ostream& operator << (ostream& output, const ConcordanceData& other){

    //output << other.key << endl;
    other.contextList.display();
    
    return output;
}
    

