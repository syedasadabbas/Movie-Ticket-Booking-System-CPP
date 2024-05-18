#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "bookingsys.h"
#include "bookingsys.cpp"
#include "mbooking.cpp"
#include "booking.cpp"
#include "ticket.cpp"
// function signature
string chooseMovie(string n);
float TicketPrice();

// user define type
BookingSystem *setTicket()
{
    string name, cnic, gender, phoneNo, mName, selectMovie;
    float ticketPrice;
    bool status = true;
    cout << endl;
    cin.ignore(1);
    cout << "\n\t\t\t\t\tENTER YOUR NAME : ";
    getline(cin, name);
    cout << "\t\t\t\t\tENTER YOUR GENDER : ";
    cin >> gender;
    cout << "\t\t\t\t\tENTER YOUR CNIC# - *(13 digits with no space)* : ";
    cin >> cnic;
    cout << "\t\t\t\t\tENTER YOUR PHONE# - *(11 digits with no space)* : ";
    cin >> phoneNo;
    mName = chooseMovie(selectMovie);
    ticketPrice = TicketPrice();

    return new BookingSystem(name, cnic, gender, phoneNo, mName, ticketPrice, status);
}

void bookTicket(vector<BookingSystem *> *bookingList)
{
    system("CLS");
    char choose;

    cout << "\n\n\t\t\t\t*****BOOK YOUR TICKET HERE*****\n\n\n"
         << endl;
    bookingList->push_back(setTicket());
    cout << "\n\t\t\t\t\tDo you want to book more tickets? (y/n) : ";
    cin >> choose;
    if (choose == 'y' || choose == 'Y')
    {
        bookTicket(bookingList);
    }
}

bool viewTicket(vector<BookingSystem *> bookingList)
{
    system("CLS");

    cout << "\n\n\n\t\t\t\t\t*****BOOKED TICKETS*****" << endl;
    if (bookingList.size() <= 0)
    {
        cout << "\n\n\n\t\t\t\t\tN O   R E C O R D   E X I S T S " << endl;
        return false;
    }
    else
    {
        cout << "\n\t\t\t\t\t**TICKET RESERVER INFO**\n\n";

        // read from bookingList
        for (int i = 0; i < bookingList.size(); i++)
        {
            cout << "******************************************************************************************************************************************\n";
            cout << "\tCNIC # : " << bookingList.at(i)->getCnic() << "\t\tGENDER : " << bookingList.at(i)->getGender() << "\t\t\tCUSTOMER NAME : " << bookingList.at(i)->getName() << "\n"
                 << i + 1 << "\tTICKET # : TCK-" << bookingList.at(i)->getSerial() << "\t\tTICKET PRICE : " << bookingList.at(i)->getTicketPrice() << "\t\tMOVIE NAME : " << bookingList.at(i)->getMovieName() << "\n\tPHONE # : " << bookingList.at(i)->getPhoneNumber() << endl;
        }
        cout << "******************************************************************************************************************************************\n";
    }
    return true;
}

void deleteTicket(vector<BookingSystem *> *bookingList)
{
    system("CLS");
    int serial;
    char choose;
    cout << "\n\n\n\t\t\t\t\t\tDELETION OF TICKET\n\n\n\n"
         << endl;
    if (viewTicket(*bookingList))
    {
        cout << "\n\t\t\t\tEnter Serial no of ticket to delete : ";
        cin >> serial;
        cout << "\n\n\n\t\t\t\tDO YOU REALLY WANT TO DELETE YOUR TICKETS? (y/n) : ";
        cin >> choose;
        if (choose == 'y' || choose == 'Y')
        {
            char opt;
            bookingList->erase(bookingList->begin() + serial - 1);
            cout << "\n\n\n\n\t\t\t\tTHE TICKET HAS BEEN DELETED SUCCESSFULLY! " << endl;
            viewTicket(*bookingList);
            cout << "\n\t\t\t\tDO YOU WANT TO DELETE MORE TICKETS? (y/n) : ";
            cin >> opt;
            if (opt == 'y' || opt == 'Y')
            {
                deleteTicket(bookingList);
            }
        }
        else
        {
            cout << "\n\t\t\t\tYOUR TICKET HAS NOT BEEN DELETED!";
        }
    }
}
void searchBooking(vector<BookingSystem *> bookingList)
{
    system("CLS");

    string name;
    bool flag = false;
    Booking b;
    int n;

    cout << "\n\t\t\t\t\t1. SEARCH BY NAME\n\t\t\t\t\t2. SEARCH BY CNIC #\n\t\t\t\t\t3. SEARCH BY PHONE #\n\n\t\t\t\t\tENTER YOUR CHOICE : ";
    cin >> n;
    if (n == 1)
    {
        cin.ignore(1);
        // search from bookingList
        cout << "\n\t\t\t\t\tEnter Name : ";
        getline(cin, name);
        for (int i = 0; i < bookingList.size(); i++)
        {
            if (bookingList.at(i)->getName() == name)
            {
                cout << "\n\t\t\t\t**************************************************************\n";
                cout << "\n\t\t\t\t\t" << i + 1 << " : " << bookingList.at(i)->getName() << " has reserved " << bookingList.at(i)->getMovieName() << "\n\t\t\t\t\tTicket Number is : TCK-" << bookingList.at(i)->getSerial() << endl;
                cout << "\n\t\t\t\t**************************************************************\n";
                flag = true;
                break;
            }
        }
    }
    else if (n == 2)
    {
        // search from bookingList
        cout << "\n\t\t\t\t\tENTER CNIC # : ";
        cin >> name;
        for (int i = 0; i < bookingList.size(); i++)
        {
            if (bookingList.at(i)->getCnic() == name)
            {
                cout << "\n\t\t\t\t**************************************************************\n";
                cout << "\n\t\t\t\t\t" << i + 1 << " : " << bookingList.at(i)->getName() << " has reserved " << bookingList.at(i)->getMovieName() << "\n\t\t\t\t\tTicket Number is : TCK-" << bookingList.at(i)->getSerial() << endl;
                cout << "\n\t\t\t\t**************************************************************\n";
                flag = true;
                break;
            }
        }
    }
    else if (n == 3)
    {
        // search from bookingList
        cout << "\n\t\t\t\t\tENTER PHONE # : ";
        cin >> name;
        for (int i = 0; i < bookingList.size(); i++)
        {
            if (bookingList.at(i)->getPhoneNumber() == name)
            {
                cout << "\n\t\t\t\t**************************************************************\n";
                cout << "\n\t\t\t\t\t" << i + 1 << " : " << bookingList.at(i)->getName() << " has reserved " << bookingList.at(i)->getMovieName() << "\n\t\t\t\t\tTicket Number is : TCK-" << bookingList.at(i)->getSerial() << endl;
                cout << "\n\t\t\t\t**************************************************************\n";
                flag = true;
                break;
            }
        }
    }

    if (!flag)
    {
        cout << "\n\t\t\t\t\tNO RECORD FOUND! \n";
    }
    char enter;
    cout << "\n\t\t\t\tDO YOU WANT TO SEARCH ANOTHER BOOKING? (y/n) : ";
    cin >> enter;
    if (enter == 'y' || enter == 'Y')
    {
        searchBooking(bookingList);
    }
}

string chooseMovie(string selectMovie)
{
    system("CLS");
    int y, a, b, c;
    cout << "\n\n\t\t\t\t\t\t*****MOVIE LIST*****\n\n\n"
         << endl;
    cout << "\n\n\t\t\t\t\t1. PAKISTANI MOVIES\n\t\t\t\t\t2. HOLLYWOOD MOVIES\n\t\t\t\t\t3. ANIMATED MOVIES (KID's ENTERTAINMENT)\n"
         << endl;
    cout << "\n\n\t\t\t\t\tEnter Your Choice : ";
    cin >> y;
    if (y == 1)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t*****PAKISTANI MOVIES*****\n\n\n"
             << endl;
        cout << "\t\t\t\t\t1. NA MALOOM AFRAD\n\t\t\t\t\t2. WRONG NUMBER\n\t\t\t\t\t3. KARACHI SE LAHORE\n\t\t\t\t\t4. PUNJAB NAHI JAUNGI\n\t\t\t\t\t5. JAWANI PHIR NAHI AANI\n\t\t\t\t\t6. LAHORE SE AAGAY\n\t\t\t\t\t7. WAR\n\t\t\t\t\t8. ACTOR IN LAW\n"
             << endl;
        cout << "\n\t\t\t\t\tENTER SERIAL NUMBER OF MOVIE NAME TO SELECT MOVIE : ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            selectMovie = "NA MALOOM AFRAD";
            break;
        }
        case 2:
        {
            selectMovie = "WRONG NUMBER";
            break;
        }
        case 3:
        {
            selectMovie = "KARACHI SE LAHORE";
            break;
        }
        case 4:
        {
            selectMovie = "PUNJAB NAHI JAUNGI";
            break;
        }
        case 5:
        {
            selectMovie = "JAWANI PHIR NAHI AANI";
            break;
        }
        case 6:
        {
            selectMovie = "LAHORE SE AAGAY";
            break;
        }
        case 7:
        {
            selectMovie = "WAR";
            break;
        }
        case 8:
        {
            selectMovie = "ACTOR IN LAW";
            break;
        }
        default:
        {
            cout << "\n\t\t\t\t\tSomething went wrong!\n"
                 << endl;
            chooseMovie(selectMovie);
            break;
        }
        }
    }
    else if (y == 2)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t*****HOLLYWOOD MOVIES*****\n\n\n"
             << endl;
        cout << "\n\t\t\t\t\t1. WORLD WAR-Z\n\t\t\t\t\t2. PASSENGERS\n\t\t\t\t\t3. FAST AND FURIOUS 8\n\t\t\t\t\t4. MISSION IMPOSSIBLE - ROGUE NATION\n\t\t\t\t\t5. ROYAL CASSINO\n\t\t\t\t\t6. BLOOD DIAMOND\n\t\t\t\t\t7. CHARLIE IN THE CHOCOLATE FACTORY\n\t\t\t\t\t8. JURASSIC WORLD\n\t\t\t\t\t9. RAID REDEMPTION\n\t\t\t\t\t10. JOHN WICK - CHAPTER 4\n\t\t\t\t\t11. DUNKIRK\n\t\t\t\t\t12. LUCY\n\n"
             << endl;
        cout << "\n\t\t\t\t\tENTER SERIAL NUMBER OF MOVIE NAME TO SELECT MOVIE : ";
        cin >> b;
        switch (b)
        {
        case 1:
        {
            selectMovie = "WORLD WAR-Z";
            break;
        }
        case 2:
        {
            selectMovie = "PASSENGERS";
            break;
        }
        case 3:
        {
            selectMovie = "FAST AND FURIOUS 8";
            break;
        }
        case 4:
        {
            selectMovie = "MISSION IMPOSSIBLE - ROGUE NATION";
            break;
        }
        case 5:
        {
            selectMovie = "ROYAL CASSINO";
            break;
        }
        case 6:
        {
            selectMovie = "BLOOD DIAMOND";
            break;
        }
        case 7:
        {
            selectMovie = "CHARLIE IN THE CHOCOLATE FACTORY";
            break;
        }
        case 8:
        {
            selectMovie = "JURASSIC WORLD";
            break;
        }
        case 9:
        {
            selectMovie = "\n\t\t\t\tRAID REDEMPTION";
            break;
        }
        case 10:
        {
            selectMovie = "JOHN WICK - CHAPTER 4";
            break;
        }
        case 11:
        {
            selectMovie = "DUNKIRK";
            break;
        }
        case 12:
        {
            selectMovie = "LUCY";
            break;
        }
        default:
        {
            cout << "\n\t\t\t\t\tSomething went wrong!\n"
                 << endl;
            chooseMovie(selectMovie);
            break;
        }
        }
    }
    else if (y == 3)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t*****ANIMATED MOVIES*****\n\n\n"
             << endl;
        cout << "\n\t\t\t\t\t1. HOW TO TRAIN YOUR DRAGON 3\n\t\t\t\t\t2. ALLAHYAR\n\t\t\t\t\t3. MINNIONS\n\t\t\t\t\t4. THE EXPENDIBLES\n\t\t\t\t\t5. SNOW WHITE\n\t\t\t\t\t6. STUART LITTLE\n\t\t\t\t\t7. MOWGLI\n\t\t\t\t\t8. ALLADIN\n"
             << endl;
        cout << "\n\t\t\t\t\tENTER SERIAL NUMBER OF MOVIE NAME TO SELECT MOVIE : ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            selectMovie = "HOW TO TRAIN YOUR DRAGON 3";
            break;
        }
        case 2:
        {
            selectMovie = "ALLAHYAR";
            break;
        }
        case 3:
        {
            selectMovie = "MINNIONS";
            break;
        }
        case 4:
        {
            selectMovie = "THE EXPENDIBLES";
            break;
        }
        case 5:
        {
            selectMovie = "SNOW WHITE";
            break;
        }
        case 6:
        {
            selectMovie = "STUART LITTLE";
            break;
        }
        case 7:
        {
            selectMovie = "MOWGLI";
            break;
        }
        case 8:
        {
            selectMovie = "ALLADIN";
            break;
        }
        default:
        {
            cout << "\n\t\t\t\t\tSomething went wrong!\n"
                 << endl;
            chooseMovie(selectMovie);
            break;
        }
        }
    }
    return selectMovie;
}

void movieList()
{
    system("CLS");
    int y, a, b, c, x;
    cout << "\n\n\t\t\t\t\t\t*****MOVIE LIST*****\n\n\n"
         << endl;
    cout << "\n\n\t\t\t\t\t1. PAKISTANI MOVIES\n\t\t\t\t\t2. HOLLYWOOD MOVIES\n\t\t\t\t\t3. ANIMATED MOVIES (KID's ENTERTAINMENT)n"
         << endl;
    cout << "\n\n\t\t\t\t\tEnter Your Choice : ";
    cin >> y;
    if (y == 1)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t*****PAKISTANI MOVIES*****\n\n\n"
             << endl;
        cout << "\t\t\t\t\t1. NA MALOOM AFRAD\n\t\t\t\t\t2. WRONG NUMBER\n\t\t\t\t\t3. KARACHI SE LAHORE\n\t\t\t\t\t4. PUNJAB NAHI JAUNGI\n\t\t\t\t\t5. JAWANI PHIR NAHI AANI\n\t\t\t\t\t6. LAHORE SE AAGAY\n\t\t\t\t\t7. WAR\n\t\t\t\t\t8. ACTOR IN LAW\n"
             << endl;
        cout << "\t\t\t\t\tPress 1 to go back or Press any key to proceed : ";
        cin >> x;
        if (x == 1)
        {
            movieList();
        }
    }
    else if (y == 2)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t*****HOLLYWOOD MOVIES*****\n\n\n"
             << endl;
        cout << "\n\t\t\t\t\t1. WORLD WAR-Z\n\t\t\t\t\t2. PASSENGERS\n\t\t\t\t\t3. FAST AND FURIOUS 8\n\t\t\t\t\t4. MISSION IMPOSSIBLE - ROGUE NATION\n\t\t\t\t\t5. ROYAL CASSINO\n\t\t\t\t\t6. BLOOD DIAMOND\n\t\t\t\t\t7. CHARLIE IN THE CHOCOLATE FACTORY\n\t\t\t\t\t8. JURASSIC WORLD\n\t\t\t\t\t9. RAID REDEMPTION\n\t\t\t\t\t10. JOHN WICK - CHAPTER 4\n\t\t\t\t\t11. DUNKIRK\n\t\t\t\t\t12. LUCY\n\n"
             << endl;
        cout << "\t\t\t\t\tPress 1 to go back or Press any key to proceed : ";
        cin >> x;
        if (x == 1)
        {
            movieList();
        }
    }
    else if (y == 3)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t*****ANIMATED MOVIES*****\n\n\n"
             << endl;
        cout << "\n\t\t\t\t\t1. HOW TO TRAIN YOUR DRAGON 3\n\t\t\t\t\t2. ALLAHYAR\n\t\t\t\t\t3. MINNIONS\n\t\t\t\t\t4. THE EXPENDIBLES\n\t\t\t\t\t5. SNOW WHITE\n\t\t\t\t\t6. STUART LITTLE\n\t\t\t\t\t7. MOWGLI\n\t\t\t\t\t8. ALLADIN\n"
             << endl;
        cout << "\t\t\t\t\tPress 1 to go back or Press any key to proceed : ";
        cin >> x;
        if (x == 1)
        {
            movieList();
        }
    }
}
float TicketPrice()
{
    int price[3] = {2000, 1500, 1000};
    int index = 0;
    cout << "\n\n\t\t\t\t\t*****SELECT TICKET PRICE*****\n\n\n"
         << endl;
    cout << "\n\t\t\t\t\t1. PREMIUM SCREEN (2000 PKR)\n\t\t\t\t\t2. GOLD SCREEN (1500 PKR)\n\t\t\t\t\t3. SILVER SCREEN (1000 PKR)\n\n\t\t\t\t\tENTER YOUR CHOICE HERE : ";
    cin >> index;
    return price[index - 1];
}

int mainMenu(vector<BookingSystem *> *bookingList)
{
    system("cls");
    cout << "\n\t\t\t\t\t---------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\t*** WELCOME  TO  MOVIE  TICKET  BOOKING  SYSTEM ***" << endl;
    cout << "\n\t\t\t\t\t---------------------------------------------------\n\n"
         << endl;
    int choice;
    char choose = 'y';
    while (choose == 'y' || choose == 'Y')
    {
        cout << "\t\t\t\t\t1. BOOK TICKET \n\t\t\t\t\t2. VIEW TICKET \n\t\t\t\t\t3. DELETE TICKET \n\t\t\t\t\t4. MOVIE LIST \n\t\t\t\t\t5. SEARCH BOOKED TICKETS \n\t\t\t\t\t6. EXIT " << endl;
        cout << "\n\n\t\t\t\t\tPress the number from above menu to Open the desired Option \n\n\n\t\t\t\t\tEnter Your Choice : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            bookTicket(bookingList);
            break;
        }
        case 2:
        {
            viewTicket(*bookingList);
            break;
        }
        case 3:
        {
            deleteTicket(bookingList);
            break;
        }
        case 4:
        {
            movieList();
            break;
        }
        case 5:
        {
            searchBooking(*bookingList);
            break;
        }
        case 6:
        {
            cout << "\n\n\t\t\t\t\tT H E    E N D \n\n";
            return 0;
            break;
        }
        default:
            cout << "\n\t\t\t\t\tSOMETHING WENT WRONG!\n"
                 << endl;
            system("pause");
            mainMenu(bookingList);
        }

        cout << "\n\t\t\t\t\tDO YOU WANT TO PERFORM MORE OPTIONS?\n\t\t\t*** PRESS (y) to go to MAIN MENU or PRESS (n) to EXIT PROGRAM *** : ";
        cin >> choose;
        if (choose == 'y' || choose == 'Y')
        {
            mainMenu(bookingList);
        }
        else
        {
            cout << "\n\n\t\t\t\t\tT H E    E N D \n\n";
            return 0;
        }
        return 0;
    }
}

int main()
{
    try
    {
        system("cls");
        vector<BookingSystem *> bookingList;
        fstream textFile;
        textFile.open("save.txt", ios::in);
        char ch;
        string list[6];
        int index = 0;
        string word = "";

        // read from file and write in bookingList
        while (!textFile.eof())
        {
            textFile >> ch;
            if (ch == ',')
            {
                list[index++] = word;
                word = "";
            }
            else if (ch == '/')
            {
                word += " ";
            }
            else if (ch == ':')
            {
                if (index > 0)
                {
                    list[index++] = word;
                    word = "";
                    index = 0;
                    bookingList.push_back(new BookingSystem(list[0], list[1], list[2], list[3], list[4], stof(list[5]), false));
                }
            }
            else
            {
                word += ch;
            }
        }
        textFile.close();
        mainMenu(&bookingList);
        textFile.open("save.txt", ios::out);

        // read from bookingList and write in file
        for (int i = 0; i < bookingList.size(); i++)
        {
            BookingSystem *bs = bookingList.at(i);
            textFile << bs->getName() << "," << bs->getCnic() << "," << bs->getGender() << "," << bs->getPhoneNumber() << "," << bs->getMovieName() << "," << bs->getTicketPrice() << ":";
        }
        textFile.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}