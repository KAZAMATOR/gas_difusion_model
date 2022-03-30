//
// Created by Stepan on 27.03.2022.
//

#ifndef MY_GAS_MOLECULE_H
#define MY_GAS_MOLECULE_H

#pragma once

#include "particle.h"
#include "point.h"

class molecule :public particle, public point{
public:
    molecule(double mass, double radius, vector position, vector v, sf::Color color);

    void setLocation(vector location);

    void update(double time);

    void draw(sf::RenderWindow &w, int i, int j, int k,double a) override;

    void x_wall_collision();

    void y_wall_collision();

    void z_wall_collision();
};


#endif //MY_GAS_MOLECULE_H
