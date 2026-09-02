#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global difficulty level
int level = 1;

//Part A

class Entity {
private:
    string name;
    int health;
    int level;
    string type;

public:
    Entity& setName(const string& name) {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health) {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level) {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type) {
        this->type = type;
        return *this;
    }

    string getName() const { 
        return name; }
    int getHealth() const { 
        return health; }
    int getLevel() const {
         return level; }
    string getType() const { 
        return type; }

    void displayInfo() const {
        cout << "Name: " << name << " | Type: " << type << " | Health: " << health << " | Level: " << level << endl;
    }
};

//Part B -----------------

namespace Physics {
    double clamp(double val, double min, double max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

namespace GameMath {
    int clamp(int val, int min, int max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}


namespace Engine {
    namespace Audio {
        void playSound(string name) {
            cout << "Playing: " << name << endl;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // ------Part A----------------

    Entity player, enemy, item;
    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();

    // ---------------- Part B
    cout << "Physics::clamp(velocity 15.5, 0, 10)  = " << Physics::clamp(15.5, 0, 10) << endl;
    cout << "GameMath::clamp(health 120, 0, 100)    = " << GameMath::clamp(120, 0, 100) << endl;
    cout << "Physics::lerp(0, 10, 0.5)              = " << Physics::lerp(0, 10, 0.5) << endl;
    cout << "GameMath::lerp(0, 10, 0.5)             = " << GameMath::lerp(0, 10, 0.5) << endl;

    {
        using namespace GameMath;
        
        cout << "(inside block, using GameMath) clamp(7, 1, 5) = " << clamp(7, 1, 5) << endl;
    }

    // ---Part C
    cout << "\n===== GAME MAP GENERATION =====" << endl;
    int R, C;
    cout << "Enter number of rows: ";
    cin >> R;
    cout << "Enter number of columns: ";
    cin >> C;

    int** map = new int*[R];
    for (int i = 0; i < R; i++) {
        map[i] = new int[C];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] = rand() % 5;
        }
    }

    cout << "\n===== GAME MAP (" << R << " x " << C << ") =====" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << setw(3) << map[i][j];
        }
        cout << endl;
    }
    cout << "Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon" << endl;

    int tileCount[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            tileCount[map[i][j]]++;
        }
    }

    string tileNames[5] = {"Grass", "Water", "Mountain", "Forest", "Dungeon"};
    cout << "\nTile Count:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << " " << left << setw(10) << tileNames[i] << ": " << tileCount[i] << endl;
    }

    for (int i = 0; i < R; i++) {
        delete[] map[i];
    }
    delete[] map;

    int level = 25; // local player level, shadows the global
    cout << "Local level (player)  : " << level << endl;
    cout << "Global level (::level): " << ::level << endl;

    Engine::Audio::playSound("sword_clash");

    return 0;
}
