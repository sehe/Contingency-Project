/* Contingency Project By Finn Fallowfield
 * Copyright (c) 2016 Finn Fallowfield
 * Nuclear War Survival Simulator
 */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class ContinentStats 
{

};

class Weapon 
{
private:
    int damage;
    int cost;
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

    void getCost()
    {
        return cost;
    }

    void getDamage()
    {
        return damage;
    }

    void getRange()
    {
        return range;
    }

};

class WeaponArsenal
{
public:
    Weapon icbm;
    Weapon mrbm;
    Weapon srbm;
    Weapon bomb;
};

class Europe
{
private:
    WeaponArsenal arsenal;

public:   
    Europe() {    
        arsenal.icbm.setCost(120);
        arsenal.icbm.setRange(90);
        arsenal.mrbm.setCost(70);
        arsenal.srbm.setCost(30);
    }
};

class China
{
private:
    WeaponArsenal arsenal;

public:
    China() {
        arsenal.srbm.setCost(100);
    }
};

class Russia
{
private:
    WeaponArsenal arsenal:

public:
    Russia() {
        arsenal.srbm.setCost(50);
    }

};

class America 
{
private:
    WeaponArsenal arsenal;

public:
    America() {
        arsenal.srbm.setCost(50);
    }

};



int main() {

    // Call continent class constructors
    Europe europe;
    China china;
    Russia russia;
    America america;

}