/* Contingency Project By Finn Fallowfield
 * Copyright (c) 2016 Finn Fallowfield
 * Nuclear War Survival Simulator
 */

// Includes:

#include <iostream>
#include <chrono> 
#include <thread>

using std::cout;
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
    int wealth; // wealth in billions
    int aggression;
    int max_aggression;


    Weapon icbm;
    Weapon mrbm;
    Weapon srbm;

    Weapon bomb;

public:

    Region()
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

/* Vehicle base class */

class Vehicle
{

}

/* Vehicle child classes */

class Boat : public Vehicle 
{

}

class Plane : public Vehicle
{

}

class Submarine : public Vehicle 
{

}


/* Controllers */

class PlayerController // Player specific methods and variables
{
    //
};

class AiController // AI specific methods and variabels
{
    //
};

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
    string playerRegionInput; // Player's chosen region

    Region* playerRegion;

    // Game introduction
    cout << "Welcome to The Contingency Project.\n"
         << "A global nuclear war is about to take place\n"
         << "Will you be able to survive with the smallest population decrease percentage?\n";

    // Player region input
    cout << "Please select a region to play as.\n> ";
    cin >> playerRegion;
    cout << "You have chosen to play as " << playerRegion << "!\n";

    switch playerRegion { // Region selection conditional
        case "":
        break;
        case "":
    }


    // Run game loop through update function
    Update();

}
