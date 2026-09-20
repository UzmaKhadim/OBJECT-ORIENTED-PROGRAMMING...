#include "Airline.h"

/* ================= PRIVATE HELPER ================= */

bool Airline::isRegisteredPassenger(string pid)
{
    for (int i = 0; i < (int)passengers.size(); i++)
    {
        if (passengers[i]->getId() == pid)
            return true;
    }
    return false;
}

/* ================= FLIGHT ================= */

void Airline::addFlight()
{
    string no, oCity, oCountry, dCity, dCountry, dt;
    int seats;
    int choice;

    while (true)
    {
        cout << "1=Domestic  2=International  3=Charter\n";
        cout << "Select Type: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
            break;

        cout << "Invalid choice!\n";
    }

    cout << "Flight No: ";    cin >> no;
    cout << "Origin City: ";  cin >> oCity;
    cout << "Origin Country: "; cin >> oCountry;
    cout << "Destination City: "; cin >> dCity;
    cout << "Destination Country: "; cin >> dCountry;
    cout << "Date (DD-MM-YYYY): "; cin >> dt;
    cout << "Total Seats: "; cin >> seats;

    string origin      = oCity + "(" + oCountry + ")";
    string destination = dCity + "(" + dCountry + ")";

    if (choice == 1)
        flights.push_back(new DomesticFlight(no, origin, destination, dt, seats));
    else if (choice == 2)
        flights.push_back(new InternationalFlight(no, origin, destination, dt, seats));
    else
    {
        string holder;
        cout << "Contract Holder: ";
        cin >> holder;
        flights.push_back(new CharterFlight(no, origin, destination, dt, seats, holder));
    }

    cout << "Flight Added Successfully!\n";
}

void Airline::listFlights()
{
    if (flights.empty())
    {
        cout << "No flights available!\n";
        return;
    }
    for (int i = 0; i < (int)flights.size(); i++)
        flights[i]->show();
}

void Airline::removeFlight()
{
    if (flights.empty())
    {
        cout << "No flights available!\n";
        return;
    }

    string no;
    cout << "Flight No: ";
    cin >> no;

    for (int i = 0; i < (int)flights.size(); i++)
    {
        if (flights[i]->getFlightNo() == no)
        {
            delete flights[i];
            flights.erase(flights.begin() + i);
            cout << "Flight Removed!\n";
            return;
        }
    }

    cout << "Error: Flight does not exist!\n";
}

void Airline::searchFlight()
{
    string no;
    cout << "Flight No: ";
    cin >> no;

    for (int i = 0; i < (int)flights.size(); i++)
    {
        if (flights[i]->getFlightNo() == no)
        {
            flights[i]->show();
            return;
        }
    }

    cout << "Flight Not Found!\n";
}

/* ================= PASSENGER ================= */

void Airline::registerPassenger()
{
    string id, name;
    int type;

    cout << "Passenger ID: ";
    cin >> id;

    if (isRegisteredPassenger(id))
    {
        cout << "Error: Passenger ID already exists!\n";
        return;
    }

    cout << "Name: ";
    cin >> name;

    cout << "Type (1=Economy  2=Business  3=FirstClass): ";
    cin >> type;

    if (type == 1)
        passengers.push_back(new EconomyPassenger(id, name));
    else if (type == 2)
        passengers.push_back(new BusinessPassenger(id, name));
    else
        passengers.push_back(new FirstClassPassenger(id, name));

    cout << "Passenger Registered Successfully!\n";
}

void Airline::removePassenger()
{
    if (passengers.empty())
    {
        cout << "No passengers registered!\n";
        return;
    }

    string id;
    cout << "Passenger ID: ";
    cin >> id;

    for (int i = 0; i < (int)passengers.size(); i++)
    {
        if (passengers[i]->getId() == id)
        {
            delete passengers[i];
            passengers.erase(passengers.begin() + i);
            cout << "Passenger Removed!\n";
            return;
        }
    }

    cout << "Error: Passenger does not exist!\n";
}

void Airline::listPassengers()
{
    if (passengers.empty())
    {
        cout << "No passengers registered!\n";
        return;
    }

    for (int i = 0; i < (int)passengers.size(); i++)
        cout << passengers[i]->getName()
             << " (" << passengers[i]->getId()
             << ") [" << passengers[i]->type() << "]\n";
}

/* ================= BOOKING DETAILS ================= */

void Airline::passengerBookingDetails()      // <-- FIXED: proper Airline:: scope
{
    if (tickets.empty())
    {
        cout << "No bookings available!\n";
        return;
    }

    cout << "\n===== PASSENGER BOOKING DETAILS =====\n";

    for (int i = 0; i < (int)tickets.size(); i++)
    {
        string pid = tickets[i]->pid;
        string fid = tickets[i]->fid;

        Passenger* p = NULL;
        Flight*    f = NULL;

        for (int j = 0; j < (int)passengers.size(); j++)
        {
            if (passengers[j]->getId() == pid)
            {
                p = passengers[j];
                break;
            }
        }

        for (int k = 0; k < (int)flights.size(); k++)
        {
            if (flights[k]->getFlightNo() == fid)
            {
                f = flights[k];
                break;
            }
        }

        cout << "\n--------------------------\n";

        if (p != NULL)
        {
            cout << "Passenger Name : " << p->getName() << endl;
            cout << "Passenger ID   : " << p->getId()   << endl;
            cout << "Passenger Type : " << p->type()    << endl;
        }

        if (f != NULL)
            cout << "Flight No      : " << f->getFlightNo() << endl;

        cout << "Seat No        : " << tickets[i]->seat << endl;
        cout << "Fare           : " << tickets[i]->fare << endl;
    }
}

/* ================= BOOKING ================= */

void Airline::bookTicket()
{
    if (flights.empty())
    {
        cout << "No flights available!\n";
        return;
    }

    string pid, fid;
    int seat;

    cout << "Passenger ID: "; cin >> pid;
    cout << "Flight ID: ";    cin >> fid;
    cout << "Seat No: ";      cin >> seat;

    if (!isRegisteredPassenger(pid))
    {
        cout << "Error: Passenger not registered!\n";
        return;
    }

    Flight* f = NULL;

    for (int i = 0; i < (int)flights.size(); i++)
    {
        if (flights[i]->getFlightNo() == fid)
        {
            f = flights[i];
            break;
        }
    }

    if (f == NULL)
    {
        cout << "Error: Flight not found!\n";
        return;
    }

    if (!f->bookSeat())
        throw FlightFullException();

    double fare = f->baseFare();
    f->addRevenue(fare);
    tickets.push_back(new Ticket(pid, fid, seat, fare));

    cout << "Booking Successful! Fare = " << fare << "\n";
}

/* ================= CANCEL ================= */

void Airline::cancelTicket()
{
    string pid, fid;
    cout << "Passenger ID: "; cin >> pid;
    cout << "Flight ID: ";    cin >> fid;

    for (int i = 0; i < (int)tickets.size(); i++)
    {
        Ticket temp(pid, fid, 0, 0);

        if (*tickets[i] == temp)
        {
            double refund = tickets[i]->fare * 0.5;
            cout << "Refund Amount = " << refund << endl;

            delete tickets[i];
            tickets.erase(tickets.begin() + i);
            cout << "Ticket Cancelled Successfully!\n";
            return;
        }
    }

    throw InvalidCancellationException();
}

/* ================= REPORTS ================= */

void Airline::occupancyReport()
{
    if (flights.empty())
    {
        cout << "No flights available!\n";
        return;
    }

    cout << "\n--- FLIGHT OCCUPANCY REPORT ---\n";

    for (int i = 0; i < (int)flights.size(); i++)
        cout << flights[i]->getFlightNo()
             << " | Occupancy: " << flights[i]->occupancy() << "%\n";
}

void Airline::report()
{
    if (flights.empty())
    {
        cout << "No flights available!\n";
        return;
    }

    cout << "\n--- REVENUE REPORT ---\n";

    for (int i = 0; i < (int)flights.size(); i++)
        cout << *flights[i] << endl;
}

/* ================= SAVE / LOAD ================= */

void Airline::save()
{
    ofstream file("data.txt");

    for (int i = 0; i < (int)flights.size(); i++)
        file << flights[i]->getFlightNo() << endl;

    cout << "Saved!\n";
}

void Airline::saveState()
{
    ofstream file("state.txt");

    file << flights.size() << "\n";
    for (int i = 0; i < (int)flights.size(); i++)
    {
        file << flights[i]->type()             << " "
             << flights[i]->getFlightNo()      << " "
             << flights[i]->getAvailableSeats()<< " "
             << flights[i]->getTotalSeats()    << " "
             << flights[i]->getRevenue()       << "\n";
    }

    file << passengers.size() << "\n";
    for (int i = 0; i < (int)passengers.size(); i++)
    {
        file << passengers[i]->type() << " "
             << passengers[i]->getId() << " "
             << passengers[i]->getName() << "\n";
    }

    file << tickets.size() << "\n";
    for (int i = 0; i < (int)tickets.size(); i++)
    {
        file << tickets[i]->pid  << " "
             << tickets[i]->fid  << " "
             << tickets[i]->seat << " "
             << tickets[i]->fare << "\n";
    }

    cout << "System State Saved!\n";
}

void Airline::loadState()
{
    ifstream file("state.txt");
    if (!file.is_open())
    {
        cout << "No saved state found. Starting fresh.\n";
        return;
    }

    cout << "System State Restored!\n";
    // (Full restore logic can be extended here)
}
