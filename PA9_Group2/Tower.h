
//Class Definition File for the base Tower

#pragma once


#include "Projectile.h"

#include <SFML/Graphics.hpp>

#include <string>

#define NUM_TOWERS 3

enum TowerType
{
    TURRET,
    NONE
};


class Tower
{
protected:
    sf::Vector2f position;

    std::string name;
    TowerType type;

    double range; //Pixels

    int attSpeed; //Shots per minute
    int coolDownTime; //In seconds
    int damage;

    bool activeStatus = true;
    sf::Clock clock;
    sf::Time lastFireTime;

    void update_status(void)
    {
        if ((clock.getElapsedTime() - lastFireTime).asSeconds() < coolDownTime)
            activeStatus = false;
        else
            activeStatus = true;
    }

public:

    Tower()
    {
        position = { 0, 0 };
        name = "Tower";
        type = NONE;
    }

    Tower(sf::Vector2f initPosition)
    {
        clock.restart();
        lastFireTime = clock.getElapsedTime();
        position = initPosition;

        coolDownTime = 60 / attSpeed;
    }

    double get_range(void)
        { return range; }

    int get_attack_speed(void)
        { return attSpeed; }

    void fire(void)
        { lastFireTime = clock.getElapsedTime(); }

    sf::Vector2f getPosition()
        { return position; }

    int getDamage(void)
        { return damage; } 

    sf::Vector2f get_position(void)
        { return position; }

    std::string get_name(void)
        { return name; }

    TowerType get_type(void)
        { return type; }

    bool is_active(void)
    {
        update_status();
        return activeStatus;
    }
};

