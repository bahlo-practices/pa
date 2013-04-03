/* 
 * File:   Theatre.h
 * Author: arne
 *
 * Created on 31. Januar 2013, 15:27
 */

#ifndef THEATRE_H
#define	THEATRE_H

#include <vector>
#include "Ticket.h"

using namespace std;

class Theatre {
public:
    Theatre();
    bool sellTicket(Ticket _ticket);
    void sortByPrice();
    void sortBySeat();
    int const soldTickets();
    double const totalRevenous();
    void const printSoldTickets();
    void const printSeats();
    
    const int numberOfTickets;
private:
    vector<Ticket> tickets;
};

#endif	/* THEATRE_H */

