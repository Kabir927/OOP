#include <iostream>
#include <iomanip>

using namespace std;

void getMatrixInput(int** matrix, int rows, int cols);
void displayMatrix(int** matrix, int rows, int cols);
void addMatrices(int** matrix1, int** matrix2, int** resultMatrix, int rows, int cols);
void subtractMatrices(int** matrix1, int** matrix2, int** resultMatrix, int rows, int cols);
void deallocateMatrix(int** matrix, int rows);

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int** matrix1 = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix1[i] = new int[cols];
    }

    int** matrix2 = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix2[i] = new int[cols];
    }

    cout << "Enter elements of matrix 1:\n";
    getMatrixInput(matrix1, rows, cols);

    cout << "Enter elements of matrix 2:\n";
    getMatrixInput(matrix2, rows, cols);

    cout << "\nDisplaying Matrix 1:\n";
    displayMatrix(matrix1, rows, cols);

    cout << "\nDisplaying Matrix 2:\n";
    displayMatrix(matrix2, rows, cols);

    int** sumMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        sumMatrix[i] = new int[cols];
    }
    addMatrices(matrix1, matrix2, sumMatrix, rows, cols);
    cout << "\nDisplaying Sum of Matrices:\n";
    displayMatrix(sumMatrix, rows, cols);
    deallocateMatrix(sumMatrix, rows);

    int** differenceMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        differenceMatrix[i] = new int[cols];
    }
    subtractMatrices(matrix1, matrix2, differenceMatrix, rows, cols);
    cout << "\nDisplaying Difference of Matrices:\n";
    displayMatrix(differenceMatrix, rows, cols);
    deallocateMatrix(differenceMatrix, rows);

    deallocateMatrix(matrix1, rows);
    deallocateMatrix(matrix2, rows);

    return 0;
}

void getMatrixInput(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void addMatrices(int** matrix1, int** matrix2, int** resultMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int** matrix1, int** matrix2, int** resultMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}