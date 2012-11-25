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
    enum Genre { Rock=1, Jazz, Pop, Klassik, Reggae };
    
    mp3Tag();
    mp3Tag(string interpret, string titel, double dauer, bool kopierschutz, Genre g);
    
    void printall();
    void setkopierschutz(bool value);
    //void populate(mp3Tag item);
    
    string interpret( )    const { return i; }
    string titel( ) const { return t; }
    double dauer( )     const { return d; }
    bool kopierschutz() const { return true; }
    Genre genre() const {return g;}

    
private:
    string i;
    string t;
    double d;
    bool k;
    Genre g;
    
};

const mp3Tag& default_mp3Tag( );


#endif	/* MP3TAG_H */

