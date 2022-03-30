
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "molecule.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include "main_cube.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Standard");

    main_cube MAIN = main_cube(2,2,2,100,25.,15);

//    molecule m1 = molecule(1.,1.,{600.,200.,0.},{25.,-26.,0.},sf::Color::Red);
//    molecule m2 = molecule(1.,1.,{640.,160.,0.},{-1.,1.,0.},sf::Color::Blue);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        double time = 0.0001;
        //регулируем скорость


        window.clear();

        MAIN.update(time,window);

//        if(std::abs((m1.getPosition() - m2.getPosition()).getLen2()) <  4.){
//            m1.Collision(m2);
//        }


//
//
//        m1.update(time);
//        m2.update(time);
//
//        m1.draw(window);
//        m2.draw(window);
//
//        std::cout << m1.getV().getLen2() + m2.getV().getLen2() << std::endl;
//        std::cout << m1.getV().x << "//" << m2.getV().x << std::endl;
        window.display();
    }
}