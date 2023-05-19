#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;
using namespace std;

#include <random>
#include <chrono>

TEST_CASE("Test Point") {
    CHECK_NOTHROW(Point p1(3, 4));
    CHECK_NOTHROW(Point p2(0, 0));
    Point p1(3, 4);
    Point p2(0, 0);
    CHECK_EQ(p1.distance(p2), 5.0);
}

TEST_CASE("Test Character") {
    Point p1(0.0, 0.0);
    Point p2(1.0, 1.0);
    Character character("John", p1);
    CHECK(character.isAlive());
    Character otherCharacter("Jane", p2);
    double dist = character.distance(&otherCharacter);
    CHECK_EQ(dist, 0.0);
    CHECK_EQ(character.getName(), "");
    Point location = character.getLocation();
    CHECK_EQ(character.print(), "");
    CHECK_EQ(character.getHitpoints(), 0);
    character.moveTowards(p2, 1.0);
    character.hit(150);
    CHECK(!character.isAlive());
}

TEST_CASE("Test Ninja") {
    Point p1(0, 0);
    Ninja ninja("Ninja1", p1);
    CHECK_NOTHROW(Ninja ninja("Ninja1", p1));
    CHECK_NOTHROW(Ninja ninja("Ninja1", p1,100,8));
    CHECK_EQ(ninja.getName(), "Ninja1");
    CHECK_EQ(ninja.isAlive(), true);

}

TEST_CASE("Test Cowboy") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    CHECK_EQ(cowboy.getName(), "Cowboy1");
    CHECK_EQ(cowboy.isAlive(), true);
    CHECK_EQ(cowboy.hasboolets(), true);
    SUBCASE("Test shoot") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        cowboy.reload();
        CHECK(cowboy.hasboolets());
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        cowboy.shoot(&cowboy2);
        CHECK_FALSE(cowboy.hasboolets()); //empty bullet stack.
    }
}

TEST_CASE("Test OldNinja") {
    Point p1(0, 0);
    OldNinja oldNinja("OldNinja", p1);
    CHECK_EQ(oldNinja.getName(), "OldNinja");
    CHECK_EQ(oldNinja.isAlive(), true);
}

TEST_CASE("Test TrainedNinja") {
    Point p1(0, 0);
    TrainedNinja trainedNinja("TrainedNinja1", p1);
    CHECK_EQ(trainedNinja.getName(), "TrainedNinja1");
    CHECK_EQ(trainedNinja.isAlive(), true);
}

TEST_CASE("Test YoungNinja") {
    Point p1(0, 0);
    YoungNinja youngNinja("YoungNinja1", p1);
    CHECK_EQ(youngNinja.getName(), "YoungNinja1");
    CHECK_EQ(youngNinja.isAlive(), true);
}

TEST_CASE("Test Team") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    Team team1(&cowboy);
    CHECK_EQ(team1.stillAlive(), 1);

    SUBCASE("Test team attack") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        Team2 team2(&cowboy2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2); 
        CHECK_EQ(team2.stillAlive(), 0);
    }
        SUBCASE("Test adding new character") {
        Cowboy *cowboy2 = new Cowboy("Cowboy2", Point(1, 1));
        team1.add(cowboy2);
        CHECK_EQ(team1.stillAlive(), 2);

    }
}

TEST_CASE("Test Team2") {
    Point p1(0, 0);
    Cowboy cowboy1("Cowboy1", p1);
    Team2 team1(&cowboy1);
    CHECK_EQ(team1.stillAlive(), 1);

    SUBCASE("Test attack") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        Team2 team2(&cowboy2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        CHECK_EQ(team2.stillAlive(), 0);
    }
    SUBCASE("Test adding new character") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        team1.add(&cowboy2);
        CHECK_EQ(team1.stillAlive(), 2);
    }
}

TEST_CASE("Test SmartTeam") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy", p1);
    SmartTeam team1(&cowboy);
    CHECK_EQ(team1.stillAlive(), 1);

    SUBCASE("Test attack") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        SmartTeam team2(&cowboy2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        team1.attack(&team2);
        CHECK_EQ(team2.stillAlive(), 0);
    }

    SUBCASE("Test adding new character") {
        Cowboy *cowboy2 = new Cowboy("Cowboy2", Point(1, 1));
        team1.add(cowboy2);
        CHECK_EQ(team1.stillAlive(), 2);
    }
}

TEST_CASE("Test Cowboy reloading") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    cowboy.shoot(&cowboy);
    CHECK_EQ(cowboy.hasboolets(), false);
    cowboy.reload();
    CHECK_EQ(cowboy.hasboolets(), true);
}

TEST_CASE("Test Ninja moving") {
    Point p1(0, 0);
    Point p2(1, 1);
    Ninja ninja("Ninja1", p1);
    Cowboy cowboy("Cowboy1", p2);
    ninja.move(&cowboy);

}

TEST_CASE("Test SmartTeam order") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy1", p1);
    Cowboy cowboy2("Cowboy2", p2);
    SmartTeam team(&cowboy);
    team.add(&cowboy2);
    CHECK_EQ(team.getByOrder()->getName(), "Cowboy2");
}

TEST_CASE("Test ninja slashing") {
    Point p1(0, 0);
    Point p2(1, 1);
    Ninja ninja("Ninja1", p1);
    Cowboy cowboy("Cowboy1", p2);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    CHECK_EQ(cowboy.isAlive(), false);
}

TEST_CASE("Test team attack") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy1", p1);
    OldNinja ninja("bad",p2);
    Team team1(&cowboy);
    Team team2(&ninja);
    team1.attack(&team2);
    team1.attack(&team2);
    team1.attack(&team2);
    CHECK_EQ(team2.stillAlive(), 0);
}

TEST_CASE("Testing Game")
{
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy",p1);
    OldNinja ninja("Ninja",p2);
    Team teamA(&cowboy);
    Team teamB(&ninja);

    while(teamA.stillAlive() > 0 && teamB.stillAlive() > 0)
    {
        CHECK_NOTHROW(teamA.attack(&teamB));
        CHECK_NOTHROW(teamB.attack(&teamA));
    }
    CHECK_NOTHROW(teamA.print());
    CHECK_NOTHROW(teamB.print());
}

TEST_CASE("Test character hitpoints") {
    Point p1(0, 0);
    Character character("Character", p1, 99);
    CHECK_EQ(character.isAlive(), true);
    character.hit(33);
    CHECK_EQ(character.isAlive(), true);
    character.hit(33);
    CHECK_EQ(character.isAlive(), true);
    character.hit(33);
    CHECK_EQ(character.isAlive(), false);    
    character.hit(33);
    CHECK_EQ(character.isAlive(), false);
}




