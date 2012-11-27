/* 
 * File:   mp3Tag.cpp
 * 
 * Created on 24. November 2012, 14:56
 */

#include <iostream>
#include "mp3Tag.h"

using namespace std;

const mp3Tag& default_mp3Tag() { 
    static const mp3Tag defmp3Tag("Max Mustermann", "Mustersong", 2,59, true, mp3Tag::Rock);
    return defmp3Tag;
}

mp3Tag::mp3Tag() 
    :i(default_mp3Tag().interpret()),
            t(default_mp3Tag().titel()),
        d(default_mp3Tag().dauer()),
        k(default_mp3Tag().kopierschutz()),
        g(default_mp3Tag().genre())
{}

mp3Tag::mp3Tag(string interpret, string titel, double dauer, bool kopierschutz, Genre genre)
        :i(interpret),
        t(titel),
        d(dauer),
        k(kopierschutz),
        g(genre)
        {if (!check()) throw Invalid();}

mp3Tag::mp3Tag(string interpret, string titel, int minuten, int sekunden, bool kopierschutz, Genre genre)
        :i(interpret),
        t(titel),
        m(minuten),
        s(sekunden),
        k(kopierschutz),
        g(genre)
        {if (!check()) throw Invalid();}

void mp3Tag::printall(){
    cout<<"Interpret:\t"<<i<<endl;
    cout<<"Titel:\t\t"<<t<<endl;
    cout<<"Dauer:\t\t"<<m<<","<<s<<endl;
    
    string out (" ");
    switch(g){
        case 1:
            out="Rock";
            break;
        case 2:
            out="Jazz";
            break;
        case 3:
            out="Pop";
            break;
        case 4:
            out="Klassik";
            break;
        case 5:
            out="Reggea";
            break;
    }
    
    cout<<"Genre:\t\t"<<out<<endl;
    if(k==true){
        cout<<"Titel ist kopiergeschuetzt"<<endl;
        cout<<"--------------------------------"<<endl;
    }
    else{
        cout<<"Titel ist nicht kopiergeschuetzt"<<endl;
        cout<<"--------------------------------"<<endl;
    }
}

void mp3Tag::setkopierschutz(bool value){
    if(value==true){
        k=true;
    }
    if(value==false){
        k=false;
    }
}

bool mp3Tag::check(){
    if (m<0) return false;
    if(t.length() <= 0) return false;
    if (i.length() <= 0) return false; 
    if (s<0 || s>59) return false;
    return true;
}
