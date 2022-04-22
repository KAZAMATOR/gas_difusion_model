#include "parser.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "molecule.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include "main_cube.h"
#include <fstream>
#include <list>



int main(){

    //change the speed
    double time = 10e-4;
    double elapse_time = 0.;

    std::cout << "STARTING THE PROGRAM" << std::endl;
    std::cout << "||||||||||||||||||||" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "please enter parameters:" << std::endl;
    std::cout << "||||||||||||||||||||" << std::endl;

    double a;
    double T;
    double mean_speed;
    int x;
    int y;
    int z;
    int molecules_per_gas_cube;

    std::cout << "mean gas T (K): " << std::endl;
    std::cin >> T;
    mean_speed = std::sqrt(3.*8.314462618*T/0.02897);
    std::cout << "molecules_per_gas_cube : " << std::endl;
    std::cin >> molecules_per_gas_cube;
    std::cout << "main cube dimension (x,y,z) : " << std::endl;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;
    std::cout << "dimension of one division : " << std::endl;
    std::cin >> a;
    std::cout << std::endl;

    remove("C:\\Users\\Stepan\\Desktop\\my_gas\\gas_difusion_model\\data.txt");
    std::ofstream out("C:\\Users\\Stepan\\Desktop\\my_gas\\gas_difusion_model\\data.txt",std::ios::binary);

    //set the size and number of small cubes


    sf::RenderWindow window(sf::VideoMode(a*x, a*y), "Standard");
    main_cube MAIN = main_cube(x,y,z,a,mean_speed,molecules_per_gas_cube);
    parser pars(MAIN,elapse_time);

    //counter for set file output frequency
    int counter = 0;
    while (window.isOpen()) {
        elapse_time += time;
        counter++;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        if(counter%100 == 0 and out.is_open()){
            counter = 0;
//            MAIN.update(time,out, true, pars.getMWallCounter());
            pars.diff_coef_pars();
        }
        else MAIN.update(time,out, true, pars.getMWallCounter());
        bool f = false;
        MAIN.draw(window, f);
        window.display();
//        pars.pressure_pars();

    }

}