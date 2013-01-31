/* 
 * File:   Ticket.h
 * Author: arne
 *
 * Created on 31. Januar 2013, 15:28
 */

#ifndef TICKET_H
#define	TICKET_H

class Ticket {
public:
    Ticket();
    Ticket(int row, int seat, double price, bool occupied);
    bool const isOccupied();
    void const print();
    // Setter
    void setRow(int _row);
    void setSeat(int _seat);
    void setPrice(double _price);
    void setOccupied(bool _occupied);
    // Getter
    int const getRow();
    int const getSeat();
    double const getPrice();
private:
    int row;
    int seat;
    double price;
    bool occupied;
};

#endif	/* TICKET_H */

