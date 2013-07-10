//
//  main.cpp
//  Erlrouter
//
//  Created by Arne Bahlo on 09.07.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//  ToDo:
//  - Give out the sorted words (first nomen, then acronyms, alphabetically)
//  - Write to "Index.txt"
//

#include <iostream>
#include <fstream>
#include <map>
#include <locale>
#include <stdexcept>
#include "Word.h"
#include "Nomen.h"
#include "Akronym.h"

// Helper functions
void addWordToMap(std::multimap<std::string, Word*> &map, Word &word) {
    std::multimap<std::string, Word*>::iterator it = map.find(word.getWord());
    if(it != map.end()) {
        std::list<int> lineNumbers = word.getLineNumbers();
        int firstLineNumber(0);
        for(std::list<int>::iterator it = lineNumbers.begin(); it != lineNumbers.end(); ++it) {
            firstLineNumber = *it;
        }
        it->second->addLineNumber(firstLineNumber);
    } else {
        map.insert(std::pair<std::string, Word*>(word.getWord(), &word));
    }
}

void printMap(std::multimap<std::string, Word*> &map) {
    for(std::map<std::string, Word*>::iterator it = map.begin();it != map.end();++it)
        it->second->print();
}

bool isNomen(const std::string &word) {
    char tempChar(' ');
    char firstChar = word.at(0);
    int letterCount(0);
    for(int i = 0;i < word.length();++i) {
        tempChar = word.at(i);
        if(isalpha(tempChar)) {
            letterCount++;
        } else {
            return false;
        }
    }
    return letterCount >= 4 && firstChar> 64 && firstChar < 91;
}

bool isAkronym(const std::string &word) {
    char tempChar(' ');
    int capitalLetters(0);
    int letterCount(0);
    for(int i = 0;i < word.length();++i) {
        tempChar = word.at(i);
        if(tempChar > 64 && tempChar < 91) {
            // Capital letters
            capitalLetters++;
            letterCount++;
        } else if(tempChar > 96 && tempChar < 123) {
            letterCount++;
        } else {
            return false;
        }
    }
    return capitalLetters >= 2;
}

int main(int argc, const char * argv[]) {
    try {
        setlocale(LC_ALL, "");
        std::locale loc;
        std::multimap<std::string, Word*> words;

        // Define vars
        std::string filename = "Erlrouter.txt";
        char tempChar(0);
        std::string tempWord("");
        int lineCounter(1);

        // Open file
        std::ifstream book(filename.c_str());
        if(!book.is_open()) throw std::runtime_error("Die Datei \"" + filename + "\" konnte nicht geöffnet werden!");

        // Go through file and read in char-by-char
        do {
            tempChar = book.get();
            if(tempChar == '\n') lineCounter++;
            if(isspace(tempChar, loc)) {
                // Write word
                if(tempWord.length() > 0) {
                    if(isNomen(tempWord)) {
                        // We have a nomen!
                        addWordToMap(words, *new Nomen(tempWord, lineCounter));
                    } else if(isAkronym(tempWord)) {
                        // We have an acronym!
                        addWordToMap(words, *new Akronym(tempWord, lineCounter));
                    }
                }
                tempWord = "";
            } else if(isalpha(tempChar, loc)) {
                tempWord = tempWord + tempChar;
            }
        } while(book.good());
        book.close(); // Close file
        
        printMap(words);

        return 0;
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Ein unbekannter Fehler trat auf." << std::endl;
    }
}

