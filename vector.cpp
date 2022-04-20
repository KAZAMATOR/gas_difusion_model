//
// Created by Stepan on 25.03.2022.
//
// Implementation of "vector" methods and operators
#include <iostream>
#include <cmath>
#include "vector.h"

vector::vector(): x(0.), y(0.), z(0.){};

vector::vector(double x, double y, double z): x(x), y(y), z(z){}

double vector::getLen2() const{
    return (x*x + y*y + z*z);
}

double vector::module() const {
    return std::sqrt(getLen2());
}

vector vector::operator+(vector rhs) const {
    return {x+rhs.x, y+rhs.y, z+rhs.z};
}

vector vector::operator-(vector rhs) const {
    return {x - rhs.x, y - rhs.y, z - rhs.z};
}
vector vector::operator*(double a) const {
    return{x*a, y*a, z*a};
}

double vector::operator*(vector rhs) const{
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

vector operator*(double a, vector v){
    return {v.x*a, v.y*a, v.z*a};
}

