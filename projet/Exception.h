#ifndef EXCEPTION_H
#define EXCEPTION_H

/* ================= CUSTOM EXCEPTIONS ================= */

class FlightFullException
{
public:
    const char* what();
};

class InvalidCancellationException
{
public:
    const char* what();
};

#endif
