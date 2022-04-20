//
// Created by Stepan on 25.03.2022.
//
// This is some math to further handle collisions and particle motion

#ifndef MY_GAS_VECTOR_H
#define MY_GAS_VECTOR_H

class vector{
public:
    double x,y,z;

    vector(double x, double y, double z);
    vector();

    //returns the square of the vector length
    [[nodiscard]] double getLen2() const;

    //returns the vector length
    [[nodiscard]] double module() const;

    //few overloaded operators
    vector operator+(vector rhs) const;

    vector operator-(vector rhs) const;

    vector operator*(double a) const;

    //scalar multiplication operator
    double operator*(vector rhs) const;
};

vector operator*(double a, vector v);


#endif //MY_GAS_VECTOR_H
