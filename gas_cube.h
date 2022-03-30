//
// Created by Stepan on 29.03.2022.
//

#ifndef MAIN_CPP_GAS_CUBE_H
#define MAIN_CPP_GAS_CUBE_H

#pragma once

#include <vector>
#include "molecule.h"
#include <list>
#include <SFML/Graphics.hpp>


class gas_cube {
private:
    int i,j,k;
    int x,y,z;
    float a;
    std::list<molecule*> gas_in_cube;
    std::vector<gas_cube*> walls;
public:
    gas_cube() = default;
    gas_cube(std::list<molecule*>& gas_in_cube, int i, int j, int k, int x, int y, int z, float a);

    void update(double time, sf::RenderWindow& w);

    std::vector<gas_cube*>* getWalls();

    void append_molecule(molecule* m);

    unsigned getSize();
};


#endif //MAIN_CPP_GAS_CUBE_H
