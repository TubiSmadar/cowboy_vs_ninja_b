#include <iostream>
#include <cmath>

#include "Character.hpp"
using namespace std;

namespace ariel
{
    Character::Character(string name, Point point) : name(name), point(point){
        this->inTeam = false;
    }
    Character::Character(string name, Point point, int hitpoints) : name(name), point(point), hitpoints(hitpoints)
    {
        this->inTeam = false;
    }

    bool Character::isAlive()
    {
        return this->hitpoints > 0;
    }
    
    void Character::hit(int damage)
    {
        if (damage < 0)
        {
            throw std::invalid_argument("can't heal in this game!");
        }
        if (this->hitpoints - damage < 0)
        {
            this->hitpoints = 0;
        }
        else
        {
            this->hitpoints = this->hitpoints - damage;
        }
    }
    string Character::getName()
    {
        return this->name;
    }
    Point Character::getLocation()
    {
        return this->point;
    }
    void Character::setLocation(Point location){
        this->point = location;
    }
    string Character::print()
    {
        std::string info = "Name: " + name + "\n";
        info += "Hitpoints: " + std::to_string(hitpoints) + "\n";
        info += "Point: ";
        info += point.print(this->point);
        info += "\n";
        return info;
    }

    int Character::getHitpoints()
    {
        return this->hitpoints;
    }
    
    void Character::setHitpoints(int hitpoints){
        this->hitpoints = hitpoints;
    }
    
    double Character::distance(Character *other){
        return this->point.distance(other->getLocation());
    }
    void Character::setInTeam(bool exp) {
        this->inTeam = exp;
    }
    bool Character::getInTeam(){
        return this->inTeam;
    }


}
