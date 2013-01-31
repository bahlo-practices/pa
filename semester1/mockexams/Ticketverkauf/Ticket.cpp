/* 
 * File:   Ticket.cpp
 * Author: arne
 * 
 * Created on 31. Januar 2013, 15:28
 */

#include <iostream>

#include "Theatre.h"
#include "Ticket.h"

Ticket::Ticket() : row(0), seat(0), price(0.0), occupied(false) {
}

Ticket::Ticket(int row, int seat, double price, bool occupied) : row(row), seat(seat), price(price), occupied(occupied) {
}

void const Ticket::print() {
    cout << "Reihe " << row << ", Platz " << seat << endl;
    cout << "Preis: " << price << ", ";
    if(occupied)
        cout << "besetzt";
    else
        cout << "nicht besetzt";
    cout << endl;
}

// Getter
bool const Ticket::isOccupied() 
{
    return occupied;
}
int const Ticket::getRow()
{
    return row;
}
int const Ticket::getSeat()
{
    return seat;
}
double const Ticket::getPrice()
{
    return price;
}

// Setter
void Ticket::setOccupied(bool _occupied)
{
    occupied = _occupied;
}
void Ticket::setRow(int _row)
{
    row = _row;
}
void Ticket::setSeat(int _seat)
{
    seat = _seat;
}
void Ticket::setPrice(double _price)
{
    price = _price;
}