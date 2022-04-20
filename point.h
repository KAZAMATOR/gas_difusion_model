//
// Created by Stepan on 27.03.2022.
//
// This is an elementary object that draws a particle with a size of 1 pixel

#ifndef MY_GAS_POINT_H
#define MY_GAS_POINT_H


#include <SFML/Graphics.hpp>
#include "vector.h"

class point {
private:
    sf::RectangleShape p;
public:

    point(vector location, sf::Color color);

    //method that sets the point position
    void setPosition(vector location);

    //method that draws the point
    virtual void draw(sf::RenderWindow &w, int i, int j, int k,double a);
};


#endif //MY_GAS_POINT_H
