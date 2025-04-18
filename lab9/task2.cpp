#include <iostream>
#include <string>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p) : dishName(name), price(p) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
private:
    bool isHot;

public:
    Appetizer(string name, double price, bool hot)
        : MenuItem(name, price), isHot(hot) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << endl;
        cout << "Price: $" << price << endl;
        cout << "Served: " << (isHot ? "Hot" : "Cold") << endl;
    }

    void prepare() override {
        cout << "Preparing appetizer " << dishName << ":" << endl;
        cout << "1. Gather ingredients" << endl;
        cout << "2. Mix components" << endl;
        cout << "3. Plate with garnish" << endl;
    }
};

class MainCourse : public MenuItem {
private:
    string cookingLevel;

public:
    MainCourse(string name, double price, string level)
        : MenuItem(name, price), cookingLevel(level) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << endl;
        cout << "Price: $" << price << endl;
        cout << "Cooking Level: " << cookingLevel << endl;
    }

    void prepare() override {
        cout << "Preparing main course " << dishName << ":" << endl;
        cout << "1. Season ingredients" << endl;
        cout << "2. Cook to " << cookingLevel << endl;
        cout << "3. Prepare side dishes" << endl;
        cout << "4. Plate presentation" << endl;
    }
};

int main() {
    MenuItem* menu[2];
    
    menu[0] = new Appetizer("Bruschetta", 8.99, true);
    menu[1] = new MainCourse("Grilled Salmon", 24.99, "Medium");

    for(int i = 0; i < 2; i++) {
        menu[i]->showDetails();
        menu[i]->prepare();
        cout << "------------------------" << endl;
    }

    for(int i = 0; i < 2; i++) {
        delete menu[i];
    }

    return 0;
}