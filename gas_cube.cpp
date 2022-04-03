//
// Created by Stepan on 29.03.2022.
//
// Implementation of "gas_cube" methods

#include "gas_cube.h"
#include <iostream>


gas_cube::gas_cube(std::list<molecule *>& gas_in_cube, int i, int j, int k, int x, int y, int z, float a): gas_in_cube(gas_in_cube), i(i),
j(j), k(k), a(a), x(x), y(y), z(z){
}


void gas_cube::append_molecule(molecule* m) {
    gas_in_cube.push_back(m);
}

void gas_cube::update(double time, sf::RenderWindow &w) {
    for(auto it = gas_in_cube.begin();it!=gas_in_cube.end();it++) {
        for (auto it1 = gas_in_cube.begin(); it1 != gas_in_cube.end(); it1++) {
            if (it != it1) {
                if (((*it)->getPosition() - (*it1)->getPosition()).module() < (*it)->getRadius() * 2) {
                    if ((((*it)->getPosition() - (*it1)->getPosition()).module() -
                            (((*it)->getRadius() + (*it)->getRadius()))) < 0.) {
                        (*it)->Collision(*(*it1));
                    }
                }
            }
        }
//      std::cout << (*it)->getPosition().x << "/" << (*it)->getPosition().y << std::endl;
    }

    for(auto it = gas_in_cube.begin();it!=gas_in_cube.end();){
        if ((*it)->getPosition().x < 0.) {
            if (walls[0] == nullptr) {
                (*it)->x_wall_collision();
            } else {
                std::cout << "erased" << std::endl;
                vector pos = (*it)->getPosition();
                pos.x += a;
                (*it)->setLocation(pos);
                (walls[0])->append_molecule(*it);
                auto eraser = it;
                it++;
                gas_in_cube.erase(eraser);
                continue;
            }
        }

        if ((*it)->getPosition().x > a) {
            if (walls[1] == nullptr) {
                (*it)->x_wall_collision();
            } else {
                std::cout << "erased" << std::endl;
                vector pos = (*it)->getPosition();
                pos.x -= a;
                (*it)->setLocation(pos);
                (walls[1])->append_molecule(*it);
                auto eraser = it;
                it++;
                gas_in_cube.erase(eraser);
                continue;

            }
        }

        if ((*it)->getPosition().y < 0.) {
            if (walls[2] == nullptr) {
                (*it)->y_wall_collision();
            } else {
                std::cout << "erased" << std::endl;
                vector pos = (*it)->getPosition();
                pos.y += a;
                (*it)->setLocation(pos);
                (walls[2])->append_molecule(*it);
                auto eraser = it;
                it++;
                gas_in_cube.erase(eraser);
                continue;
            }
        }

        if ((*it)->getPosition().y > a) {
            if (walls[3] == nullptr) {
                (*it)->y_wall_collision();
            } else {
                std::cout << "erased" << std::endl;
                vector pos = (*it)->getPosition();
                pos.y -= a;
                (*it)->setLocation(pos);
                (walls[3])->append_molecule(*it);
                auto eraser = it;
                it++;
                gas_in_cube.erase(eraser);
                continue;
            }
        }

        if ((*it)->getPosition().z < 0.) {
            if (walls[4] == nullptr) {
                (*it)->z_wall_collision();
            } else {
                std::cout << "erased" << std::endl;
                vector pos = (*it)->getPosition();
                pos.z += a;
                (*it)->setLocation(pos);
                (walls[4])->append_molecule(*it);
                auto eraser = it;
                it++;
                gas_in_cube.erase(eraser);
                continue;
            }
        }

        if ((*it)->getPosition().z > a) {
            if (walls[5] == nullptr) {
                (*it)->z_wall_collision();
            } else {
                std::cout << "erased" << std::endl;
                vector pos = (*it)->getPosition();
                pos.z -= a;
                (*it)->setLocation(pos);
                (walls[5])->append_molecule(*it);
                auto eraser = it;
                it++;
                gas_in_cube.erase(eraser);
                continue;
            }
        }
        it++;
    }

    for(auto & element: gas_in_cube){
        element->update(time);
        element->draw(w,i,j,k,a);
    }
    sf::Vertex square[]{
        sf::Vertex(sf::Vector2f(i*a, j*a)),
        sf::Vertex(sf::Vector2f((i+1)*a, j*a)),
        sf::Vertex(sf::Vector2f((i+1)*a, (j+1)*a)),
        sf::Vertex(sf::Vector2f(i*a, (j+1)*a))
    };
    w.draw(square,4,sf::LinesStrip);
}

std::vector<gas_cube*>* gas_cube::getWalls() {
    return &walls;
}

unsigned gas_cube::getSize() {
    return gas_in_cube.size();
}