
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
    std::ofstream out("C:\\Users\\Stepan\\Desktop\\my_gas\\gas_difusion_model\\data.txt",std::ios::app);

    //set the size and number of small cubes


    sf::RenderWindow window(sf::VideoMode(a*x, a*y), "Standard");
    //    3000000000.
    //create main_cube (x,y,z,a, mean_speed, molecules_per_gas_cube)
    main_cube MAIN = main_cube(x,y,z,a,mean_speed,molecules_per_gas_cube);

    //counter for set file output frequency
    int counter = 0;
    while (window.isOpen()) {
        counter++;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //change the speed
        double time = 10e-4;

        window.clear();

        if(counter/100 == 0 and out.is_open()){
            //std::cout << "tick" << std::endl;
            counter = 0;
            MAIN.update(time,out, true);
        }
        else MAIN.update(time,out, false);
        MAIN.draw(window);
        window.display();
    }

}