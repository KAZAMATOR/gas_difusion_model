//
// Created by Stepan on 29.03.2022.
//
// Class for storing and processing a large number of molecules located in a certain territory of our volume.
// Later it is used to create a large cube (main volume).
// Such a complex structure was created for the further implementation of parallel programming.

#ifndef MAIN_CPP_GAS_CUBE_H
#define MAIN_CPP_GAS_CUBE_H


#include <vector>
#include "molecule.h"
#include <list>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include <sstream>


class gas_cube {
private:
    int i,j,k;
    int x,y,z;
    int m_per_cube;
    float a;
    std::stringstream join_string;
    std::list<molecule*> gas_in_cube;

    //contain links to neighboring cubes
    std::vector<gas_cube*> walls;
public:
    gas_cube() = default;
    gas_cube(std::list<molecule*>& gas_in_cube, int i, int j, int k, int x, int y, int z, int m_per_cube, float a);

    std::vector<gas_cube*>* getWalls();

    void append_molecule(molecule* m);

    unsigned getSize();
    unsigned getRedSize();

    const std::stringstream &getJoinString() const;

    void setGasInCube0();

    //combines the functions of updating position and drawing,
    //if the molecule is outside the cube, it either hits the wall or is transferred to another cube,
    //depending on the presence of a neighboring cube on that side
    //(the function also draws the borders of the cube)
    void update(double time, std::ofstream& out, bool flag, double& m_wall_counter);
    void update_all(std::vector<std::thread*>& threads,double time, std::ofstream& out, bool flag, double& m_wall_counter);

    void draw( sf::RenderWindow& w, bool& flag);
};


#endif //MAIN_CPP_GAS_CUBE_H
