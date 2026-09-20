#include "Ticket.h"

/* ===================== TICKET ===================== */

Ticket::Ticket(string p, string f, int s, double fa)
{
    pid = p;
    fid = f;
    seat = s;
    fare = fa;
}

/* ================= OPERATOR OVERLOADING ================= */

ostream& operator<<(ostream& out, const Ticket& t)
{
    out << "Passenger ID: " << t.pid
        << " | Flight ID: " << t.fid
        << " | Seat: " << t.seat
        << " | Fare: " << t.fare;
    return out;
}

bool Ticket::operator==(const Ticket& t)
{
    return (pid == t.pid && fid == t.fid);
}
