#include "Ninja.hpp"

using namespace std;

    namespace ariel {

    
    Ninja::Ninja(std::string name, Point point, int hitpoints, int speed) : Character(name,point, hitpoints){

    }
    Ninja::Ninja(std::string name, Point point) : Character(name,point){

    }

    void Ninja::move(Character* enemy){

    }

    void Ninja::slash(Character* enemy){
        
    }
    
};
