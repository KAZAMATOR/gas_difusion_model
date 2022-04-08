//
// Created by Stepan on 27.03.2022.
//
// Implementation of "point" methods

#include "point.h"


point::point(vector location, sf::Color color) {
    p.setPosition(location.x, location.y);
    p.setSize({1,1});
    p.setFillColor(color);

}

void point::setPosition(vector location) {
    p.setPosition(location.x, location.y);
}

void point::draw(sf::RenderWindow &w,int i,int j,int k, double a){
    p.setPosition({static_cast<float>(p.getPosition().x + i*a), static_cast<float>(p.getPosition().y + j*a)});
    w.draw(p);
}


