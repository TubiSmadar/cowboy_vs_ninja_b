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
        ~SmartTeam() override = default;
        SmartTeam(const SmartTeam&) = default;
        SmartTeam& operator=(const SmartTeam&) = default;
        SmartTeam(SmartTeam&&) = default;
        SmartTeam& operator=(SmartTeam&&) = default;        
        SmartTeam(Character* t2LeaderP);

        // void add(Character* fighter_to_add) override;
        void attack(Team* enemy_team) override;
        Character* chooseTarget(Team* other) override;

    };
}

#endif // SMART_TEAM_HPP
