// ConcordanceData.h
// Created by Ning Hou on 10/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file ConcordanceData.h*/
/** This ConcordanceData class creates a ConcordanceData object that holds
 * a key word string and a LinkedList of contexts.
 */

#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

/** Definiton of a class of ConcordanceData.*/

class ConcordanceData
{
private:
    string key;
    LinkedList contextList;
    
public:
    ConcordanceData();
    
    ConcordanceData(const string otherKey, const string before, const string after);
    
//    ConcordanceData(const ConcordanceData& other);
    
    //~ConcordanceData();
    
    // methods
//    string getKey() const;
    
//    LinkedList getContextList() const;
    
    void update(const string before, const string after);
    
    bool operator > (const ConcordanceData& other);
    
    bool operator ==(const ConcordanceData& other);
    
    bool operator <(const ConcordanceData& other);
    
    friend ostream& operator << (ostream& output, const ConcordanceData& theContextList);
    
};
