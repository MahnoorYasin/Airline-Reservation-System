# Airline-Reservation-System
# Airline Reservation System

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Installation & Compilation](#installation--compilation)
- [Usage](#usage)
- [Data Storage](#data-storage)
- [Future Improvements](#future-improvements)
- [Author](#author)

---

## Introduction

The **Airline Reservation System** is a C++ console application that allows users to book, cancel, and manage flight seat reservations. The system utilizes a **linked list** to store passenger details and an **array** to track seat availability. The project includes features like **searching for passengers, modifying reservations, displaying seat status**, and **saving/loading data from a file**.

---

## Features

- **Make Reservation**: Allows users to enter details and book a seat.
- **Cancel Reservation**: Removes a booking based on passenger ID.
- **Search Passenger**: Retrieves passenger details using an ID.
- **Change Reservation**: Modifies seat number for an existing reservation.
- **Print Passenger List**: Displays a formatted list of all passengers.
- **Reservation Report**: Shows reserved and available seats.
- **Seat Status**: Displays which seats are occupied and available.
- **File Storage**: Saves and loads data from a file (`reservations.txt`) to retain records.

---

## Technologies Used

- **Programming Language**: C++
- **Data Structures**:
  - **Linked List**: Stores passenger information dynamically.
  - **Array**: Manages seat availability.
- **File Handling**: Uses `fstream` to read/write reservation data to a text file.

---

## Project Structure

```
AirlineReservationSystem/
│── main.cpp          // Entry point of the program
│── airlines.h        // Header file (Class and function declarations)
│── airlines.cpp      // Implementation of reservation system
│── reservations.txt  // Data storage for reservations
│── README.md         // Project documentation
```

---

## How It Works
- **User Interface**: The system provides a menu-driven interface, allowing users to book, cancel, or manage reservations in an easy-to-use format.
- **Linked List**: The system uses a linked list to dynamically manage passenger information, ensuring efficient handling of reservations.
- **Seat Management**: An array is used to keep track of seat reservations, marking seats as either available or occupied based on user actions.
- **Data Persistence**: Data is saved after every change to ensure continuity, but the system does not load any existing data from previous sessions at startup.

---

## Installation & Compilation

### Prerequisites:
- A **C++ compiler** (G++ for Linux/Mac or MinGW for Windows).

### Compilation:
Use the following command to compile the program:

```sh
g++ main.cpp airlines.cpp -o airline_reservation
```

### Running the Program:
After compiling, execute:

```sh
./airline_reservation
```

---

## Usage

1. When the program starts, it displays a **menu**:
   ```
   *********************************************
           AIRLINE RESERVATION SYSTEM
   *********************************************

   MENU OPTIONS:
   [1] Make Reservation
   [2] Cancel Reservation
   [3] Search Passenger
   [4] Change Reservation
   [5] Print Passenger List
   [6] Print Reservation Report
   [7] Display Seat Status
   [8] Quit
   Option:
   ```
2. Enter the corresponding **option number** to perform an action.

### Example: Making a Reservation
- Choose option `[1] Make Reservation`
- Enter **first name, last name, ID, phone number, seat number, and meal preference**.
- If the seat is available, reservation is successful.

### Example: Canceling a Reservation
- Choose option `[2] Cancel Reservation`
- Enter **Passenger ID** to delete the reservation.

### Example: Searching for a Passenger
- Choose option `[3] Search Passenger`
- Enter **Passenger ID** to retrieve details.

### Example: Displaying Seat Status
- Choose option `[7] Display Seat Status`
- The system lists **available and reserved seats**.

---

## Data Storage

The system saves reservation data in `reservations.txt`. The file stores:
- Passenger **Full Name, ID, Phone Number, Seat Number, Meal Preference**.
- Seat availability data is also stored.

### Sample `reservations.txt` Output:
```
Full Name            ID    Phone Number     Seat Number    Meal Preference
-------------------------------------------------------------
John Doe            101   1234567890        5              Veg
Alice Smith        102   9876543210        12             Non-Veg
```


## Future Improvements

- **GUI Integration**: Develop a graphical user interface using **Qt**.
- **Multi-flight Support**: Allow reservations for multiple flights.
- **Database Integration**: Replace file storage with a **SQL database**.
- **Payment Processing**: Add an online payment option for seat booking.
