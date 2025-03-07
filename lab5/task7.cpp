#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;

    Product(int id, string name, int quantity) : id(id), name(name), quantity(quantity) {}
};

class Warehouse {
public:
    Product* products[100];
    int productCount;

    Warehouse() : productCount(0) {}

    void addProduct(Product* product) {
        if (productCount < 100) {
            products[productCount++] = product;
        }
    }

    void sortProducts() {
        for (int i = 0; i < productCount - 1; ++i) {
            for (int j = i + 1; j < productCount; ++j) {
                if (products[i]->name > products[j]->name) {
                    Product* temp = products[i];
                    products[i] = products[j];
                    products[j] = temp;
                }
            }
        }
    }

    void searchProduct(int id) {
        for (int i = 0; i < productCount; ++i) {
            if (products[i]->id == id) {
                cout << "Product Found: ID: " << products[i]->id << ", Name: " << products[i]->name << ", Quantity: " << products[i]->quantity << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void displayProducts() {
        for (int i = 0; i < productCount; ++i) {
            cout << "ID: " << products[i]->id << ", Name: " << products[i]->name << ", Quantity: " << products[i]->quantity << endl;
        }
    }
};

int main() {
    Warehouse warehouse;

    warehouse.addProduct(new Product(1, "Chair", 50));
    warehouse.addProduct(new Product(2, "Laptop", 20));
    warehouse.addProduct(new Product(3, "Apple", 100));

    warehouse.sortProducts();
    warehouse.displayProducts();

    warehouse.searchProduct(2);
    warehouse.searchProduct(4);

    return 0;
}