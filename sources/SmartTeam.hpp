#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include <iostream>
#include <vector>
#include "Team.hpp"

using namespace std;

namespace ariel
{
    class SmartTeam : public Team
    {
    private:


    public:
        SmartTeam(Character* t2LeaderP);
        Character* getByOrder() override;

    };
}

#endif // SMART_TEAM_HPP
