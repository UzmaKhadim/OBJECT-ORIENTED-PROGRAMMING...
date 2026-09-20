#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

/* ===================== TICKET ===================== */
class Ticket {
public:
    string pid, fid;
    int seat;
    double fare;

    Ticket(string p, string f, int s, double fa);

    friend ostream& operator<<(ostream& out, const Ticket& t);

    bool operator==(const Ticket& t);
};

#endif
