//
// Created by Stepan on 27.03.2022.
//

#include <iostream>
#include "molecule.h"


molecule::molecule(double mass, double radius, vector position, vector v, sf::Color color) : particle(mass, radius, position, v),
                                                                                             point(position, color){}

void molecule::setLocation(vector location){
    particle::setPosition(location);
    point::setPosition(location);
}

void molecule::update(double time) {
    move(time);
    point::setPosition(position);
//    std::cout << v.x << "/" << v.y << std::endl;
}

void molecule::draw(sf::RenderWindow &w,int i, int j, int k,double a) {
    point::draw(w,i,j,k,a);
}

void molecule::x_wall_collision() {
    v.x = -v.x;
}

void molecule::y_wall_collision() {
    v.y = -v.y;
}

void molecule::z_wall_collision() {
    v.z = -v.z;
}

