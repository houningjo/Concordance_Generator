// ConcordanceData.h
// Created by Ning Hou on 10/27/17.
// Copyright © 2017 Ning Hou. All rights reserved.

/** @file ConcordanceData.h*/
/** This ConcordanceData class creates a ConcordanceData object that holds
 * a key word string and a ContextList of contexts.
 */

#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "ContextList.h"
using namespace std;

/** Definiton of a class of ConcordanceData.*/

class ConcordanceData
{
private:
    string key;
    ContextList contextList;
    
public:
    ConcordanceData();
    
    /** Creates a new ConcordanceData object with specified key, before,
     * and after context string.
     * @param otherKey a keyword string
     * @param before a before string
     * @param after an after string
     */
    ConcordanceData(const string otherKey, const string before, const string after);
    
    /** Updates this ConcordanceData with a specified before and after
     * string. 
     * @param before a before string
     * @param after an after string
     */
    void update(const string before, const string after);
    
    /** Returns true if this ConcordanceData is greater than other 
     * ConcordanceData, false otherwise
     * @param other the other ConcordanceData
     * @return true if this ConcordanceData is greater than other
     * ConcordanceData, false otherwise
     */
    bool operator > (const ConcordanceData& other);
    
    /** Returns true if this ConcordanceData is equal to other 
     * ConcordanceData, false otherwise
     * @param other the reference of the other ConcordanceData
     * @return true if this ConcordanceData is equal to other
     * ConcordanceData, false otherwise
     */
    bool operator ==(const ConcordanceData& other);
    
   /** Returns true if this ConcordanceData is smaller than other 
	* ConcordanceData, false otherwise
	* @param other the the reference of the other ConcordanceData
	* @return true if this ConcordanceData is smaller than other
	* ConcordanceData, false otherwise
	*/
    bool operator <(const ConcordanceData& other);
    
    /** Assigns a specified ConcordanceData to this ConcordanceData.
     * @param other the reference of the other ConcordanceData
     * @return ConcordanceData& a reference to this ConcordanceData
     */
    const ConcordanceData& operator = (const ConcordanceData& other);
    
    /** Output the context of this ConcordanceData object.
     * @param output the reference of the output stream
     * @param theContextList the reference of this ContextList
     * @return ostream& a reference of the output stream
     */
    friend ostream& operator << (ostream& output, const ConcordanceData& theContextList);
    
};
