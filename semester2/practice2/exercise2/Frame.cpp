/* 
 * File:   Frame.cpp
 * 
 * Created on 11. April 2013, 14:21
 */

#include <sstream>

#include "Frame.h"

Frame::Frame() : frame() {
    reset();
};

void Frame::show() const {
    /* Alte version
    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            std::cout << frame[j][yMax - i - 1];
        }
        std::cout << "\n";
        //cout << "Zeile. " <<i <<"\n";
    }*/
    
    std::stringstream output;
    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            output << frame[j][yMax - i - 1];
        }
        output << "\n";
        //cout << "Zeile. " <<i <<"\n";
    }
    std::cout << output.str();
}

void Frame::frame_dump() const {
    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            std::cout.put(frame[j][yMax - i - 1]);
        }
    }
}

void Frame::reset() {
    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            frame[j][i] = black;
        }
    }
}

void Frame::put_point(int x, int y) {
    frame[x][y] = white;
}

bool Frame::on_frame(int x, int y) const {
    if (x >= xMax || x < 0) return false;
    if (y >= yMax || y < 0) return false;

    return true;
}

std::ostream& operator<<(std::ostream& os, const Frame* fr) {
    fr->show();
    return os;
};