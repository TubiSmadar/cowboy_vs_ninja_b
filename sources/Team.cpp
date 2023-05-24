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
        if (Ninja *temp = dynamic_cast<Ninja *>(fighter_to_add)){
            this->warriors.push_back(fighter_to_add);
            fighter_to_add->setInTeam(true);
            teamSize++;
        }
        else{
            this->warriors.insert(this->warriors.begin(), fighter_to_add);
            fighter_to_add->setInTeam(true);
            teamSize++;
        }
    }
 
    bool Team::isLeader(Character* warrior){
        if (warrior == leaderP)
        {return true;}
        return false;
    }

    void Team::attack(Team* other) {
        if (other == nullptr)
        {
            throw std::invalid_argument("nullptr");
        }
        if (!this->leaderP->isAlive())
        {
            this->leaderP = chooseLeader(this->leaderP);
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
        for (Character* warrior : this->warriors)
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
    Character* Team::chooseLeader(Character* leaderP){
        if (leaderP->isAlive())
        {return leaderP;}
        if (leaderP == nullptr)
        {
            throw std::invalid_argument("nullptr");
        }
        double temp_dist = std::numeric_limits<double>::max();
        Character* temp;
        for (Character* character : this->warriors){
            if (leaderP->distance(character) < temp_dist && character->isAlive())
            {
                temp_dist = leaderP->distance(character);
                temp = character;
            }
        }

        return temp;
    }

    Character* Team::chooseTarget(Team* enemy_team)
    {
        if (enemy_team == nullptr)
        {
            throw std::invalid_argument("nullptr");
        }
        if (enemy_team->stillAlive() <= 0)
        {
            return nullptr;
        }
        double temp_dist = std::numeric_limits<double>::max();
        Character* temp = nullptr; // Initialize temp to nullptr
        for (Character* character : enemy_team->getWarriors())
        {
            if (this->leaderP->distance(character) < temp_dist && character->isAlive())
            {
                temp_dist = this->leaderP->distance(character); // Update temp_dist with the new minimum distance
                temp = character; // Assign the selected character to temp
            }
        }
        return temp;
    }


    

    int Team::stillAlive()
    {
        int count = 0;
        for (Character* warrior : this->warriors)
        {
            if (warrior->isAlive())
            {
                count++;
            }
        }
        return count;
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




}
