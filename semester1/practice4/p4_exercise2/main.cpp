/* 
 * File:   main.cpp
 * Author: Johannes Wahl
 *
 * Created on 24. November 2012, 12:22
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>

using namespace std;

void backwards(string in){
    int length = in.length();
    for(int i=length-1;i>=0;i--){
           cout<<in[i];
    }
}

string sortieren(string in){
    vector<char> signs;
    vector<char> original;
    char temp=('a');
    int capital(0);
    int small(0);
    
   for(int i=0; i<in.length();i++){ //saves original string to compare
        temp=in[i];
        original.push_back(temp);
    }
        
    transform(in.begin(),in.end(),in.begin(),::towlower); //turn all capital characters to small ones
    
    for(int i=0; i<in.length();i++){ //save string with small characters
        temp=in[i];
        signs.push_back(temp);
    }
    
    for(int i=0; i<original.size(); i++){
     
    }
    
    for(int i=0; i<signs.size();i++){
        cout<<signs.at(i);
    }   
    
    return in;
}

int main() {
    
//    string input="test";
//    cout<<"Bitte Triple eingeben: ";
//    cin >> input;
//    backwards(input);
//    cout<<endl;
//    sortieren(input);
    
    char A = 'A';
    char a = 'a';
    int er= (int)a-(int)A;
    cout << er;
    
    
    return 0;
}

