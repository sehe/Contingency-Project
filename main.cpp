// Includes:
#include <iostream>
#include <string>
#include <functional>
#include <chrono> 
#include <thread>
#include <vector>
#include <cmath>

struct Goodbye {};
using Clock = std::chrono::high_resolution_clock;

/// Weapon class
/// Every weapon in the game
/// Weapons are upgradable

struct Weapon 
{
    int count;
    int damage;
    float cost;
    int range;
    
    Weapon(int count, int damage, float cost, int range) : count(count), damage(damage), cost(cost), range(range) {}
};

/* Region */

class Region
{
public:
    std::string name;
    int wealth; // wealth in billions
    int aggression;
    int max_aggression;

    Weapon icbm;
    Weapon mrbm;
    Weapon srbm;

public:
    Region(std::string n) : name(n), icbm(0, 80, 120, 8000), mrbm(0, 70, 80, 800), srbm(0, 55, 80, 800) {}
};

namespace Regions {
    std::vector<Region> static all {
        {"europe"},
        {"russia"},
        {"sea"},
        {"america"},
        {"china"},
        {"africa"},
    };

    Region& choose() {
        unsigned choice = all.size(); // invalid

        std::cout << "Regions:\n";
        for (unsigned i = 0; i < all.size(); ++i) {
            std::cout << i << ". " << all.at(i).name << "\n";
        }

        while (choice >= Regions::all.size()) {
            std::cout << "Select a region\n> ";

            if (!(std::cin >> choice)) {
                if (std::cin.eof()) throw Goodbye{};
                std::cin.clear();
                std::cin.ignore(1024, '\n');

                choice = all.size(); // need to reset
            }
        }

        return Regions::all.at(choice);
    }
}

/* Controllers */

class PlayerController // Player specific methods and variables
{
    Region& _region;
public:
    Region const& region() const { return _region; }

    PlayerController(Region& region) : _region(region) { }
};

class AiController // AI specific methods and variabels
{
public:

};

/* Vehicle base class */

class Vehicle
{

};

/* Start function */

void Start() {
}

void Update() {
    bool run = true; // Set run to false to quit update loop and end game loop: TEMP
    
    while (run) {
        auto begin = Clock::now();

        // Update loop code here

        std::this_thread::sleep_until(begin + std::chrono::seconds(1)); // Pause for remaining time
    }
}

int main() 
{
    std::cout << "Welcome to The Contingency Project.\n"
         << "A global nuclear war is about to take place\n"
         << "Will you be able to survive with the smallest population decrease percentage?\n";

    PlayerController playerController(Regions::choose());
    std::cout << playerController.region().name;
}
