#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include "Exception.h"

using namespace std;

class Airline
{
private:
    vector<Flight*> flights;
    vector<Passenger*> passengers;
    vector<Ticket*> tickets;

    bool isRegisteredPassenger(string pid);

public:

    // Flight
    void addFlight();
    void listFlights();
    void removeFlight();
    void searchFlight();

    // Passenger
    void registerPassenger();
    void removePassenger();
    void listPassengers();

    // Booking
    void bookTicket();
    void cancelTicket();
    void passengerBookingDetails();   // <-- properly declared as member

    // Reports
    void occupancyReport();
    void report();

    // File Handling
    void save();
    void saveState();
    void loadState();
};

#endif
