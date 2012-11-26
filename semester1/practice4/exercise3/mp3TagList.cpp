/* 
 * File:   mp3TagList.cpp
 * 
 * Created on 26. November 2012, 14:24
 */

#include "mp3TagList.h"
#include "mp3Tag.h"
#include <iostream>

using namespace std;

mp3TagList::mp3TagList() {
}

void mp3TagList::populate(mp3Tag in){
    list.push_back(in);
}

void mp3TagList::printfirst(){
   list.at(0).printall();
}

void mp3TagList::printall(){
    for(int i=0; i<list.size();i++){
        list.at(i).printall();
    }
}

