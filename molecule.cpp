//
// Created by Stepan on 27.03.2022.
//
// Implementation of "molecule" methods

#include <iostream>
#include "molecule.h"
#include <fstream>


molecule::molecule(double mass, double radius, vector position, vector v, sf::Color color, bool d_flag) : particle(mass, radius, position, v),
                                                                                             point(position, color), diffusion_flag(d_flag){}

void molecule::setLocation(vector location){
    particle::setPosition(location);
    point::setPosition(location);
}

void molecule::update(double time, std::fstream& out, bool flag) {
    move(time);
    point::setPosition(position);
    if(flag){
        out << getPosition().x << " " << getPosition().y << " " << getPosition().z << std::endl;
    }
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



