#ifndef BOOKINGSYS_H
#define BOOKINGSYS_H

#include "mbooking.h"
using namespace std;

class BookingSystem : public MovieBooking
{
private:
    float ticketPrice;

public:
    BookingSystem();
    BookingSystem(string name, string cnic, string gender, string phoneNo, string mName, float ticketPrice, bool status);
    void setTicketPrice(float ticketPrice);
    float getTicketPrice();
    ~BookingSystem();
    // Overridding
    void showConfirmedStatus();
};
#endif