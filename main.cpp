
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "molecule.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include "main_cube.h"

int main(){

    //set the size and number of small cubes
    double a = 200.;
    int x = 4;
    int y = 4;
    int z = 1;
    sf::RenderWindow window(sf::VideoMode(a*x, a*y), "Standard");

    //create main_cube (x,y,z,a, mean_speed, molecules_per_gas_cube)
    main_cube MAIN = main_cube(x,y,z,a,25.,100);

//    molecule m1 = molecule(1.,1.,{600.,200.,0.},{25.,-26.,0.},sf::Color::Red);
//    molecule m2 = molecule(1.,1.,{640.,160.,0.},{-1.,1.,0.},sf::Color::Blue);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //change the speed
        double time = 0.001;

        window.clear();

        MAIN.update(time,window);

        window.display();
    }
}