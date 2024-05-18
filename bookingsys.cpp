#include <iostream>
#include "bookingsys.h"
#include <string>

BookingSystem ::BookingSystem() : MovieBooking()
{
    this->ticketPrice = 0.0;
}
BookingSystem ::BookingSystem(string name, string cnic, string gender, string phoneNo, string mName, float ticketPrice, bool status = true) : MovieBooking(name, cnic, gender, phoneNo, mName)
{
    this->ticketPrice = ticketPrice;
    if (status)
    // Polymorphism
        this->showConfirmedStatus();
}

void BookingSystem ::setTicketPrice(float ticketPrice)
{
    this->ticketPrice = ticketPrice;
}
float BookingSystem ::getTicketPrice()
{
    return ticketPrice;
}

BookingSystem :: ~BookingSystem(){}

// Overridding
void BookingSystem ::showConfirmedStatus()
{
    cout << "\n\t\t\t\t\tBooking for " << movieName << " successfully confirmed ! " << endl;
}