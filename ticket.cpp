#include "ticket.h"

Ticket ::Ticket()
{
    total++;
    serial = total;
}

int Ticket ::getTicket()
{
    return this->serial;
}

Ticket :: ~Ticket(){}

int Ticket::total = 10300;