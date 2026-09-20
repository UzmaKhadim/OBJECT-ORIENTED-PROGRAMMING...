#include "Exception.h"

/* ================= FLIGHT FULL EXCEPTION ================= */

const char* FlightFullException::what()
{
    return "Flight is full! No seats available.";
}

/* ================= INVALID CANCELLATION EXCEPTION ================= */

const char* InvalidCancellationException::what()
{
    return "Ticket cancellation failed! Ticket not found.";
}
