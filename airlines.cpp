#include "airlines.h"
#include <fstream>
#include <iomanip>

airlines::airlines()
{
    start = nullptr; // Initialize the linked list
    initializeSeats();
    load_from_file(); // Load data from file on initialization
}

void airlines::initializeSeats()
{
    for (int i = 0; i < size; i++)
    {
        seats[i] = 0; // All seats start as available
    }
}

void airlines::menu()
{
    char choice;
    do
    {
        cout << "\nMENU OPTIONS:\n";
        cout << "[1] Make Reservation\n";
        cout << "[2] Cancel Reservation\n";
        cout << "[3] Search Passenger\n";
        cout << "[4] Change Reservation\n";
        cout << "[5] Print Passenger List\n";
        cout << "[6] Print Reservation Report\n";
        cout << "[7] Display Seat Status\n";
        cout << "[8] Quit\n";
        cout << "Option: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            make_reservation();
            break;
        case '2':
            cancel_reservation();
            break;
        case '3':
            search_passenger();
            break;
        case '4':
            change_reservation();
            break;
        case '5':
            print_list();
            break;
        case '6':
            print_report();
            break;
        case '7':
            display_seats();
            break;
        case '8':
            save_to_file();
            cout << "Exiting... Data saved successfully. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '8');
}

bool airlines::is_unique_id(int id)
{
    node *temp = start;
    while (temp != nullptr)
    {
        if (temp->ID == id)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void airlines::make_reservation()
{
    node *temp = new node;
    int seat_num;

    cout << "Enter First Name: ";
    cin >> temp->fname;
    cout << "Enter Last Name: ";
    cin >> temp->lname;

    do
    {
        cout << "Enter ID: ";
        cin >> temp->ID;

        if (!is_unique_id(temp->ID))
        {
            cout << "ID already exists. Try again.\n";
        }
        else
        {
            break;
        }
    } while (true);

    cout << "Enter Phone Number: ";
    cin >> temp->phone_num;

    do
    {
        cout << "Enter Seat Number (1-" << size << "): ";
        cin >> seat_num;

        if (seat_num < 1 || seat_num > size || seats[seat_num - 1] == -1)
        {
            cout << "Invalid or already reserved seat. Try again.\n";
        }
        else
        {
            seats[seat_num - 1] = -1; // Reserve the seat
            temp->seat_num = seat_num;
            break;
        }
    } while (true);

    cout << "Meal Preference (Veg/Non-Veg/No Meal): ";
    cin >> temp->meal_pref;

    temp->next = start;
    start = temp;

    cout << "Reservation successful!\n";

    save_to_file(); // Save the reservation data immediately after making a reservation
}

void airlines::cancel_reservation()
{
    int id;
    cout << "Enter ID of the passenger to cancel reservation: ";
    cin >> id;

    node *temp = start;
    node *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->ID == id)
        {
            seats[temp->seat_num - 1] = 0; // Free the seat
            if (prev == nullptr)
            {
                start = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Reservation canceled successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Reservation not found.\n";
}

void airlines::search_passenger()
{
    int id;
    cout << "Enter Passenger ID to search: ";
    cin >> id;

    node *temp = start;
    while (temp != nullptr)
    {
        if (temp->ID == id)
        {
            cout << "Passenger Found: \n";
            cout << "Name: " << temp->fname << " " << temp->lname << "\n";
            cout << "Phone: " << temp->phone_num << "\n";
            cout << "Seat: " << temp->seat_num << "\n";
            cout << "Meal Preference: " << temp->meal_pref << "\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Passenger not found.\n";
}

void airlines::change_reservation()
{
    int id;
    cout << "Enter Passenger ID to change reservation: ";
    cin >> id;

    node *temp = start;
    while (temp != nullptr)
    {
        if (temp->ID == id)
        {
            cout << "Current Seat: " << temp->seat_num << "\n";
            seats[temp->seat_num - 1] = 0; // Free the old seat

            int new_seat;
            do
            {
                cout << "Enter New Seat Number (1-" << size << "): ";
                cin >> new_seat;

                if (new_seat < 1 || new_seat > size || seats[new_seat - 1] == -1)
                {
                    cout << "Invalid or already reserved seat. Try again.\n";
                }
                else
                {
                    seats[new_seat - 1] = -1; // Reserve the new seat
                    temp->seat_num = new_seat;
                    cout << "Reservation updated successfully!\n";
                    return;
                }
            } while (true);
        }
        temp = temp->next;
    }

    cout << "Passenger not found.\n";
}

void airlines::print_list()
{
    node *temp = start;

    if (temp == nullptr)
    {
        cout << "No reservations to display.\n";
        return;
    }

    ofstream file("reservations.txt");
    if (!file)
    {
        cout << "Error opening file for saving.\n";
        return;
    }

    // Write headers to the file
    file << left << setw(20) << "Full Name"
         << setw(15) << "ID"
         << setw(15) << "Phone Number"
         << setw(10) << "Seat Number"
         << setw(15) << "Meal Preference"
         << endl;

    // Write data to the file
    while (temp != nullptr)
    {
        string fullname = temp->fname + " " + temp->lname;
        file << left << setw(20) << fullname
             << setw(15) << temp->ID
             << setw(15) << temp->phone_num
             << setw(10) << temp->seat_num
             << setw(15) << temp->meal_pref
             << endl;

        temp = temp->next;
    }

    file.close();

    // Also print the data to console
    cout << "\nPassenger List:\n";
    cout << left << setw(20) << "Full Name"
         << setw(15) << "ID"
         << setw(15) << "Phone Number"
         << setw(10) << "Seat Number"
         << setw(15) << "Meal Preference"
         << endl;

    temp = start;
    while (temp != nullptr)
    {
        string fullname = temp->fname + " " + temp->lname;
        cout << left << setw(20) << fullname
             << setw(15) << temp->ID
             << setw(15) << temp->phone_num
             << setw(10) << temp->seat_num
             << setw(15) << temp->meal_pref
             << endl;

        temp = temp->next;
    }
}

void airlines::print_report()
{
    int reserved = 0, available = 0;

    for (int i = 0; i < size; i++)
    {
        if (seats[i] == -1)
        {
            reserved++;
        }
        else if (seats[i] == 0)
        {
            available++;
        }
    }

    cout << "\nReservation Report:\n";
    cout << "Total Seats: " << size << "\n";
    cout << "Reserved Seats: " << reserved << "\n";
    cout << "Available Seats: " << available << "\n";
}

void airlines::display_seats()
{
    cout << "\nSeat Status:\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Seat " << (i + 1) << ": ";
        if (seats[i] == -1)
        {
            cout << "Reserved\n";
        }
        else if (seats[i] == 0)
        {
            cout << "Available\n";
        }
    }
}

void airlines::save_to_file()
{
    ofstream file("reservations.txt", ios::out); // open the file for writing
    if (!file)
    {
        cout << "Error opening file for saving.\n";
        return;
    }

    // Print the header for the table
    file << left
         << setw(20) << "Full Name"
         << setw(5) << "ID"
         << setw(20) << "Phone Number"
         << setw(20) << "Seat Number "
         << setw(20) << "Meal Preference"
         << "\n";

    // Print a separator line for visual clarity
    file << "-------------------------------------------------------------"
         << "\n";

    // Save seat availability data
    for (int i = 0; i < size; i++)
    {
        file << seats[i] << " ";
    }
    file << "\n"; // End of seat availability data

    // Save reservation details (passenger information)
    node *temp = start;
    while (temp != nullptr)
    {
        file << left
             << setw(20) << temp->fname + " " + temp->lname // Full Name
             << setw(5) << temp->ID                        // ID
             << setw(20) << temp->phone_num                 // Phone Number
             << setw(20) << temp->seat_num                  // Seat Number
             << setw(20) << temp->meal_pref                 // Meal Preference
             << "\n";
        temp = temp->next;
    }

    file.close();
    cout << "Data saved to file successfully.\n";
}

void airlines::load_from_file()
{
    ifstream file("reservations.txt");
    if (!file)
    {
        cout << "Error opening file for loading or file does not exist.\n";
        return;
    }

    // Load seat availability data
    for (int i = 0; i < size; i++)
    {
        file >> seats[i];
    }

    // Load reservation data (passenger information)
    while (!file.eof())
    {
        node *temp = new node;

        file >> temp->fname >> temp->lname >> temp->ID >> temp->phone_num >> temp->seat_num >> temp->meal_pref;

        if (file.fail())
        {
            delete temp;
            break;
        }

        temp->next = start;
        start = temp;
    }

    file.close();
    cout << "Data loaded successfully.\n";
}

airlines::~airlines()
{
    while (start != nullptr)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}
