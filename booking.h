#ifndef BOOKING_H
#define BOOKING_H

#include <cstring>
#include "ticket.h"

using namespace std;

class Booking
{
private:
    Ticket *ticket;
    string name;
    string cnic;
    string gender;
    string phoneNo;

public:
    Booking();
    Booking(string, string, string, string);
    int getSerial();
    string getName();
    string getCnic();
    string getPhoneNumber();
    string getGender();
    void setName(string);
    void setCnic(string);
    void setPhoneNumber(string);
    void setGender(string);
    ~Booking();
    // OVERRIDING
    void showConfirmedStatus();
};

#endif
