/* 
 * File:   Theatre.cpp
 * Author: arne
 * 
 * Created on 31. Januar 2013, 15:27
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Theatre.h"
#include "Ticket.h"

using namespace std;

Theatre::Theatre() : tickets(0), numberOfTickets(150) 
{
    int count = 0;
    for( int row = 1; row <= 10; row++ ) 
    {
        for ( int seat = 1; seat <= 15; seat++) 
        {
            int price = 10.0; // Standardpreis
            price = price + (10 - row); // Preiserhöhung für Reihe
            if ( seat > 8 )
                price = price + (15 - seat) * 0.5;
            else if ( seat < 8 )
                price = price + (9 - seat) * 0.5;
            else 
                price = price + 8 * 0.5;
            price = price + (10 - seat);
            tickets.push_back(Ticket(row, seat, price, false));
            count++;
        }
    }
}

bool Theatre::sellTicket(Ticket _ticket) 
{
    if(_ticket.getRow() < 1 || _ticket.getRow() > 15 || _ticket.getSeat() < 1 || _ticket.getSeat() > 10) return false;
    int index = (_ticket.getRow() * 15 - 15) + _ticket.getSeat() - 1;
    if ( tickets.at(index).isOccupied() ) 
        return false;
    else 
        tickets.at(index).setOccupied(true);
        return true;
}

int const Theatre::soldTickets()
{
    int soldTickets = 0;
    for ( int count = 0; count < 150; count++ )
        if( tickets.at(count).isOccupied() ) soldTickets++;
    return soldTickets;
}

double const Theatre::totalRevenous()
{
    double total = 0.0;
    for ( int count = 0; count < 150; count++ ) 
        if( tickets.at(count).isOccupied() ) total += tickets.at(count).getPrice();
    return total;
}

void const Theatre::printSeats() 
{
    cout << "Verkaufte Tickets: " << Theatre::soldTickets() << endl;
    cout << "Gesamteinnahmen: " << Theatre::totalRevenous() << endl;
    cout << "Saalplan:" << endl;
    int count = 0;
    for ( int row = 0; row <= 10; row ++ )
    {
        if ( row == 0 )
        {
            cout << setw(3) << left << "";
            for ( int i = 1; i <= 15; i++ )
                cout << setw(3) << i;
            cout << endl;
        }
        else
        {    
            cout << setw(3) << left << row;
            for ( int seat = 1; seat <= 15; seat++ )
            {
                string sign = "-";
                if ( tickets.at(count).isOccupied() ) sign = "x";
                cout << setw(3) << left << sign;
                count++;
            }
            cout << endl;
        }
    }
}

void Theatre::sortByPrice() 
{
    int toSort = tickets.size() - 1;
    int indexOfSmallestElement = 0;
    while(toSort > 0) 
    {
        for ( int i = 1; i <= toSort; i++ )
        {
            if( tickets.at(i).getPrice() < tickets.at(indexOfSmallestElement).getPrice())
                indexOfSmallestElement = i;
        }
        swap(tickets.at(indexOfSmallestElement), tickets.at(toSort));
        toSort--;
    }
}

void const Theatre::printSoldTickets() 
{
    for ( int i = 0; i < tickets.size(); i++ )
        if(tickets.at(i).isOccupied()) tickets.at(i).print();
}

void Theatre::sortBySeat()
{
    for ( int i = tickets.size(); i > 1; i-- )
    {
        for ( int j = 0; j < i - 1; j++)
        {
            if( tickets.at(j).getSeat() > tickets.at(j+1).getSeat()) 
            {
                swap(tickets.at(j), tickets.at(j+1));
            }
        }
    }
}