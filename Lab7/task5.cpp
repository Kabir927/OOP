#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(string id, string n, int lvl, int hp, string weapon)
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks with basic ability!" << endl;
    }

    virtual void defend() {
        cout << name << " defends with basic stance!" << endl;
    }

    virtual void displayStats() {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        cout << "Weapon Type: " << weaponType << endl;
    }
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(string id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " swings weapon for " << meleeDamage << " melee damage!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength << endl;
        cout << "Melee Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(string id, string n, int lvl, int hp, string weapon, int mana, int power)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() override {
        cout << name << " creates a magical barrier with " << spellPower << " power!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << endl;
        cout << "Spell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(string id, string n, int lvl, int hp, string weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " shoots arrow with " << rangedAccuracy << "% accuracy!" << endl;
        arrowCount--;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Arrow Count: " << arrowCount << endl;
        cout << "Ranged Accuracy: " << rangedAccuracy << "%" << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(string id, string n, int lvl, int hp, string weapon, int stealth, int agi)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior("W001", "Conan", 10, 150, "Greatsword", 50, 35);
    Mage mage("M001", "Gandalf", 12, 90, "Staff", 200, 75);
    Archer archer("A001", "Legolas", 15, 120, "Longbow", 30, 95);
    Rogue rogue("R001", "Shadow", 8, 110, "Daggers", 80, 90);

    warrior.attack();
    warrior.defend();
    warrior.displayStats();

    mage.attack();
    mage.defend();
    mage.displayStats();

    archer.attack();
    archer.defend();
    archer.displayStats();

    rogue.attack();
    rogue.defend();
    rogue.displayStats();

    return 0;
}