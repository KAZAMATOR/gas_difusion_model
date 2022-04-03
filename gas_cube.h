//
// Created by Stepan on 29.03.2022.
//
// Class for storing and processing a large number of molecules located in a certain territory of our volume.
// Later it is used to create a large cube (main volume).
// Such a complex structure was created for the further implementation of parallel programming.

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

    //contain links to neighboring cubes
    std::vector<gas_cube*> walls;
public:
    gas_cube() = default;
    gas_cube(std::list<molecule*>& gas_in_cube, int i, int j, int k, int x, int y, int z, float a);

    std::vector<gas_cube*>* getWalls();

    //combines the functions of updating position and drawing,
    //if the molecule is outside the cube, it either hits the wall or is transferred to another cube,
    //depending on the presence of a neighboring cube on that side
    //(the function also draws the borders of the cube)
    void update(double time, sf::RenderWindow& w);

    void append_molecule(molecule* m);

    unsigned getSize();
};


#endif //MAIN_CPP_GAS_CUBE_H
