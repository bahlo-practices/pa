//
//  main.cpp
//  Erlrouter
//
//  Created by Arne Bahlo on 09.07.13.
//  Copyright (c) 2013 Arne Bahlo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <locale>
#include <stdexcept>
#include <sstream>
#include <iterator>
#include "Word.h"
#include "Nomen.h"
#include "Akronym.h"

// Helper functions
typedef std::multimap<std::string, Word*> wordMap;
typedef std::pair<std::string, Word*> wordPair;

void addWordToMap(wordMap &map, Word &word) {
    wordMap::iterator it = map.find(word.getWord());
    if(it != map.end()) {
        std::list<int> lineNumbers = word.getLineNumbers();
        int firstLineNumber(0);
        for(std::list<int>::iterator it = lineNumbers.begin(); it != lineNumbers.end(); ++it) {
            firstLineNumber = *it;
        }
        it->second->addLineNumber(firstLineNumber);
    } else {
        map.insert(wordPair(word.getWord(), &word));
    }
}

void printMap(wordMap &map) {
    for(wordMap::iterator it = map.begin();it != map.end();++it)
        it->second->print();
}

void writeMap(wordMap &map, std::ostream &output) {
    for(wordMap::iterator it = map.begin();it != map.end();++it)
        output << it->second->getWord() << " " << it->second->getLineNumbersAsString() << std::endl;
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
        wordMap words;

        // Define vars
        std::string filename = "Erlrouter.txt";
        char tempChar(0);
        std::string tempWord("");
        int lineCounter(1);

        // Open file
        std::ifstream book(filename.c_str());
        if(!book.is_open()) throw std::runtime_error("Die Datei \"" + filename + "\" konnte nicht geöffnet werden!");
        
/*      Get line || get word
        std::string line("");
        std::istream_iterator<std::string> iiter(book);
        std::istream_iterator<std::string> eos;
        for(int i = 0;i<=2;++i)
            std::cout << *iiter++ << std::endl; // Read word
            getline(book, line);
        std::cout << line << std::endl;
*/

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
        
        // Write to Index.txt
        std::string outputFilename("Index.txt");
        std::ofstream index(outputFilename.c_str());
        writeMap(words, index);

        return 0;
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Ein unbekannter Fehler trat auf." << std::endl;
    }
}

