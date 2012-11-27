/* 
 * File:   mp3Tag.h
 * Author: jw
 *
 * Created on 24. November 2012, 14:56
 */

#ifndef MP3TAG_H
#define	MP3TAG_H

#include <string>
#include <vector>

using namespace std;

class mp3Tag {
public:
    class Invalid{};
    enum Genre { Rock=1, Jazz, Pop, Klassik, Reggae };
    
    mp3Tag();
    mp3Tag(string interpret, string titel, double dauer, bool kopierschutz, Genre g);
    mp3Tag(string interpret, string titel, int minuten, int sekunden, bool kopierschutz, Genre g);
    
    void printall();
    void setkopierschutz(bool value);
    bool check();
    
    string interpret( )    const { return i; }
    string titel( ) const { return t; }
    double dauer( )     const { return d; }
    bool kopierschutz() const { return true; }
    Genre genre() const {return g;}
    int minuten() const {return m;}
    int sekunden() const {return s;}

    
private:
    string i;
    string t;
    double d;
    bool k;
    Genre g;
    int m;
    int s;
    
};

const mp3Tag& default_mp3Tag( );


#endif	/* MP3TAG_H */

