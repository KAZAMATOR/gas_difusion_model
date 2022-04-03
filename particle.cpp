//
// Created by Stepan on 25.03.2022.
//
// Implementation of "particle" methods
#include "particle.h"
#include <cmath>
#include <iostream>

particle::particle(double mass, double radius, vector position ,vector v): mass(mass), radius(radius), position(position), v(v){}



double particle::getMass() const {
    return mass;
}

double particle::getRadius() const {
    return radius;
}

const vector &particle::getPosition() const {
    return position;
}

const vector &particle::getV() const {
    return v;
}

void particle::setPosition(const vector &position) {
    particle::position = position;
}

void particle::setV(const vector &v) {
    this->v = v;
}

void particle::Collision(particle &p2) {

    std::cout << v.module()*v.module() + p2.getV().module()*p2.getV().module() << std::endl;

    vector dist = p2.getPosition() - position;
    double l = std::sqrt(dist.getLen2());
    position = position - ((radius + p2.getRadius())/l - 1)*dist;
    vector v1 = v;
    v = v - (v - p2.getV())*(position - p2.position) / (position - p2.position).getLen2() * (position - p2.position);
    p2.setV(p2.getV() - (p2.getV() - v1)*(p2.position - position) / (p2.position - position).getLen2() * (p2.position - position));
    std::cout << "collision" << std::endl;


    std::cout << v.module()*v.module() + p2.getV().module()*p2.getV().module() << std::endl;
}

void particle::move(double time) {
    position = position + v*time;
}
