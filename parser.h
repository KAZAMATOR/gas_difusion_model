//
// Created by Stepan on 09.04.2022.
//

#ifndef MAIN_CPP_PARSER_H
#define MAIN_CPP_PARSER_H

#include "main_cube.h"
#include <vector>


class parser {

private:
    main_cube& cube;
    int x,y,z;
    int molecule_per_cube;
    double a;
    double & elapse_time;
    double pressure;
    int red_left_quantity, red_right_quantity, blue_left_quantity, blue_right_quantity;
    std::vector<std::pair<int, int>> red_n_vector;
public:

    explicit parser(main_cube &cube, double &time);

    double &getMWallCounter();

    void pressure_pars();

    void diff_coef_pars();

    void concentration_pars();

};


#endif //MAIN_CPP_PARSER_H
