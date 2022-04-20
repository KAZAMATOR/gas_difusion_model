//
// Created by Stepan on 09.04.2022.
//

#include "parser.h"
#include <iostream>



parser::parser(main_cube &cube, double &elapse_time) : cube(cube), x(cube.getX()), y(cube.getY()), z(cube.getZ()),
molecule_per_cube(cube.getMoleculePerGasCube()), a(cube.getA()), elapse_time(elapse_time){
    pressure = 0.;
}

void parser::pressure_pars() {

    double s = 2*x*y + 2*x*z + 2*y*z;

    std::cout << "PRESSURE: " << ((pressure/elapse_time)/(a*a))/(double(s)) << std::endl;
}

double &parser::getMWallCounter(){
    return pressure;
}

void parser::concentration_pars() {

}


void parser::diff_coef_pars() {
    int red_left_quantity = 0;
    int red_right_quantity = 0;
    int blue_left_quantity = 0;
    int blue_right_quantity = 0;
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            for(int k = 0;k<z;k++){
                if(i<x/2){
                    red_left_quantity += cube.getMainCube3D()[i][j][k]->getRedSize();
                    blue_left_quantity += cube.getMainCube3D()[i][j][k]->getSize() -
                            this->cube.getMainCube3D()[i][j][k]->getRedSize();
                }
                else{
                    red_right_quantity += cube.getMainCube3D()[i][j][k]->getRedSize();
                    blue_right_quantity += cube.getMainCube3D()[i][j][k]->getSize() -
                                          this->cube.getMainCube3D()[i][j][k]->getRedSize();
                }
            }
        }
    }
    red_n_vector.push_back({red_left_quantity, red_right_quantity});
    std::cout << red_left_quantity - red_right_quantity << std::endl;
}
