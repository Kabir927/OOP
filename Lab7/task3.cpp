#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string ticketID;
    string passengerName;
    float price;
    string date;
    string destination;

public:
    Ticket(string id, string name, float p, string d, string dest) 
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved successfully." << endl;
    }

    virtual void cancel() {
        cout << "Ticket cancelled successfully." << endl;
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(string id, string name, float p, string d, string dest, string airline, string flight, string seat) 
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(string id, string name, float p, string d, string dest, string train, string coach, string time) 
        : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        cout << "Seat auto-assigned in " << coachType << " coach." << endl;
        Ticket::reserve();
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(string id, string name, float p, string d, string dest, string company, string seat) 
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout << "Last-minute refund processed for seat " << seatNumber << "." << endl;
        Ticket::cancel();
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(string id, string name, float p, string d, string dest, string artist, string v, string seat) 
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight("F001", "John Doe", 299.99, "2025-04-15", "New York", "Delta", "DL123", "Economy");
    TrainTicket train("T001", "Jane Smith", 49.99, "2025-04-10", "Chicago", "TR456", "First", "08:30 AM");
    BusTicket bus("B001", "Mike Brown", 19.99, "2025-04-05", "Boston", "Greyhound", "14A");
    ConcertTicket concert("C001", "Alice Green", 89.99, "2025-05-20", "Los Angeles", "Taylor Swift", "Staples Center", "VIP");

    flight.reserve();
    train.reserve();
    bus.reserve();
    concert.reserve();

    flight.displayTicketInfo();
    train.displayTicketInfo();
    bus.displayTicketInfo();
    concert.displayTicketInfo();

    bus.cancel();

    return 0;
}