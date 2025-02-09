#include <iostream>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

int main() {
    double totalValue = 0;
    int numProducts;
    cout << "Enter number of Products: ";
    cin >> numProducts;

    Product* products = new Product[numProducts];

    for (int i = 0; i < numProducts; i++) {
        cout << "\nEnter Details For Product " << i + 1 << ":\n";

        cout << "Enter Product ID: ";
        cin >> products[i].id;
        cout << "Enter Product Name: ";
        cin >> products[i].name;
        cout << "Enter Quantity of Product: ";
        cin >> products[i].quantity;
        cout << "Enter Product Price: ";
        cin >> products[i].price;
        totalValue += (products[i].quantity * products[i].price); 
    }

    cout << "\nThe Total Value of Inventory is: " << totalValue << endl;

    delete[] products;
    return 0;
}