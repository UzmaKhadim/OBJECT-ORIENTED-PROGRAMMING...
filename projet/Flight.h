#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
using namespace std;

/* ===================== FLIGHT ===================== */
class Flight {
protected:
    string flightNo, origin, destination, date;
    int totalSeats, availableSeats;
    double revenue;

public:
    Flight(string f, string o, string d, string dt, int s);

    virtual string type() const = 0;
    virtual double baseFare() const = 0;
    virtual void show() const = 0;

    bool bookSeat();
    void addRevenue(double r);

    string getFlightNo() const;
    int getAvailableSeats() const;
    int getTotalSeats() const;
    double getRevenue() const;

    double occupancy() const;

    friend ostream& operator<<(ostream& out, const Flight& f);
};

/* ===================== DOMESTIC ===================== */
class DomesticFlight : public Flight {
public:
    DomesticFlight(string f, string o, string d, string dt, int s);

    string type() const override;
    double baseFare() const override;
    void show() const override;
};

/* ===================== INTERNATIONAL ===================== */
class InternationalFlight : public Flight {
public:
    InternationalFlight(string f, string o, string d, string dt, int s);

    string type() const override;
    double baseFare() const override;
    void show() const override;
};

/* ===================== CHARTER ===================== */
class CharterFlight : public Flight {
private:
    string holder;

public:
    CharterFlight(string f, string o, string d, string dt, int s, string h);

    string type() const override;
    double baseFare() const override;
    void show() const override;
};

#endif
