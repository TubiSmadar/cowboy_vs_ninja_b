#include "Ninja.hpp"

using namespace std;

    namespace ariel {

    
    Ninja::Ninja(std::string name, Point point, int hitpoints, int speed) : Character(name,point, hitpoints){

    }
    Ninja::Ninja(std::string name, Point point) : Character(name,point){

    }

    void Ninja::move(Character* enemy){
        Point dest = this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(),this->speed);
        this->setLocation(dest);
    }

    void Ninja::slash(Character* enemy){
        if (enemy == this)
        {
            throw std::runtime_error("Call someone if you need mental help!");
        }
        if (!(this->isAlive())){
            throw std::runtime_error("Ninja is dead!");
        }
        if (!(enemy->isAlive())){
            throw std::runtime_error("Enemy is dead!");
        }
        if (this->isAlive() && this->getLocation().distance(enemy->getLocation()) < 1)
        {
            enemy->hit(40);
        }
    }
    
};
