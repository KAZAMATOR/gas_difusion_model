//
// Created by Stepan on 27.03.2022.
//
// Class that combines motion physics and particle rendering together

#ifndef MY_GAS_MOLECULE_H
#define MY_GAS_MOLECULE_H

#pragma once

#include "particle.h"
#include "point.h"

class molecule :public particle, public point{
private:

    //flag to separate particles into 2 gases
    bool diffusion_flag;
public:
    molecule(double mass, double radius, vector position, vector v, sf::Color color, bool d_flag);

    void setLocation(vector location);

    //method to update molecule position
    void update(double time, std::fstream& out, bool flag);

    //method to update molecule image
    void draw(sf::RenderWindow &w, int i, int j, int k,double a) override;

    //methods to revers x,y,z components of molecule velocity
    void x_wall_collision();

    void y_wall_collision();

    void z_wall_collision();
};

#endif //MY_GAS_MOLECULE_H
