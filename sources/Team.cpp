#include <iostream>
#include <cmath>

#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leaderP)
    {
        this->leaderP = leaderP;
    }


    bool Team::isMember(Character *character)
    {
        return true;
    }
    void Team::add(Character *fighter_to_add)
    {
    }
    void Team::attack(Team *enemy_team)
    {
    }
    int Team::stillAlive()
    {
        return 0;
    }
    void Team::print()
    {
    }
    Character *Team::getByOrder()
    {
        return NULL;
    }

    void Team::remove(Character *fighter_to_remove)
    {

    }

    Character *Team::getLeaderP()
    {
        return NULL;
    }

    size_t Team::size()
    {
        return 0;
    }


}
