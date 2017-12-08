//
//  main.cpp
//  pro4
//
//  Created by Ning Hou on 11/29/17.
//  Copyright © 2017 Ning Hou. All rights reserved.

/** @file Program4.cpp*/
/** This Program4 class is a driver to for the concordance generator project.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include "ContextList.h"
#include "ConcordanceData.h"
#include "BST.h"

using namespace std;

const string STOPWORDS = "stopwords.txt";
const int CONTEXT_SIZE = 5;

/** Returns a string representation of the before context, 5 words or less
 * if it's at the beginning of the file, at a specified location 
 * in a string vector.
 * @param data the string vector
 * @param index the pecified location
 * @return string a string representation of the before context at a 
 * specified location in a string vector
 */
string getBeforeContext(vector<string> data, int index){
    string before = "";
    
    // starts from either the beginning of the file or
    // 5 words ahead
    int startIndex = index > 5 ? index - 5 : 0;
    
    for(int i = startIndex; i < index; i++){
      
            before += data[i] + " ";
    }
    
    return before;
}

/** Returns a string representation of the after context, 6 words
 * (including the keyword) or less if it's at the end of the file, 
 * at a specified location in a string vector.
 * @param data the string vector
 * @param index the pecified location
 * @return string a string representation of the after context at a 
 * specified location in a string vector
 */
string getAfterContext(vector<string> data, int index){
    string after = "";
    int len = index + CONTEXT_SIZE + 1;
    
    // len can't be larger than 6
    if (len > data.size()){
		
		len = data.size();
    }

    for (int i = index; i < len; i++){
		
        after += data[i] + " ";
    }
    
    return after;
}

/** Returns a string representation of the keyword. The return string 
 * will have no punctuation other than ' or -, and it will be in lowercase.
 * @param key the original keyword
 * @return string a processed keyword
 */
string setKey(string key){
    string newKey = "";
    
    if(!key.empty()){
		// take out punctuation unless it's ' or -
        for(int i = 0; i < key.length(); i++){
			
            if(!ispunct(key[i]) ||
               (( i < key.length() && i > 0) &&
               (key.compare(i, 1, "'") == 0 ||
               key.compare(i, 1, "-") == 0))){
				   
                newKey += key[i];
            }
        }
        // make it into lowercase
        transform(newKey.begin(), newKey.end(), newKey.begin(), ::tolower);
    }
    return newKey;
}

/** Returns true if the key is a number, false otherwise.
 * @param key the keyword
 * @return bool true if the key is a number, false otherwise
 */
bool isNumber(string key){
    bool isNum = true;
    
    for(int i = 0; i < key.length(); i++){
        if(!isdigit(key[i])){
            isNum = false;
        }
    }
    return isNum;
    
}

int main(int argc, const char * argv[]) {
    
    // stopwords BST
    BST<string> stopwordsBST;

    ifstream stopfile;
    stopfile.open(STOPWORDS);
	
	if(stopfile.is_open()){
		string stopTemp;
		
		// fill stopwordsBST
		while(!stopfile.eof()){
			stopfile >> stopTemp;
			stopwordsBST.insert(stopTemp);
		}
	}
    
    stopfile.close();
    
    
    // creates a nonstop word bst
    BST<ConcordanceData> corpusBST;
    //string corpusFile;
    //cin >> corpusFile;
    string corpusFile = argv[1]; 
    ifstream inFile(corpusFile);
    
    if(inFile.is_open()){
        string word;
        vector<string> data;
        
        int counter = 0;
        int index = 0;
        bool isBreakPoint = false;
        
        // read first 11 words
        while(inFile >> word){
            
            data.push_back(word);
            counter++;
            
            if(counter == 11 || inFile.eof())
                break;
        }
        
        // set break pointer flag
        if(data.size() > 0){
            isBreakPoint = true;
        }
        
        while(isBreakPoint == true){
            
            // create new ConcordanceData
            string keyword = setKey(data[index]);
            string before = getBeforeContext(data, index);
            string after = getAfterContext(data, index);
            ConcordanceData cd(keyword, before, after);
            
            // does not exist in stopwords or corpus
            if(stopwordsBST.find(data[index]) == nullptr &&
               corpusBST.find(cd) == nullptr){
                // check if it's a number
                if(!isNumber(keyword)){
                    corpusBST.insert(cd);
                }
                 
            }
            // exists in corpusBST
            else if(corpusBST.find(cd) != nullptr){
                (corpusBST.find(cd))->update(before, after);
            }
                
            // update index
            if(index >= CONTEXT_SIZE){
                // not the end of the file
                // erase first item in vector
                // add new word at the end
                if(!inFile.eof()){
                    inFile >> word;
                    data.erase(data.begin());
                    data.push_back(word);
                    
                }
                // at the end of the file, update index
                else{
                    index++;
                }
            }
            // update index
            else{
                index++;
            }
                
            // switch isBreakpoint flag
            if(index > data.size()){
                isBreakPoint = false;
            }
            
        }
        inFile.close();
    }
    
    // display bst
    cout << endl;
    corpusBST.display();  
    
    return 0;
}
