/* Contingency Project By Finn Fallowfield
 * Copyright (c) 2016 Finn Fallowfield
 * Nuclear War Survival Simulator
 */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

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
    void upgradeRange(Weapon wep, float p) {
        float percentDecimal = p / 100;
        float modifier = percentDecimal + 1;
        wep.range * modifier;
    }

    void upgradeCost(Weapon wep, float p) {
        float percentDecimal = p / 100;
        float modifier = percentDecimal + 1;
        wep.cost * modifier;
    }

    void upgradeDamage(Weapon wep, float p) {
        float percentDecimal = p / 100;
        float modifier = percentDecimal + 1;
        wep.damage * modifier;
    }

    void increaseCount(Weapon wep, int i) {
        wep.count += i;
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

class Europe
{
private:
    WeaponArsenal arsenal;

public:   

    Europe() {    
    }
};

class China
{
private:
    WeaponArsenal arsenal;

public:

    China() {
    }
    
};

class Russia
{
private:
    WeaponArsenal arsenal;

public:

    Russia() {
    }

};

class America 
{
private:
    WeaponArsenal arsenal;

public:

    America() {
    }

};

class Isreal {
    private:
    WeaponArsenal arsenal;

public:

    Isreal() {
    }

}

int main() {

    // Call each region's class constructors (temporary for testing)
    Europe europe;
    China china;
    Russia russia;
    America america;

}
