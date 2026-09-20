#include "Flight.h"

/* ===================== FLIGHT ===================== */

Flight::Flight(string f, string o, string d, string dt, int s)
{
    flightNo = f;
    origin = o;
    destination = d;
    date = dt;
    totalSeats = s;
    availableSeats = s;
    revenue = 0;
}

bool Flight::bookSeat()
{
    if (availableSeats > 0)
    {
        availableSeats--;
        return true;
    }
    return false;
}

void Flight::addRevenue(double r)
{
    revenue += r;
}

string Flight::getFlightNo() const
{
    return flightNo;
}

int Flight::getAvailableSeats() const
{
    return availableSeats;
}

int Flight::getTotalSeats() const
{
    return totalSeats;
}

double Flight::getRevenue() const
{
    return revenue;
}

double Flight::occupancy() const
{
    int booked = totalSeats - availableSeats;
    if (totalSeats == 0) return 0;
    return (booked * 100.0) / totalSeats;
}

ostream& operator<<(ostream& out, const Flight& f)
{
    out << f.flightNo << " | " << f.origin << " -> " << f.destination
        << " | Seats: " << f.availableSeats
        << " | Revenue: " << f.revenue;
    return out;
}

/* ===================== DOMESTIC ===================== */

DomesticFlight::DomesticFlight(string f, string o, string d, string dt, int s)
    : Flight(f, o, d, dt, s)
{
}

string DomesticFlight::type() const
{
    return "Domestic";
}

double DomesticFlight::baseFare() const
{
    return 5000;
}

void DomesticFlight::show() const
{
    cout << "\n[Domestic Flight]\n";
    cout << flightNo << " | " << origin << " -> " << destination;
    cout << " | Date: " << date;
    cout << " | Seats: " << availableSeats << "/" << totalSeats;
    cout << " | Revenue: " << revenue;
    cout << " | Occupancy: " << occupancy() << "%\n";
}

/* ===================== INTERNATIONAL ===================== */

InternationalFlight::InternationalFlight(string f, string o, string d, string dt, int s)
    : Flight(f, o, d, dt, s)
{
}

string InternationalFlight::type() const
{
    return "International";
}

double InternationalFlight::baseFare() const
{
    return 20000;
}

void InternationalFlight::show() const
{
    cout << "\n[International Flight]\n";
    cout << flightNo << " | " << origin << " -> " << destination;
    cout << " | Date: " << date;
    cout << " | Seats: " << availableSeats << "/" << totalSeats;
    cout << " | Revenue: " << revenue;
    cout << " | Occupancy: " << occupancy() << "%\n";
}

/* ===================== CHARTER ===================== */

CharterFlight::CharterFlight(string f, string o, string d, string dt, int s, string h)
    : Flight(f, o, d, dt, s)
{
    holder = h;
}

string CharterFlight::type() const
{
    return "Charter";
}

double CharterFlight::baseFare() const
{
    return 30000;
}

void CharterFlight::show() const
{
    cout << "\n[Charter Flight]\n";
    cout << flightNo << " | " << origin << " -> " << destination;
    cout << " | Holder: " << holder;
    cout << " | Date: " << date;
    cout << " | Seats: " << availableSeats << "/" << totalSeats;
    cout << " | Revenue: " << revenue;
    cout << " | Occupancy: " << occupancy() << "%\n";
}
