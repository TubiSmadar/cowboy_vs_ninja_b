#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"



using namespace std;
namespace ariel{
    class Cowboy : public Character{
    private:
    int bullets;

    public:
    ~Cowboy() override = default;
    Cowboy(const Cowboy&) = default;
    Cowboy& operator=(const Cowboy&) = default;
    Cowboy(Cowboy&&) = default;
    Cowboy& operator=(Cowboy&&) = default;
    Cowboy(std::string name, Point point);
    void shoot(Character* enemy);
    bool hasboolets();
    void reload();
    void atk(Character* enemy);
};
}

#endif
