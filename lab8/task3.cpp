
#include <iostream>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

int main() {
    Vector2D v1(2, 3);
    Vector2D v2(1, 4);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector2D sum = v1 + v2;
    cout << "v1 + v2 = " << sum << endl;

    Vector2D diff = v1 - v2;
    cout << "v1 - v2 = " << diff << endl;

    Vector2D scaled = v1 * 2.5;
    cout << "v1 * 2.5 = " << scaled << endl;

    double dot = dotProduct(v1, v2);
    cout << "Dot product of v1 and v2: " << dot << endl;

    return 0;
}
