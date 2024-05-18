#include <iostream>
#include "booking.h"
#include <string>

Booking ::Booking()
{
    ticket = new Ticket();
    name = "";
    cnic = "";
    gender = "male";
    phoneNo = "";
}
Booking ::Booking(string name, string cnic, string gender, string phoneNo)
{
    ticket = new Ticket();
    this->name = name;
    this->cnic = cnic;
    this->gender = gender;
    this->phoneNo = phoneNo;
}

int Booking ::getSerial()
{
    return ticket->getTicket();
}

string Booking ::getName()
{
    return name;
}

string Booking ::getCnic()
{
    return cnic;
}
string Booking ::getGender()
{
    return gender;
}

string Booking ::getPhoneNumber()
{
    return phoneNo;
}

void Booking ::setName(string name)
{
    this->name = name;
}

void Booking ::setCnic(string cnic)
{
    this->cnic = cnic;
}
void Booking ::setGender(string gender)
{
    this->gender = gender;
}

void Booking ::setPhoneNumber(string phoneNo)
{
    this->phoneNo = phoneNo;
}

Booking :: ~Booking(){}

// Over-riding of function
void Booking ::showConfirmedStatus()
{
    cout << "Your Booking Confirmed! " << endl;
}