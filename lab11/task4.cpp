
#include <iostream>
#include <string>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {
};

class QueryTimeoutException : public DatabaseException {
};

template<typename T>
class DatabaseConnector {
private:
    string dbName;
    bool isConnected;

public:
    DatabaseConnector(const string& name) : dbName(name), isConnected(false) {}

    void connect() {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        }
        isConnected = true;
    }

    T query(const string& queryStr) {
        if (!isConnected) {
            throw DatabaseException();
        }
        if (dbName == "slow_db") {
            throw QueryTimeoutException();
        }
        return T();
    }
};

int main() {
    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        DatabaseConnector<int> db1("invalid_db");
        db1.connect();
    }
    catch(const ConnectionFailedException&) {
        cout << "Caught ConnectionFailedException - what(): " << DatabaseException().what() << endl;
    }

    try {
        cout << "\nAttempting to connect to slow_db..." << endl;
        DatabaseConnector<int> db2("slow_db");
        db2.connect();
        db2.query("SELECT * FROM table");
    }
    catch(const DatabaseException&) {
        cout << "Caught a general DatabaseException - what(): " << DatabaseException().what() << endl;
    }

    return 0;
}