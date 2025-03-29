#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID;
    string productName;
    float price;
    int stockQuantity;

public:
    Product(string id, string name, float p, int stock) 
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual void applyDiscount(float discountPercent) {
        price *= (1 - discountPercent / 100);
    }

    virtual float calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock Quantity: " << stockQuantity << endl;
    }

    friend ostream& operator<<(ostream& os, Product& p) {
        p.displayProductInfo();
        return os;
    }

    float operator+(Product& other) {
        return price + other.price;
    }
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(string id, string name, float p, int stock, int warranty, string b) 
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Warranty Period: " << warrantyPeriod << " months" << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product {
private:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(string id, string name, float p, int stock, string s, string c, string fabric) 
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}

    void applyDiscount(float discountPercent) override {
        price *= (1 - discountPercent / 100);
        cout << "Seasonal discount applied: " << discountPercent << "%" << endl;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Fabric Material: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
private:
    string expirationDate;
    int calories;

public:
    FoodItem(string id, string name, float p, int stock, string expDate, int cal) 
        : Product(id, name, p, stock), expirationDate(expDate), calories(cal) {}

    float calculateTotalPrice(int quantity) override {
        if (quantity >= 5) {
            return price * quantity * 0.9;
        }
        return price * quantity;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Expiration Date: " << expirationDate << endl;
        cout << "Calories: " << calories << endl;
    }
};

class Book : public Product {
private:
    string author;
    string genre;

public:
    Book(string id, string name, float p, int stock, string a, string g) 
        : Product(id, name, p, stock), author(a), genre(g) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics laptop("E001", "Laptop", 999.99, 10, 24, "Dell");
    Clothing shirt("C001", "T-Shirt", 19.99, 50, "M", "Blue", "Cotton");
    FoodItem apple("F001", "Apple", 0.99, 100, "2025-12-31", 52);
    Book novel("B001", "The Great Novel", 14.99, 20, "Jane Doe", "Fiction");

    laptop.applyDiscount(10);
    shirt.applyDiscount(20);

    cout << laptop;
    cout << shirt;
    cout << apple;
    cout << novel;

    cout << "Total price for 10 apples: $" << apple.calculateTotalPrice(10) << endl;
    cout << "Combined price of laptop and shirt: $" << (laptop + shirt) << endl;

    return 0;
}