#include "Passenger.h"

/* ===================== PASSENGER ===================== */

Passenger::Passenger(string i, string n)
{
    id = i;
    name = n;
}

string Passenger::getId() const
{
    return id;
}

string Passenger::getName() const
{
    return name;
}

/* ===================== ECONOMY ===================== */

EconomyPassenger::EconomyPassenger(string i, string n)
    : Passenger(i, n)
{
}

string EconomyPassenger::type() const
{
    return "Economy";
}

/* ===================== BUSINESS ===================== */

BusinessPassenger::BusinessPassenger(string i, string n)
    : Passenger(i, n)
{
}

string BusinessPassenger::type() const
{
    return "Business";
}

/* ===================== FIRST CLASS ===================== */

FirstClassPassenger::FirstClassPassenger(string i, string n)
    : Passenger(i, n)
{
}

string FirstClassPassenger::type() const
{
    return "FirstClass";
}
