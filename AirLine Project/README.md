# Airline Management System (C++)

A console-based Airline Management System built with core OOP concepts:
inheritance, polymorphism, operator overloading, and custom exception
handling. Manages flights, passengers, ticket bookings/cancellations, and
basic revenue/occupancy reporting, with simple save/load to disk.

> **Note:** This is the corrected version of the project. The original
> version had a bug where the program would loop forever if you typed
> a non-number into a numeric prompt (see [Bug Fix](#bug-fix--infinite-loop) below).

---

## Features

- Add / list / search / remove flights (Domestic, International, Charter)
- Register / list / remove passengers (Economy, Business, First Class)
- Book and cancel tickets, with a 50% refund on cancellation
- Passenger booking details lookup
- Flight occupancy report and revenue report
- Save system state to `state.txt` on exit
- Input is validated — invalid text re-prompts instead of crashing or hanging

---

## Project Structure

```
AirlineManagementSystem_Fixed/
├── main.cpp          # Entry point: menu loop + try/catch
├── Airline.h/.cpp     # Controller class: owns flights, passengers, tickets
├── Flight.h/.cpp      # Flight base class + Domestic/International/Charter
├── Passenger.h/.cpp   # Passenger base class + Economy/Business/FirstClass
├── Ticket.h/.cpp      # A single booking record
├── Exception.h/.cpp   # Custom exceptions: FlightFullException, InvalidCancellationException
├── InputUtils.h        # readInt()/readDouble() — validated numeric input
└── README.md
```

### File-by-file summary

| File | Responsibility |
|---|---|
| `Passenger.h/.cpp` | Abstract `Passenger` base class + 3 concrete subtypes (Economy, Business, FirstClass). Each subtype just reports its own `type()`. |
| `Flight.h/.cpp` | Abstract `Flight` base class + 3 concrete subtypes (Domestic, International, Charter). Each overrides `baseFare()` and `show()` with its own pricing/printout. Also handles seat booking (`bookSeat()`) and revenue tracking. |
| `Ticket.h/.cpp` | A booking record (passenger id, flight id, seat, fare). Overloads `<<` for printing and `==` for finding a ticket during cancellation. |
| `Exception.h/.cpp` | Two lightweight custom exception classes, each with a `what()` message. |
| `Airline.h/.cpp` | The controller — owns `vector`s of flights, passengers and tickets, and implements every menu action (add/remove/search/book/cancel/report/save). |
| `main.cpp` | Shows the menu, reads the user's choice, and dispatches to the right `Airline` method inside a `try/catch` block. |
| `InputUtils.h` | `readInt()` / `readDouble()` — reads a number safely, re-prompting on bad input instead of leaving `cin` broken. |

---

## Building

Requires a C++11-capable compiler (g++, clang++, or MSVC).

```bash
g++ -std=c++11 *.cpp -o airline_system
```

## Running

```bash
./airline_system        # Linux / macOS
airline_system.exe      # Windows
```

You'll see a numbered menu — enter the number for the action you want, `0` to
save and exit.

---

## Exception Handling

Two custom exception classes are used instead of `std::exception`:

```cpp
class FlightFullException {
public:
    const char* what();   // "Flight is full! No seats available."
};

class InvalidCancellationException {
public:
    const char* what();   // "Ticket cancellation failed! Ticket not found."
};
```

- **`FlightFullException`** is thrown from `Airline::bookTicket()` when
  `Flight::bookSeat()` reports no seats remain.
- **`InvalidCancellationException`** is thrown from `Airline::cancelTicket()`
  when no ticket matches the given passenger/flight ID.

Both are caught in `main.cpp`, where the entire menu `switch` sits inside one
`try` block:

```cpp
try
{
    switch (choice) { /* ... */ }
}
catch (FlightFullException& e)          { cout << "ERROR: " << e.what(); }
catch (InvalidCancellationException& e)  { cout << "ERROR: " << e.what(); }
```

This keeps the low-level `Airline` methods focused on *detecting* problems
(by throwing), while `main()` decides how to *handle* them (by printing a
message and returning control to the menu loop) — the program never crashes
or exits unexpectedly because of a full flight or a bad cancellation.

---

## Bug Fix — Infinite Loop

**Symptom:** the program ran fine the first time through the menu, then
started looping continuously with no error message.

**Cause:** every numeric input (menu choice, seat count, seat number, etc.)
used raw `cin >> x`. If a user typed non-numeric text where a number was
expected, `cin` silently entered a permanent fail state and left the bad
text unread in the input buffer. From that point on, *every* future
`cin >> x` anywhere in the program — including the main menu's
`cin >> choice` — failed instantly without waiting for input, so the menu
loop spun forever.

**Fix:** added `InputUtils.h` with `readInt()` / `readDouble()`, which check
`cin.fail()` after every read and, on failure, call `cin.clear()` +
`cin.ignore(...)` to repair the stream and discard the bad input before
re-prompting. All five raw numeric reads (`main.cpp`'s menu choice;
`Airline.cpp`'s flight-type choice, total seats, passenger-type choice, and
seat number) now go through these functions.

A second, unrelated issue was also fixed: `Flight` and `Passenger` are
abstract base classes deleted through base-class pointers
(`delete flights[i];`), but neither had a `virtual` destructor — undefined
behavior. Both now declare `virtual ~ClassName() {}`.

---

## Known Limitations / Possible Extensions

- `loadState()` reads the saved-state file but doesn't yet reconstruct the
  flights/passengers/tickets vectors from it — `saveState()` writes
  everything needed to do this if you want to extend it.
- No duplicate-seat check when booking (two passengers could be assigned the
  same seat number on the same flight).
- No persistence format versioning — changing the save format will break
  older `state.txt` files.
