#ifndef LEVEL_MAIN_H
#define LEVEL_MAIN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <zlib.h>
//#include <tmx/MapLoader.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "keyboard.cpp"
#include "dark_adept.cpp"
#include "slime.cpp"
#include "utils.cpp"
#include "extended_sprite.cpp"
using namespace std;

    //tmx::MapLoader m1("map_sample");
    //global variables
    int window_x = 1000;
    int window_y = 650;

    sf::Event event; 
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Stage_1");

    Dark_Adept * player = new Dark_Adept();
    std::vector<Slime *> slimes;

    float grid_counter = 0;
    std::vector<sf::VertexArray> x_lines_v;
    std::vector<sf::VertexArray> y_lines_v;

    int x_vel = 0;
    int y_vel = 0;

//update position of mobs
    void move_mobs();

//check if sprites move off the screen TODO: y-direction
    void check_sprite_bounds();

//draw grid lines
    void initialize_grid_lines();

//updates canvas
    void draw_all();

//initializes square (user)
    void initialize_player();

//initializes mobs
    void initialize_mobs();

//checks for system events
    void system_events();

//keyboard inputs (pressed)
    void key_pressed_events();

//keyboard inputs (release)
    void key_released_events();
   
//main function
    int main(){
        srand(time(NULL));
        initialize_grid_lines();
        initialize_player();
        initialize_mobs();
        int debug_timer = 500;

        while(window.isOpen() && debug_timer > 0){
            event = sf::Event();

            while(window.pollEvent(event)){
                system_events();

                if(event.type == sf::Event::KeyPressed){
                    key_pressed_events();}
                if(event.type == sf::Event::KeyReleased){
                    key_released_events();}
            }
                move_mobs();
                check_sprite_bounds();
                draw_all();
        }
        return EXIT_SUCCESS;
    };

#endif
