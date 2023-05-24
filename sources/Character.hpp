#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point point;
        int hitpoints;
        std::string name;
        bool inTeam;
    public:
        virtual ~Character() = default;
        Character(const Character&) = default;
        Character& operator=(const Character&) = default;
        Character(Character&&) = default;
        Character& operator=(Character&&) = default;
        Character(string name, Point point);
        Character(string name, Point point, int hitpoints);
        bool isAlive();
        double distance(Character *other);
        void hit(int damage);
        string getName();
        Point getLocation();
        void setLocation(Point location);
        virtual string print();
        int getHitpoints();
        void setHitpoints(int hitpoints);
        void setInTeam(bool exp);
        bool getInTeam();
    };
}

#endif // CHARACTER_HPP
