#ifndef MBOOKING_H
#define MBOOKING_H

#include "booking.h"

class MovieBooking : public Booking
{
public:
    string movieName;
    Booking booking = Booking();
    MovieBooking();
    MovieBooking(string name, string cnic, string gender, string phoneNo, string movieName);
    string getMovieName();
    ~MovieBooking();
    void showConfirmedStatus();
};
#endif
