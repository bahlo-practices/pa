/* 
 * File:   Frame.h
 *
 * Created on 11. April 2013, 14:21
 */

#ifndef FRAME_H
#define	FRAME_H

#include <iostream>
#include <ctime>

const int xMax = 1000; // Zeichen pro Frame-Zeile
const int yMax = 1000; // Zeilen pro Frame

class Frame {
public:
    enum color {
        black = '.', white = '*'
    };
    Frame();
    Frame(int x, int y);
    void put_point(int x, int y); // Punkt im Frame speichern 
    void reset(); // Frame leeren
    void show() const; // Frame auf die Konsole ausgeben 
    void frame_dump() const;
    bool on_frame(int x, int y) const; // "Clipping"
private:
    char frame[xMax][yMax];
};

std::ostream& operator<<(std::ostream& os, const Frame* fr);

#endif	/* FRAME_H */

