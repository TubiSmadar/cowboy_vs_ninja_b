#include <iostream>
#include <cmath>

#include "Character.hpp"
using namespace std;

namespace ariel
{
    Character::Character(string name, Point point) : name(name), point(point){
    
    }
    Character::Character(string name, Point point, int hitpoints) : name(name), point(point), hitpoints(hitpoints)
    {
    }

    bool Character::isAlive()
    {
        return true;
    }
    double Character::distance(Character *other)
    {
        return 0.0;
    }
    void Character::hit(int damage)
    {
    }
    string Character::getName()
    {
        return "";
    }
    Point Character::getLocation()
    {
        return Point(0.0, 0.0);
    }
    string Character::print()
    {
        return "";
    }

    int Character::getHitpoints()
    {
        return 0;
    }

    void Character::moveTowards(Point point, double distance)
    {

    }

}
