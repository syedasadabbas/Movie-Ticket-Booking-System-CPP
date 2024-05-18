#ifndef TICKET_H
#define TICKET_H

class Ticket
{
private:
    static int total;
    int serial;

public:
    Ticket();
    int getTicket();
    ~Ticket();
};
#endif