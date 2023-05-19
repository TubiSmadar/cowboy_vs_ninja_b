#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

using namespace std;

namespace ariel
{
    class Team
    {
    private:
        vector<Character *> warriors;
        Character *leaderP;
        bool isMember(Character *character);

    public:
        Team(Character *leaderP);
        void add(Character *warrior);
        void attack(Team *enemy_team);
        int stillAlive();
        void print();
        virtual Character *getByOrder();

        void remove(Character *warrior);
        Character *getLeaderP();
        size_t size();
    };
}

#endif // TEAM_HPP
