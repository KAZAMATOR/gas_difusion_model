//
// Created by Stepan on 25.03.2022.
//
// Class that implements the physical part of the molecule, movement and collision

#ifndef MY_GAS_PARTICLE_H
#define MY_GAS_PARTICLE_H

#include "vector.h"

class particle{
protected:
    double mass;
    double radius;
    vector position;
    vector v;
public:

    particle(double mass,double radius,vector position,vector v);
    particle() = default;

    //getters and setters
    [[nodiscard]] double getMass() const;

    [[nodiscard]] double getRadius() const;

    [[nodiscard]] const vector &getPosition() const;

    [[nodiscard]] const vector &getV() const;

    void setPosition(const vector &position);

    void setV(const vector &v);

    //collision and movement methods
    void Collision(particle& prt2);

    void move(double time);
};


#endif //MY_GAS_PARTICLE_H
