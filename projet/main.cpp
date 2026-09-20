#include <iostream>

#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include "Exception.h"
#include "Airline.h"

using namespace std;

int main()
{
    Airline system;
    int choice;

    system.loadState();

    while (true)
    {
        cout << "\n========== AIRLINE MANAGEMENT SYSTEM ==========\n";
        cout << "  1.  Add Flight\n";
        cout << "  2.  List Flights\n";
        cout << "  3.  Search Flight\n";
        cout << "  4.  Remove Flight\n";
        cout << "  5.  Register Passenger\n";
        cout << "  6.  List Passengers\n";
        cout << "  7.  Remove Passenger\n";
        cout << "  8.  Book Ticket\n";
        cout << "  9.  Cancel Ticket\n";
        cout << "  10. Passenger Booking Details\n";
        cout << "  11. Occupancy Report\n";
        cout << "  12. Revenue Report\n";
        cout << "  13. Save System State\n";
        cout << "  0.  Exit\n";
        cout << "================================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
                case 1:  system.addFlight();                break;
                case 2:  system.listFlights();              break;
                case 3:  system.searchFlight();             break;
                case 4:  system.removeFlight();             break;
                case 5:  system.registerPassenger();        break;
                case 6:  system.listPassengers();           break;
                case 7:  system.removePassenger();          break;
                case 8:  system.bookTicket();               break;
                case 9:  system.cancelTicket();             break;
                case 10: system.passengerBookingDetails();  break;
                case 11: system.occupancyReport();          break;
                case 12: system.report();                   break;
                case 13: system.saveState();                break;

                case 0:
                    system.saveState();
                    cout << "Exiting system. Goodbye!\n";
                    return 0;

                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
        catch (FlightFullException& e)
        {
            cout << "ERROR: " << e.what() << endl;
        }
        catch (InvalidCancellationException& e)
        {
            cout << "ERROR: " << e.what() << endl;
        }
    }

    return 0;
}
