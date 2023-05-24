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
            throw std::runtime_error("Enemy is dead!");
        }
        if (this->hasboolets() && this->isAlive())
        {
            this->bullets = this->bullets - 1;
            int newHitpoints = enemy->getHitpoints() - 10;
            enemy->setHitpoints(std::max(newHitpoints, 0));
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
    void Cowboy::atk(Character* enemy){
        if (!this->isAlive() || !enemy->isAlive())
            return;
        if (hasboolets())
            shoot(enemy);
        else
            reload();
    }
}
