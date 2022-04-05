
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "molecule.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include "main_cube.h"
#include <fstream>


int main(){
    remove("C:\\Users\\Stepan\\Desktop\\my_gas\\gas_difusion_model\\data.txt");
    std::fstream out("C:\\Users\\Stepan\\Desktop\\my_gas\\gas_difusion_model\\data.txt",std::ios::app);

    //set the size and number of small cubes
    double a = 150;
    int x = 8;
    int y = 4;
    int z = 1;

    sf::RenderWindow window(sf::VideoMode(a*x, a*y), "Standard");

    //create main_cube (x,y,z,a, mean_speed, molecules_per_gas_cube)
    main_cube MAIN = main_cube(x,y,z,a,3000000000.,100);

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
        double time = 0.0000000001;

        window.clear();

        if(counter/10 == 0 and out.is_open()){
            counter = 0;
            MAIN.update(time,out, true);
        }
        else MAIN.update(time,out, false);

        MAIN.draw(window);
        window.display();
    }
}