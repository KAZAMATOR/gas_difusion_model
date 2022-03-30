//
// Created by Stepan on 25.03.2022.
//

#ifndef MY_GAS_PARTICLE_H
#define MY_GAS_PARTICLE_H

#pragma once

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

    [[nodiscard]] double getMass() const;

    [[nodiscard]] double getRadius() const;

    [[nodiscard]] const vector &getPosition() const;

    [[nodiscard]] const vector &getV() const;

    void setPosition(const vector &position);

    void setV(const vector &v);

    void Collision(particle& prt2);

    void move(double time);

};


#endif //MY_GAS_PARTICLE_H
