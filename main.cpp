// Includes:

#include <iostream>
#include <string>
#include <functional>
#include <chrono> 
#include <thread>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

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
    string name;
    int wealth; // wealth in billions
    int aggression;
    int max_aggression;

    Weapon icbm;
    Weapon mrbm;
    Weapon srbm;
//    Weapon bomb;

public:
    Region(string n) : name(n), icbm(0, 80, 120, 8000), mrbm(0, 70, 80, 800), srbm(0, 55, 80, 800) {}
};

/* Controllers */

class PlayerController // Player specific methods and variables
{
public:
    Region* playerRegion;

};

class AiController // AI specific methods and variabels
{
public:

};

class RegionHandler 
{
public:
    // Region& europe;
    // Region& russia;
    // Region& sea;
    // Region& america;
    // Region& china;
    // Region& africa;

    enum RegionCode { EU, RU, SEA, AM, CH, AF};

    // Region regions[6];

    PlayerController playerController;

    // RegionHandler() : europe(regions[EU]),
    //                   russia(regions[RU]),
    //                   sea(regions[SEA]),
    //                   america(regions[AM]),
    //                   china(regions[CH]),
    //                   africa(regions[AF]),
    //                   regions {Region{"europe"},Region{"russia"},Region{"sea"},Region{"america"},Region{"china"},Region{"africa"}}
    // {}

    vector<Region> regions;
    
    RegionHandler() {
        static const char *names[] = { "russia", "sea", "america", "china", "africa"};
        for (auto n : names)
            regions.emplace_back(n);
    }
    

    void chooseRegion() {

        int playerRegionIndex;

        cout << "Regions:\n"
             << "0. Europe\n"
             << "1. Russia\n"
             << "2. SEA\n"
             << "3. America\n"
             << "4. China\n"
             << "5. Africa\n";

        do {
            cout << "Select a region\n> ";
            cin >> playerRegionIndex; // Get user to input a region int
        }

        while(playerRegionIndex < 0 || playerRegionIndex > 5);

        playerController.playerRegion = &regions[playerRegionIndex];
    }
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
    
    // Update function run once per second

    while(run) 
    {
        // GAME LOOP

        auto begin = std::chrono::high_resolution_clock::now(); // Start timepoint 
        
        cout << "second has passed\n"; // Test if second has passed

        // Update loop code here

        auto end = std::chrono::high_resolution_clock::now(); // End timepoint

        //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(); // Duration between start and end point

        auto remaining = std::chrono::seconds(1) - (end - begin); // Remaining time

        std::this_thread::sleep_for(remaining); // Pause for remaining time

    }
}

int main() 
{
    RegionHandler regionHandler;
    PlayerController playerController;

    // Game introduction
    cout << "Welcome to The Contingency Project.\n"
         << "A global nuclear war is about to take place\n"
         << "Will you be able to survive with the smallest population decrease percentage?\n";

    regionHandler.chooseRegion();

    string mystr = playerController.playerRegion->name;

}
