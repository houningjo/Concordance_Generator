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

//ConcordanceData::ConcordanceData(const ConcordanceData& other){
//    key = other.key;
//    
//    contextList = LinkedList(other.contextList);
//    cout << "copy constructor here." << endl;
//}

//ConcordanceData::~ConcordanceData(){
//    cout << "destructor needed here." << endl;
//}

// methods
//string ConcordanceData::getKey() const{
//    return key;
//}

//LinkedList ConcordanceData::getContextList() const{
//    return contextList;
//}

void ConcordanceData::update(const string before, const string after){
    contextList.insertTail(before, after);
}

//void ConcordanceData::setKey(string newKey){
//
//}
//
//void ConcordanceData::setContextList(LinkedList& otherList){
//
//}

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

ostream& operator << (ostream& output, const ConcordanceData& other){

    //output << other.key << endl;
    other.contextList.display();
    
    return output;
}
    

