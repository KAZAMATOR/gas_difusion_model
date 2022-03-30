//
// Created by Stepan on 25.03.2022.
//

#ifndef MY_GAS_VECTOR_H
#define MY_GAS_VECTOR_H

#pragma once

class vector{
public:
    double x,y,z;

    //constructors
    vector(double x, double y, double z);
    vector();

    [[nodiscard]] double getLen2() const;

    [[nodiscard]] double module() const;

    vector operator+(vector rhs) const;

    vector operator-(vector rhs) const;

    vector operator*(double a) const;

    double operator*(vector rhs) const;
};

vector operator*(double a, vector v);


#endif //MY_GAS_VECTOR_H
