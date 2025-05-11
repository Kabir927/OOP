
#include <iostream>
using namespace std;

class InvalidTemperatureException : public std::exception {};

template<typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15) {
        throw InvalidTemperatureException();
    }
    return (celsius * 9/5) + 32;
}

int main() {
    try {
        cout << "Attempting to convert -300C..." << endl;
        double result = convertToFahrenheit(-300.0);
    }
    catch(const InvalidTemperatureException&) {
        cout << "Caught InvalidTemperatureException - what(): std::exception" << endl;
    }
    
    try {
        double result = convertToFahrenheit(25.0);
        cout << "25C = " << result << "F" << endl;
    }
    catch(const InvalidTemperatureException&) {
        cout << "Caught InvalidTemperatureException - what(): std::exception" << endl;
    }
    
    return 0;
}
