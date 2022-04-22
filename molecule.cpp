//
// Created by Stepan on 27.03.2022.
//
// Implementation of "molecule" methods

#include <iostream>
#include "molecule.h"
#include <sstream>


molecule::molecule(double mass, double radius, vector position, vector v, sf::Color color, bool d_flag) : particle(mass, radius, position, v),
                                                                                             point(position, color), diffusion_flag(d_flag){}

void molecule::setLocation(vector location){
    particle::setPosition(location);
    point::setPosition(location);
}

void molecule::update(double time, std::stringstream& out, bool flag, int i, int j, int k, double a) {
    move(time);
    point::setPosition(position);
    if(flag){
        out << getPosition().x + a*i << " " << getPosition().y + a*j << " "
        << getPosition().z + a*k << " " << diffusion_flag << std::endl;
    }
}

void molecule::draw(sf::RenderWindow &w,int i, int j, int k,double a) {
    point::draw(w,i,j,k,a);
}

void molecule::x_wall_collision(double a) {
    if(position.x<0)position.x = 0;
    if(position.x>a)position.x = a;
    v.x *= -1;
}

void molecule::y_wall_collision(double a) {
    if(position.y<0)position.y = 0;
    if(position.y>a)position.y = a;
    v.y *= -1;
}

void molecule::z_wall_collision(double a) {
    if(position.z<0)position.z = 0;
    if(position.z>a)position.z = a;
    v.z *= -1;
}

bool molecule::isDiffusionFlag() const {
    return diffusion_flag;
}



