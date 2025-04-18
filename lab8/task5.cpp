
#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int matrix[2][2];
    friend int determinant(const Matrix2x2& m);
    friend class MatrixHelper;

public:
    Matrix2x2() {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                matrix[i][j] = 0;
    }

    Matrix2x2(int a11, int a12, int a21, int a22) {
        matrix[0][0] = a11;
        matrix[0][1] = a12;
        matrix[1][0] = a21;
        matrix[1][1] = a22;
    }

    Matrix2x2 operator+(const Matrix2x2& other) {
        Matrix2x2 result;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        return result;
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        Matrix2x2 result;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        return result;
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        Matrix2x2 result;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
        return result;
    }

    friend ostream& operator<<(ostream& os, const Matrix2x2& m) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++)
                os << m.matrix[i][j] << " ";
            os << endl;
        }
        return os;
    }
};

class MatrixHelper {
public:
    static void updateElement(Matrix2x2& m, int row, int col, int value) {
        if(row >= 0 && row < 2 && col >= 0 && col < 2)
            m.matrix[row][col] = value;
    }
};

int determinant(const Matrix2x2& m) {
    return m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1] * m.matrix[1][0];
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:" << endl << m1;
    cout << "Matrix 2:" << endl << m2;

    cout << "Addition:" << endl << m1 + m2;
    cout << "Subtraction:" << endl << m1 - m2;
    cout << "Multiplication:" << endl << m1 * m2;

    cout << "Determinant of Matrix 1: " << determinant(m1) << endl;

    MatrixHelper::updateElement(m1, 0, 0, 10);
    cout << "Matrix 1 after update:" << endl << m1;

    return 0;
}
