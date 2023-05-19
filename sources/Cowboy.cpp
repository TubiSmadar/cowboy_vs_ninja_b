#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"

namespace ariel {



    Cowboy::Cowboy(std::string name, Point point) : Character(name, point){

    }

    void Cowboy::shoot(Character* enemy){

    }

    bool Cowboy::hasboolets(){
        return false;
    }

    void Cowboy::reload(){
        
    }
    
}
