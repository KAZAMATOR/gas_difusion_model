//
// Created by Stepan on 27.03.2022.
//

#ifndef MY_GAS_POINT_H
#define MY_GAS_POINT_H

#pragma once

#include <SFML/Graphics.hpp>
#include "vector.h"

class point {
private:
    sf::RectangleShape p;
public:
    point(vector location, sf::Color color);

    void setPosition(vector location);

    virtual void draw(sf::RenderWindow &w, int i, int j, int k,double a);
};


#endif //MY_GAS_POINT_H
