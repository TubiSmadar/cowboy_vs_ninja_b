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
        int still_alive;

    public:
        ~Team2() override = default;
        Team2(const Team2&) = default;
        Team2& operator=(const Team2&) = default;
        Team2(Team2&&) = default;
        Team2& operator=(Team2&&) = default;        Team2(Character* t2LeaderP);
        void add(Character* warrior) override;
        int stillAlive() override;

    };
}

#endif // TEAM2_HPP
