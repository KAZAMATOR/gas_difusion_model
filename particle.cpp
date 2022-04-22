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
    vector dist = p2.getPosition() - position;
    double l = std::sqrt(dist.getLen2());
    position = position - ((radius + p2.getRadius())/l - 1)*dist;
    vector p1 = v*mass;
    v = (v*mass - (v*mass - p2.getV()*p2.getMass())*(position - p2.position) / (position - p2.position).getLen2() * (position - p2.position))*(1/mass);
    p2.setV((p2.getV()*p2.getMass() - (p2.getV()*p2.getMass() - p1)*(p2.position - position) / (p2.position - position).getLen2() * (p2.position - position))*(1/p2.getMass()));

}

void particle::move(double time) {
    position = position + v*time;
    v.y += 10;
}
