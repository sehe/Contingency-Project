/* Contingency Project By Finn Fallowfield
 * Copyright (c) 2016 Finn Fallowfield
 * Nuclear War Survival Simulator
 */

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;
using std::string;

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


/// Weapon class
/// Every weapon in the game will be of type Weapon
/// Each one is upgradable

class Weapon 
{
private:
    int count;
    int damage;
    float cost;
    int range;

public:
    void upgradeRange(float p) {
        float percentDecimal = p / 100;
        float modifier = percentDecimal + 1;
        range *= modifier;
    }

    void upgradeCost(float p) {
        float percentDecimal = p / 100;
        float modifier = percentDecimal + 1;
        cost *= modifier;
    }

    void upgradeDamage(float p) {
        float percentDecimal = p / 100;
        float modifier = percentDecimal + 1;
        damage *= modifier;
    }

    void increaseCount(int i) {
        count += i;
    }


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

/// Weapon arsenal
/// Each region has own version of WeaponArsenal which defines each type of weapon and sets their default weapons


class WeaponArsenal
{ /* Weapon Types */
public:

    Weapon icbm;
    Weapon mrbm;
    Weapon srbm;
    Weapon bomb;

    WeaponArsenal() { 

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


/// REGION CLASSES

class Region
{
public:
    WeaponArsenal arsenal;
};

class EnemyRegion 
{

};

void EventHandler() {

}

void Update() {

    bool run = true;
    
    /// WHILE LOOP IN UPDATE FUNCTION WILL UPDATE ONCE PER SECOND

    while(run) {

        auto begin = std::chrono::high_resolution_clock::now(); // Start point time
        
        cout << "second has passed\n";

        auto end = std::chrono::high_resolution_clock::now(); // End point time

        //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(); // Duration between start and end point

        auto remaining = std::chrono::seconds(1) - (end - begin); // Remaining time

        std::this_thread::sleep_for(remaining); // Pause for remaining time

    }
}

int main() {

    // Call each region's class constructors (temporary for testing)

    string playerRegion;

    cout << "Welcome to The Contingency Project.\n"
         << "A global nuclear war is about to take place\n"
         << "Will you be able to survive with the smallest population decrease percentage?\n";

    cout << "Please select a region to play as.\n> ";
    cin >> playerRegion;
    cout << "You have chosen to play as " << playerRegion << "!\n";



    Update();


}
