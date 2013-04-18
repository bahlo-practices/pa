/* 
 * File:   Frame.cpp
 * 
 * Created on 11. April 2013, 14:21
 */

#include "Frame.h"

Frame::Frame() : frame() {
    reset();
};

void Frame::show() const {
    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            cout << frame[j][yMax - i - 1];
        }
        cout << "\n";
        //cout << "Zeile. " <<i <<"\n";
    }
}

void Frame::frame_dump() const {
    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            cout.put(frame[j][yMax - i - 1]);
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

ostream& operator<<(ostream& os, const Frame* fr) {
    fr->show();
    return os;
};