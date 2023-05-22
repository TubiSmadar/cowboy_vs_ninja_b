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
