#include <iostream>
#include "mbooking.h"
#include <string>

MovieBooking ::MovieBooking() : Booking()
{
    this->movieName = "";
}
MovieBooking ::MovieBooking(string name, string cnic, string gender, string phoneNo, string movieName) : Booking(name, cnic, gender, phoneNo)
{
    this->movieName = movieName;
}

string MovieBooking ::getMovieName()
{
    return movieName;
}

MovieBooking :: ~MovieBooking(){}

//Overriding of function
void MovieBooking ::showConfirmedStatus()
{
    cout << "Booking for " << movieName << " successfully confirmed ! " << endl;
}