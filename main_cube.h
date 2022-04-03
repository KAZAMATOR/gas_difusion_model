//
// Created by Stepan on 29.03.2022.
//
// Class of the main cube, which combines several small

#ifndef MAIN_CPP_MAIN_CUBE_H
#define MAIN_CPP_MAIN_CUBE_H

#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "gas_cube.h"


class main_cube {
private:
    std::vector<std::vector<std::vector<gas_cube*>>> main_cube_3d;
    double a;
    double mean_speed;
    int molecule_per_gas_cube;
    int x,y,z;
public:
    main_cube(int x, int y, int z, double a,double mean_speed, int molecule_per_gas_cube);

    //method to update all small cubes that contains in main_cube_3d
    void update(double time, sf::RenderWindow &w);
};


#endif //MAIN_CPP_MAIN_CUBE_H
