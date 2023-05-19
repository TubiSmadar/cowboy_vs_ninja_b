#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <iostream>
#include <vector>
#include "Team.hpp"

using namespace std;

namespace ariel
{
    class Team2 : public Team
    {
    private:


    public:
        Team2(Character* t2LeaderP);
        Character* getByOrder() override;

    };
}

#endif // TEAM2_HPP
