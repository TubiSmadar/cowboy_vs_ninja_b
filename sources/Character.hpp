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
        string name;

    public:
        Character(string name, Point point);
        Character(string name, Point point, int hitpoints);
        bool isAlive();
        double distance(Character *other);
        void hit(int damage);
        string getName();
        Point getLocation();
        virtual string print();

        int getHitpoints();
        void moveTowards(Point point, double distance);

        
    };
}

#endif // CHARACTER_HPP
