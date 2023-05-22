#include <iostream>
#include <cmath>

#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leaderP)
    {
        if (leaderP->getInTeam()){
            throw std::runtime_error("Leader in team already!");
        }
        this->teamSize = 1;
        this->leaderP = leaderP;
        this->leaderP->setInTeam(true);
        this->warriors.push_back(leaderP);
    }

    Team::~Team()
    {
        for (const auto& warrior : warriors) 
        {
            delete warrior;
        }
    }

    bool Team::isMember(Character *character)
    {
        return true;
    }
    void Team::add(Character *fighter_to_add)
    {
        if (warriors.size() >= 10)
        {
            throw std::runtime_error("size bigger than 10 error!");
        }
        
        if (fighter_to_add->getInTeam()){
            throw std::runtime_error("Character in team already!");
        }
        this->warriors.push_back(fighter_to_add);
        fighter_to_add->setInTeam(true);
        teamSize++;
    }
    void Team::attack(Team *enemy_team)
    {
        if(enemy_team == nullptr)
        {
            throw std::invalid_argument("nullptr");
        }
        //first check leader life and choose other if needed
        if(!this->leaderP->isAlive()){
            this->leaderP = chooseLeader(this->leaderP);
        }
        //team choose target

        Character* target;

        target = chooseTarget(enemy_team);
        label1:
        if (target->isAlive() && target != nullptr){
            for (Character* character : this->warriors)
            {
                    if(this->stillAlive() <= 0 || enemy_team->stillAlive() <=0)
                    {
                        break;
                    }
                    if (character->isAlive())
                    {
                        if (Cowboy *temp = dynamic_cast<Cowboy *>(character)){
                            if (temp->hasboolets())
                                temp->shoot(target);
                                if (isLeader(temp))
                                {
                                    target = chooseLeader(enemy_team->leaderP);
                                }
                            else
                                temp->reload();
                        }

                        if (Ninja *temp = dynamic_cast<Ninja *>(character)){
                            if(temp->getLocation().distance(target->getLocation()) < 1)
                                temp->slash(target);
                                if (isLeader(temp))
                                {
                                    target = chooseLeader(enemy_team->leaderP);
                                }
                            else
                                temp->move(target);
                        }
                    }
                    else {
                        goto label1;
                    }      
            }
        }


    }
    bool Team::isLeader(Character* warrior){
        if (warrior == leaderP)
        {return true;}
        return false;
    }


    Character* Team::chooseLeader(Character* leaderP){
        double temp_dist = std::numeric_limits<double>::max();
        Character* temp;
        for (Character* character : this->warriors){
            if (leaderP->distance(character) < temp_dist && character->isAlive())
            {
                temp = character;
            }
        }
        return temp;
    }
    Character* Team::chooseTarget(Team *enemy_team){
        if (enemy_team->stillAlive() <= 0)
        {
            return NULL;
        }
        double temp_dist = std::numeric_limits<double>::max();
        Character* temp;
        for (Character* character : enemy_team->getWarriors()){
            if (this->leaderP->distance(character) < temp_dist && character->isAlive())
            {
                temp = character;
            }
        }
        return temp;
    }

    

    int Team::stillAlive()
    {
        return this->teamSize;
    }
    void Team::print()
    {
        for (Character *character : warriors)
        {
            if (Cowboy *temp = dynamic_cast<Cowboy *>(character))
                std::cout << "c: " << temp->print() << "\n";

            if (Ninja *temp = dynamic_cast<Ninja *>(character))
                std::cout << "n: " << temp->print() << "\n";

        }
    }

    Character *Team::getByOrder()
    {
        return NULL;
    }

    void Team::remove(Character* fighter_to_remove)
    {
        fighter_to_remove->setInTeam(false);
        auto it = std::find(warriors.begin(), warriors.end(), fighter_to_remove);
        if (it != warriors.end()) {
            warriors.erase(it);
        }
        teamSize--;
    }

    Character *Team::getLeaderP()
    {
        return this->leaderP;
    }

    size_t Team::size()
    {
        return warriors.size();
    }
            
    vector<Character *> Team::getWarriors(){
        return this->warriors;
    }



}
