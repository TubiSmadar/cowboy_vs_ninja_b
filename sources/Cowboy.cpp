#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"

namespace ariel {



    Cowboy::Cowboy(std::string name, Point point) : Character(name, point, 110){
        this->bullets = 6;
    }

    void Cowboy::shoot(Character* enemy){
        if (enemy == this)
        {
            throw std::runtime_error("Call someone if you need mental help!");
        }
        if (!(this->isAlive())){
            throw std::runtime_error("Cowboy is dead!");
        }
        if (!(enemy->isAlive())){
            throw std::runtime_error("Enemy is dead!\nDon't waste ammo!");
        }
        if (this->hasboolets() && this->isAlive())
        {
            this->bullets = this->bullets - 1;
            enemy->setHitpoints(enemy->getHitpoints() - 10);
        }
    }

    bool Cowboy::hasboolets(){
        return this->bullets >= 1;
    }

    void Cowboy::reload(){
        if (!(this->isAlive()))
        {
            throw std::runtime_error("Dead can't reload!");
        }
        this->bullets = 6;
    }
    
}
