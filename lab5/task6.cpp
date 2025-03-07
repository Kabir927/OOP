#include <iostream>
#include <string>

using namespace std;

class Level {
public:
    string levelName;
    int difficulty;

    Level(string name, int difficulty) : levelName(name), difficulty(difficulty) {}
};

class VideoGame {
public:
    string title;
    string genre;
    Level* levels[10];
    int levelCount;

    VideoGame(string title, string genre) : title(title), genre(genre), levelCount(0) {}

    void addLevel(Level* level) {
        if (levelCount < 10) {
            levels[levelCount++] = level;
        }
    }

    void display() {
        cout << "Game: " << title << ", Genre: " << genre << endl;
        cout << "Levels: " << endl;
        for (int i = 0; i < levelCount; ++i) {
            cout << "Level Name: " << levels[i]->levelName << ", Difficulty: " << levels[i]->difficulty << endl;
        }
    }

    ~VideoGame() {
        for (int i = 0; i < levelCount; ++i) {
            delete levels[i];
        }
    }
};

int main() {
    VideoGame game("Epic Quest", "RPG");

    game.addLevel(new Level("Forest", 1));
    game.addLevel(new Level("Cave", 3));
    game.addLevel(new Level("Castle", 5));

    game.display();

    return 0;
}