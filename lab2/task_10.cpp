#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int layers, rows, cols;
    cout << "Enter Dimensions for 3D array (Layers Rows Columns): ";
    cin >> layers >> rows >> cols;

    int*** array3D = new int**[layers];

    for (int i = 0; i < layers; i++) {
        array3D[i] = new int*[rows];
        for (int j = 0; j < rows; j++) {
            array3D[i][j] = new int[cols];
            for (int k = 0; k < cols; k++) {
                cout << "Element [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    for (int i = 0; i < layers; i++) {
        cout << "\nLayer " << i + 1 << ":\n";
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                cout << "|" << setw(2) << array3D[i][j][k];
            }
            cout << "|\n";
        }
    }

    // Deallocate memory (remember to deallocate in reverse order of allocation)
    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < rows; j++) {
            delete[] array3D[i][j];
        }
        delete[] array3D[i];
    }
    delete[] array3D;

    return 0;
}