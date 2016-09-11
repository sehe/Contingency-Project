// Includes:

#include <iostream>
#include <string>
#include <functional>
#include <chrono> 
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/// Weapon class
/// Every weapon in the game
/// Weapons are upgradable

class Weapon 
{
private:
    int count;
    int damage;
    float cost;
    int range;

public:

    /* SET */

    void setCost(float c)
    {
        cost = c;
    }

    void setDamage(int d)
    {
        damage = d;
    }

    void setRange(int r)
    {
        range = r;
    }

    void setCount(int n)
    {
        count = n;
    }


    /* GET */

    float getCost()
    {
        return cost;
    }

    int getDamage()
    {
        return damage;
    }

    int getRange()
    {
        return range;
    }

    int getCount()
    {
        return count;
    }

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
    Weapon bomb;

public:

    Region(string n) : name(n)
    {
        /* Set region weapon values */

        // DEFAULT ICBM VALUES
        icbm.setCount(0);
        icbm.setCost(120);
        icbm.setRange(8000);
        icbm.setDamage(80);

        // DEFAULT MRBM VALUES
        mrbm.setCount(0);
        mrbm.setCost(100);
        mrbm.setRange(2000);
        mrbm.setDamage(70);
        
        // DEFAULT SRBM VALUES
        srbm.setCount(0);
        srbm.setCost(80);
        srbm.setRange(800);
        srbm.setDamage(55);
    }

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
    Region& europe;
    Region& russia;
    Region& sea;
    Region& america;
    Region& china;
    Region& africa;

    enum RegionCode { EU, RU, SEA, AM, CH, AF};

    Region regions[6];

    PlayerController playerController;

    RegionHandler() : europe(regions[EU]),
                      russia(regions[RU]),
                      sea(regions[SEA]),
                      america(regions[AM]),
                      china(regions[CH]),
                      africa(regions[AF]),
                      regions {Region{"europe"},Region{"russia"},Region{"sea"},Region{"america"},Region{"china"},Region{"africa"}}
    {

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
    Region* playerRegion;
    RegionHandler regionHandler;

    // Game introduction
    cout << "Welcome to The Contingency Project.\n"
         << "A global nuclear war is about to take place\n"
         << "Will you be able to survive with the smallest population decrease percentage?\n";

    regionHandler.chooseRegion();

}
