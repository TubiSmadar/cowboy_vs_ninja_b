#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"



using namespace std;
namespace ariel{
    class Cowboy : public Character{
    private:
    int bullets;

    public:
    Cowboy(std::string name, Point point);
    void shoot(Character* enemy);
    bool hasboolets();
    void reload();
};
}

#endif
