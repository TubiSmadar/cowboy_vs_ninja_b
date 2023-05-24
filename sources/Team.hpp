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
        virtual ~Team();
        Team(const Team&) = default;
        Team& operator=(const Team&) = default;
        Team(Team&&) = default;
        Team& operator=(Team&&) = default;        
        virtual void add(Character *warrior);
        virtual void attack(Team *enemy_team);
        virtual int stillAlive();
        void print();
        vector<Character *> getWarriors()
        {
            return warriors;
        }
        void setWarriors(Character * fighter_to_add)
        {
            warriors.push_back(fighter_to_add);
        }
        void remove(Character *warrior);
        Character *getLeaderP();
        void setLeaderP(Character* leaderP){this->leaderP = leaderP;}
        Character* chooseLeader(Character* leaderP);
        virtual Character* chooseTarget(Team* enemy_team);
        bool isLeader(Character* warrior);

        size_t size();
    };
}

#endif // TEAM_HPP
