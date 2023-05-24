#include <iostream>
#include <cmath>

#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *t2LeaderP) : Team(t2LeaderP)
    {
        
    }
    Character* SmartTeam::chooseTarget(Team* other){
        if (other == nullptr)
        {
            throw std::invalid_argument("nullptr");
        }
        if (other->stillAlive() <= 0)
        {
            return nullptr;
        }
        double temp_dist = std::numeric_limits<double>::max();
        Character* temp = nullptr; // Initialize temp to nullptr
        for (Character* character : other->getWarriors())
        {
            if(dynamic_cast<Cowboy*>(character) != nullptr){
                if (this->getLeaderP()->distance(character) < temp_dist && character->isAlive())
                {
                    temp_dist = this->getLeaderP()->distance(character); // Update temp_dist with the new minimum distance
                    temp = character; // Assign the selected character to temp
                }
            }
            else {
                if (this->getLeaderP()->distance(character) < temp_dist && character->isAlive())
                {
                    temp_dist = this->getLeaderP()->distance(character); // Update temp_dist with the new minimum distance
                    temp = character; // Assign the selected character to temp
                }  
            }
        }
        return temp;
    }


    void SmartTeam::attack(Team* other) {
        if (other == nullptr)
        {
            throw std::invalid_argument("nullptr");
        }
        if (!this->getLeaderP()->isAlive())
        {
            this->Team::setLeaderP(chooseLeader(this->getLeaderP()));
        }

        if (other->stillAlive() <= 0 || this->stillAlive()<=0)
        {
            throw std::runtime_error("cant attack dead team!");
            return;
        }

        choose_target:// For goto
        Character* target = chooseTarget(other);
        if (target == nullptr){
            return;
        }
        
        if (other->stillAlive() <= 0 || this->stillAlive()<=0)
        {
            return;
        }
        for (Character* warrior : this->getWarriors())
        {
            if (other->stillAlive() <= 0 || this->stillAlive()<=0)
                {
                    return;
                }
            if (warrior->isAlive() && warrior != nullptr){
                if (dynamic_cast<Cowboy*>(warrior) != nullptr)
                {
                    Cowboy* temp = (Cowboy*)(warrior);
                    temp->atk(target);
                    // std::cout<<target->getHitpoints()<<std::endl;
                    if (!target->isAlive())
                    {
                        target = chooseTarget(other);
                    }
                }

                if (dynamic_cast<Ninja*>(warrior) != nullptr)
                {
                    Ninja* temp = (Ninja*)(warrior);
                    temp->atk(target);
                    // std::cout<<target->getHitpoints()<<std::endl;
                    if (!target->isAlive())
                    {
                        target = chooseTarget(other);
                    }
                }

            }
        }

    }

}
