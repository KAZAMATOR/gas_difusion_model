//
// Created by Stepan on 29.03.2022.
//
// 1)Implementation of "main_cube" methods
// 2)Random generation function
// 3)small cube bond creator function

#include <SFML/Graphics.hpp>
#include "main_cube.h"
#include <list>
#include "vector.h"
#include <iostream>
#include <thread>
#include <functional>



//flag: true = coord_distribution,  false = speed_distribution
double particle_generator(std::mt19937_64& generator, double a, double mean_speed,bool flag, sf::Clock clock){
    auto coord_distribution = std::uniform_real_distribution<double>(0,a);
//    auto coord_distribution = std::uniform_int_distribution(0,int(a));
    auto speed_distribution = std::normal_distribution(mean_speed,mean_speed/2);
    //
    auto operator_distribution = std::uniform_int_distribution(0,1);

//    std::cout << current_time << std::endl;

    if(flag){
        return double(coord_distribution(generator));
    }
    if(operator_distribution(generator)){
        return double(speed_distribution(generator));
    }
    else{
        return -double(speed_distribution(generator));
    }
}

void cube_bond_creator(std::vector<std::vector<std::vector<gas_cube*>>>& main_cube_3d, gas_cube* cube,
                       int i, int j, int k, int x, int y, int z){
    (*(cube->getWalls())).resize(6);
    if(i == 0 or i == x-1){
        if(i == 0){
            (*(cube->getWalls()))[0] = nullptr;
        }
        if(i == x-1){
            (*(cube->getWalls()))[1] = nullptr;
        }
    }
    if(i!=0){(*(cube->getWalls()))[0] = main_cube_3d[i-1][j][k];}
    if(i!=x-1){(*(cube->getWalls()))[1] = main_cube_3d[i+1][j][k];}


    if(j == 0 or j == y-1){
        if(j == 0){
            (*(cube->getWalls()))[2] = nullptr;
        }
        if(j == y-1){
            (*(cube->getWalls()))[3] = nullptr;
        }
    }
    if(j!=0){(*(cube->getWalls()))[2] = main_cube_3d[i][j-1][k];}
    if(j!=y-1){(*(cube->getWalls()))[3] = main_cube_3d[i][j+1][k];}


    if(k == 0 or k == z-1){
        if(k == 0){
            (*(cube->getWalls()))[4] = nullptr;
        }
        if(k == z-1){
            (*(cube->getWalls()))[5] = nullptr;
        }
    }
    if(k!=0){(*(cube->getWalls()))[4] = main_cube_3d[i][j][k-1];}
    if(k!=z-1){(*(cube->getWalls()))[5] = main_cube_3d[i][j][k+1];}


}

main_cube::main_cube(int x, int y, int z, double a,double mean_speed, int molecule_per_gas_cube): a(a), x(x), y(y), z(z),
molecule_per_gas_cube(molecule_per_gas_cube), mean_speed(mean_speed){
    std::cout << "LOADING..." << std::endl;
    std::cout << "[:";
    main_cube_3d.resize(x);
    for(auto & element: main_cube_3d){
        element.resize(y);
        for(auto & i: element){
            i.resize(z);

        }
    }
    sf::Clock clock;
    double counter = 0.;
    int b = 1;
    auto current_time = clock.getElapsedTime().asMicroseconds();
    auto generator =  std::mt19937_64(current_time);
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            for(int k = 0;k<z;k++){
                std::list<molecule*> molecules_list;
                for(int l = 0;l<molecule_per_gas_cube;l++){
                    current_time = clock.getElapsedTime().asMicroseconds();

                    double f = particle_generator(generator,a,mean_speed, true, clock);
                    double n = particle_generator(generator,a,mean_speed, false, clock);
                    double g = particle_generator(generator,a,mean_speed, true, clock);
                    double m = particle_generator(generator,a,mean_speed, false, clock);
                    double h = particle_generator(generator,a,mean_speed, true, clock);
                    double c = particle_generator(generator,a,mean_speed, false, clock);

                    vector position = {f,g,0.};

//                    std::cout << "molecule_created" << std::endl;
//                    std::cout << position.x << "/" << position.y << "/" << position.z << std::endl;
                    vector v = {n,m,0.};
//                    std::cout << v.x << "/" << v.y << "/" << v.z << std::endl;

                    if(i<x/2)molecules_list.push_back(new molecule(1.,1.,position,v,sf::Color::Blue, true));
                    else{
                        molecules_list.push_back(new molecule(1.,1.,position,v,sf::Color::Red, false));
                    }
                }
                main_cube_3d[i][j][k] = new gas_cube(molecules_list,i,j,k,x,y,z,a);
                double divider = x*y*z;
                if(counter > b){
                    std::cout << "|";
                    b++;
                }
                counter += 32./divider;
            }
        }
    }
    std::cout << ":]" << std::endl;
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            for(int k = 0;k<z;k++){
                cube_bond_creator(main_cube_3d, main_cube_3d[i][j][k], i, j, k, x, y, z);
            }
        }
    }
    std::cout << "CUBE LOADED" << std::endl;
}


void main_cube::update(double time, std::ofstream& out, bool flag) {
    std::vector<std::thread*> threads;
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            for(int k = 0;k<z;k++){
               main_cube_3d[i][j][k]->update_all(threads,time,out,flag);
            }
        }
    }
    for(auto & element: threads){
        element->join();
        delete element;
    }
}

void main_cube::draw(sf::RenderWindow &w) {
//    unsigned s = 0;
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            for(int k = 0;k<z;k++){
                main_cube_3d[i][j][k]->draw(w);
//                s+=main_cube_3d[i][j][k]->getSize();
            }
        }
    }
//    std::cout << s << std::endl;
}