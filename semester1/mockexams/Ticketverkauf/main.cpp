/* 
 * File:   main.cpp
 * Author: arne
 *
 * Created on 31. Januar 2013, 15:26
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Theatre.h"
#include "Ticket.h"

using namespace std;

int main(int argc, char** argv) {
    try 
    {
        Theatre theater = Theatre();
        
        // Populate
        int seatCount = 0;
        srand(time(0));
        do{
            int row = rand() % 9 + 1;
            int seat = rand() % 14 + 1;
            if(!theater.sellTicket(Ticket(row, seat, 0.0, false)))
                continue;
            else
                seatCount ++;
        } while (seatCount < 50);
        
        theater.printSeats();
        
        // Sort by price and output
        cout << endl << "Nach Preis sortiert:" << endl;
        theater.sortByPrice();
        theater.printSoldTickets();
        
        // Sort by seat and output
        cout << endl << "Nach Sitz sortiert:" << endl;
        theater.sortBySeat();
        theater.printSoldTickets();

        return 0;
    }
    catch (exception &e) 
    {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Ein Fehler ist aufgetreten" << endl;
        return 2;
    }
}

