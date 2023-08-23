#include <bits/stdc++.h>
using namespace std;

class Guest
{
private:
    string name;
    int age;
    int price;

public:
    Guest(const string &name, int age) : name(name), age(age)
    {
        price = calculatePrice();
    }

    int calculatePrice()
    {
        if (age <= 2)
        {
            return 0;
        }
        else if (age < 18)
        {
            return 100;
        }
        else if (age < 60)
        {
            return 500;
        }
        else
        {
            return 300;
        }
    }

    int getPrice() const
    {
        return price;
    }

    string toString() const
    {
        return "Guest " + name + " (age: " + to_string(age) + ", price: INR " + to_string(price) + ")";
    }
};

class Ticket
{
private:
    vector<Guest> guests;
    int totalCharges;

public:
    Ticket() : totalCharges(0) {}

    void addGuest(const Guest &guest)
    {
        guests.push_back(guest);
        totalCharges += guest.getPrice();
    }

    void displayTicketDetails() const
    {
        for (const Guest &guest : guests)
        {
            cout << guest.toString() << endl;
        }
        cout << "Total Charges: INR " << totalCharges << endl;
    }
};

int main()
{
    int numGuests;
    cout << "Enter the number of guests: ";
    cin >> numGuests;
    cin.ignore();

    Ticket ticket;

    for (int i = 1; i <= numGuests; i++)
    {
        string name;
        int age;

        cout << "Enter the name of Guest " << i << ": ";
        getline(cin, name);

        cout << "Enter the age of Guest " << i << ": ";
        cin >> age;
        cin.ignore();

        Guest guest(name, age);
        ticket.addGuest(guest);
    }

    cout << "\nTicket Details:" << endl;
    ticket.displayTicketDetails();

    return 0;
}

// output

// Enter the number of guests: 5
// Enter the name of Guest 1: Ram
// Enter the age of Guest 1: 23
// Enter the name of Guest 2: ganesh
// Enter the age of Guest 2: 1
// Enter the name of Guest 3: seeta
// Enter the age of Guest 3: 20
// Enter the name of Guest 4: laxman
// Enter the age of Guest 4: 22
// Enter the name of Guest 5: dasrath
// Enter the age of Guest 5: 61

// Ticket Details:
// Guest Ram (age: 23, price: INR 500)
// Guest ganesh (age: 1, price: INR 0)
// Guest seeta (age: 20, price: INR 500)
// Guest laxman (age: 22, price: INR 500)
// Guest dasrath (age: 61, price: INR 300)
// Total Charges: INR 1800