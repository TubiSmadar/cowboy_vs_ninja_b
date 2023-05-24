#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
#include "Point.hpp"  

using namespace std;
namespace ariel{
    class Ninja : public Character{
    private:
    int speed;

    public:
    ~Ninja() override = default;
    Ninja(const Ninja&) = default;
    Ninja& operator=(const Ninja&) = default;
    Ninja(Ninja&&) = default;
    Ninja& operator=(Ninja&&) = default;    Ninja(std::string name, Point point);
    Ninja(std::string name, Point point, int hitpoints, int speed);
    void move(Character* enemy);
    void slash(Character* enemy);
    void atk(Character* enemy);

};
}

#endif
