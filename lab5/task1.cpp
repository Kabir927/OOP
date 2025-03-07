#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
    int id;
    string address;
    string* ownerName;

public:
    Apartment(int id, string addr, string owner) {
        this->id = id;
        this->address = addr;
        this->ownerName = new string(owner);
    }

    Apartment(const Apartment &other) {
        this->id = other.id;
        this->address = other.address;
        this->ownerName = new string(*other.ownerName);
    }

    ~Apartment() {
        delete ownerName;
    }

    void display() const {
        cout << "ID: " << id << ", Address: " << address << ", Owner: " << *ownerName << endl;
    }

    void setOwnerName(const string& newOwner) {
        *ownerName = newOwner;
    }
};

int main() {
    Apartment apt1(101, "123 Main St", "John Doe");
    Apartment apt2 = apt1;

    apt1.display();
    apt2.display();

    apt2.setOwnerName("Jane Smith");

    apt1.display();
    apt2.display();

    return 0;
}