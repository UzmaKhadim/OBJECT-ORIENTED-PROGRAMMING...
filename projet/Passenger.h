#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
using namespace std;

/* ===================== PASSENGER ===================== */
class Passenger {
protected:
    string id, name;

public:
    Passenger(string i, string n);

    virtual string type() const = 0;

    string getId() const;
    string getName() const;
};

/* ===================== ECONOMY ===================== */
class EconomyPassenger : public Passenger {
public:
    EconomyPassenger(string i, string n);

    string type() const override;
};

/* ===================== BUSINESS ===================== */
class BusinessPassenger : public Passenger {
public:
    BusinessPassenger(string i, string n);

    string type() const override;
};

/* ===================== FIRST CLASS ===================== */
class FirstClassPassenger : public Passenger {
public:
    FirstClassPassenger(string i, string n);

    string type() const override;
};

#endif
