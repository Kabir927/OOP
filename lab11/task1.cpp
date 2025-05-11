
#include <iostream>
#include <string>
using namespace std;

class DimensionMismatchException : public std::exception {
private:
    string msg;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        msg = "Matrices must have same dimensions (" + to_string(r1) + "x" + to_string(c1) + " vs " + to_string(r2) + "x" + to_string(c2) + ")!";
    }
    
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

template<typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for(int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }
    
    ~Matrix() {
        for(int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    
    void setElement(int i, int j, T value) {
        data[i][j] = value;
    }
    
    T getElement(int i, int j) const {
        return data[i][j];
    }
    
    Matrix operator+(const Matrix& other) {
        if(rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }
        
        Matrix result(rows, cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    void display() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);
        
        A.setElement(0, 0, 1);
        A.setElement(0, 1, 2);
        A.setElement(1, 0, 3);
        A.setElement(1, 1, 4);
        
        Matrix<int> C = A + B;
    }
    catch(const DimensionMismatchException& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}