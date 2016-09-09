/* Contingency Project By Finn Fallowfield
 * Copyright (c) 2016 Finn Fallowfield
 * Nuclear War Survival Simulator
 */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

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

class WeaponArsenal
{ /* Weapon Types */
public:
    Weapon icbm;
    Weapon mrbm;
    Weapon srbm;
    Weapon bomb;

    WeaponArsenal() { 

        // ICBM
        icbm.setCount(0);
        icbm.setCost(120);
        icbm.setRange(8000);
        icbm.setDamage(80);

        // MRBM
        mrbm.setCount(0);
        mrbm.setCost(100);
        mrbm.setRange(2000);
        mrbm.setDamage(70);
        
        // SRBM
        srbm.setCount(0);
        srbm.setCost(80);
        srbm.setRange(800);
        srbm.setDamage(55);
    }
};

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

int main() {

    // Call continent class constructors
    Europe europe;
    China china;
    Russia russia;
    America america;

}