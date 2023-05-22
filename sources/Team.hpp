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
        int teamSize;

    public:
        Team(Character *leaderP);
        ~Team();
        void add(Character *warrior);
        void attack(Team *enemy_team);
        int stillAlive();
        void print();
        virtual Character *getByOrder();
        vector<Character *> getWarriors();
        void remove(Character *warrior);
        Character *getLeaderP();
        Character* chooseLeader(Character* leaderP);
        Character* chooseTarget(Team* enemy_team);
        bool isLeader(Character* warrior);

        size_t size();
    };
}

#endif // TEAM_HPP
