/* 
 * File:   mp3TagList.h
 * Author: jw
 *
 * Created on 26. November 2012, 14:24
 */

#ifndef MP3TAGLIST_H
#define	MP3TAGLIST_H

#include "mp3Tag.h"
#include <vector>

class mp3TagList {
public:
    
    mp3TagList();
    void populate(mp3Tag in);
    void printfirst();
    void printall();

private:
    
    vector<mp3Tag> list;

};

#endif	/* MP3TAGLIST_H */

