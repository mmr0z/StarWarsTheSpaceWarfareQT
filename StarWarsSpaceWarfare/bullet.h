#pragma once
#include "player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite
{
public:
    Bullet();

    virtual void Shoot(double elapsed);
    void SetSpeed(double sx, double sy);
    void ShootLeft(double elapsed, Player &player);
    void ShootRight(double elapsed, Player &player);
    void ShootToTarget();

protected:
    double speed_x;
    double speed_y;

};
