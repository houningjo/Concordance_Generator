//
//  main.cpp
//  pro4
//
//  Created by Ning Hou on 11/29/17.
//  Copyright © 2017 Ning Hou. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include "LinkedList.h"
#include "ConcordanceData.h"
#include "BST.h"
#include "BST.cpp"
#include "BNode.h"
using namespace std;

const string STOPWORDS = "/Users/ninghou/Documents/pro4/pro4/pro4/stopword.txt";
const int CONTEXT_SIZE = 5;

//vector<string> getVector(string filename){
//    vector<string> data;
//    ifstream inFile;
//    inFile.open(filename);
//    string temp;
//    while(!inFile.eof()){
//        inFile >> temp;
//        data.push_back(temp);
//        cout << "temp: " << temp << endl;
//    }
//    inFile.close();
//
//    return data;
//}

string getBeforeContext(vector<string> data, int index){
    string before = "";
    
    for(int i = 0; i < CONTEXT_SIZE; i++){
        if((index - i) > 0){
            before += data[i] + " ";
        }
    }
    //cout << "before: " << before << endl;
    return before;
}

string getAfterContext(vector<string> data, int index){
    string after = "";
    int len = index + 6;
    
    // if the index + 6 (for the 5 words) is more than the size of the
    // vector then select the vector size
    if (len > data.size()) len = data.size();
    
    // from index + 1 (to get only the context) to the len
    // get all the five words to the right
    for (int i = index; i < len; i++){
        after += data[i] + " ";
    }
    
    return after;
}


string setKey(string key){
    string newKey = "";
    if(!key.empty()){

        for(int i = 0; i < key.length(); i++){
            if(!ispunct(key[i]) ||
               (( i < key.length() && i > 0) &&
               (key.compare(i, 1, "'") == 0 ||
               key.compare(i, 1, "-") == 0))){
                newKey += key[i];
            }
        }
        
        transform(newKey.begin(), newKey.end(), newKey.begin(), ::tolower);
    }
    return newKey;
}

bool isNumber(string key){
    bool isNum = true;
    
    for(int i = 0; i < key.length(); i++){
        if(!isdigit(key[i])){
            isNum = false;
        }
    }
    return isNum;
    
}

void printVector(vector<string> data){
    for(int i = 0; i < data.size(); i++ ){
        cout << data[i] << " ";
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    // stopwords BST
    BST<string> stopwordsBST;

    ifstream stopfile;
    stopfile.open(STOPWORDS);
    string stopTemp;

    while(!stopfile.eof()){
        stopfile >> stopTemp;
        stopwordsBST.insert(stopTemp);
    }
    //cerr << "got here: stopwords" << endl;
    stopfile.close();
    
    
    // creates a nonstop word bst
    BST<ConcordanceData> corpusBST;
    string corpusFile;
    cin >> corpusFile;
    
    ifstream inFile(corpusFile);
    
    if(inFile.is_open()){
        string word;
        vector<string> data;
        
        int counter = 0;
        int index = 0;
        bool isBreakPoint = false;
        
        // read first 11 words
        while(inFile >> word){
            //cerr << "got point A" << endl;
            data.push_back(word);
            counter++;
            
            if(counter == 11 || inFile.eof())
                break;
        }
        //cerr << "got point B" << endl;
        // set break pointer flag
        if(data.size() > 0){
            isBreakPoint = true;
        }
        
        while(isBreakPoint == true){
            // general case: key is not in stopwords
            if(stopwordsBST.find(data[index]) == nullptr){
                //cerr << "got point C" << endl;
                string keyword = setKey(data[index]);
                //cerr << "keyword: " << keyword << endl;
                // check if it's a number
                if(!isNumber(keyword)){
                    string before = getBeforeContext(data, index);
                    string after = getAfterContext(data, index);
                    //cerr << "before: " << before << endl;
                    //cerr << "after: " << after << endl;
                    
                    ConcordanceData cd(keyword, before, after);
                    // exists in corpusBST
                    if(corpusBST.find(cd)){
                        corpusBST.find(cd)->item.update(before, after);
                    }
                    // new in corpusBST
                    else{
                        corpusBST.insert(cd);
                    }
                    
                    // test bst
                    //corpusBST.display();
                }
                
                //cerr << "vector data before: " << endl;
                printVector(data);
                
                // update index
                if(index >= CONTEXT_SIZE){
                    // if it's not then end of the file
                    // read next word, erase index 0,
                    // add next word to the end
                    if(!inFile.eof()){
                        inFile >> word;
                        data.erase(data.begin());
                        data.push_back(word);
                        
                        // test vector
                        //printVector(data);
                    }
                    // file at the end
                    // process the leftovers in vector
                    else{
                        index++;
                    }
                }
                // update index
                else{
                    index++;
                    //cerr << "index: " << index << endl;
                }
                
                // switch isBreakpoint flag
                if(index > data.size()){
                    isBreakPoint = false;
                }
                
                //cerr << "is break point: " << isBreakPoint << endl;
            }
            else{
                index++;
            }
           
        }
        
         inFile.close();
        // display bst
        cout << endl;
        //cout << setw(100);
        corpusBST.display();
    }
    
    
    return 0;
}
