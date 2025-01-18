#ifndef AIRLINES_H
#define AIRLINES_H

#include <iostream>
#include <string>

using namespace std;

const int size = 50; // Total number of seats

struct node
{
    string fname;     // First Name
    string lname;     // Last Name
    int ID;           // Passenger ID
    string phone_num; // Phone Number
    int seat_num;     // Seat Number
    string meal_pref; // Meal Preference
    node *next;       // Pointer to next node in the linked list
};

class airlines
{
private:
    node *start;     // Linked list of passengers
    int seats[size]; // Array for seat availability

    void initializeSeats();    // Initialize seat availability
    bool is_unique_id(int id); // Check if the ID is unique
    void save_to_file();       // Save data to a file
    void load_from_file();     // Load data from a file

public:
    airlines();                // Constructor
    ~airlines();               // Destructor
    void menu();               // Display menu options
    void make_reservation();   // Reserve a seat
    void cancel_reservation(); // Cancel a reservation
    void search_passenger();   // Search for a passenger by ID
    void change_reservation(); // Change reservation details
    void print_list();         // Print the passenger list
    void print_report();       // Print reservation report
    void display_seats();      // Display seat status
};

#endif
