//
// Created by Stepan on 27.03.2022.
//
// Class that combines motion physics and particle rendering together

#ifndef MY_GAS_MOLECULE_H
#define MY_GAS_MOLECULE_H


#include "particle.h"
#include "point.h"

class molecule :public particle, public point{
private:

    //flag to separate particles into 2 gases
    bool diffusion_flag;
public:
    molecule(double mass, double radius, vector position, vector v, sf::Color color, bool d_flag);

    void setLocation(vector location);

    bool isDiffusionFlag() const;

    //method to update molecule position
    void update(double time, std::stringstream& out, bool flag, int i, int j, int k, double a);

    //method to update molecule image
    void draw(sf::RenderWindow &w, int i, int j, int k,double a) override;

    //methods to revers x,y,z components of molecule velocity
    void x_wall_collision(double a);

    void y_wall_collision(double a);

    void z_wall_collision(double a);
};

#endif //MY_GAS_MOLECULE_H
