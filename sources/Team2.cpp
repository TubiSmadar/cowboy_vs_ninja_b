#include <iostream>
#include <cmath>

#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *t2LeaderP) : Team(t2LeaderP)
    {
        
    }

    int Team2::stillAlive() {
        int count = 0;
        for (Character* warrior : this->getWarriors())
        {
            if (warrior->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team2::add(Character* fighter_to_add) {
        if (fighter_to_add != nullptr && fighter_to_add->isAlive() && !fighter_to_add->getInTeam() && getWarriors().size() < 10)
        {
            this->setWarriors(fighter_to_add);
            fighter_to_add->setInTeam(true);
        }
        else
        {
            throw runtime_error("Can't add this Character!");
        }
    }

}


