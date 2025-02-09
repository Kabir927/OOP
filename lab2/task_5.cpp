#include <iostream>
#include <iomanip>

using namespace std;

void displayMatrix(int** matrix, int rows, int cols);
void transposeMatrix(int** matrix, int rows, int cols);
void deallocateMatrix(int** matrix, int rows);

int main() {
    int rows, cols;
    cout << "Enter Rows and Columns: ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols); 

    cout << "\nTransposed Matrix:\n";
    displayMatrix(matrix, rows, cols); 

    deallocateMatrix(matrix, rows);

    return 0;
}

void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}