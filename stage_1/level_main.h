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
#include "tile.cpp"
using namespace std;

    //tmx::MapLoader m1("map_sample");
    //global variables
    int window_x = 1000;
    int window_y = 650;

    sf::Event event; 
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Stage_1");
    std::vector<Tile *> hard_blocks;
    std::vector<Tile *> soft_blocks;

    Dark_Adept * player = new Dark_Adept();
    std::vector<Slime *> slimes;

    float grid_counter = 0;
    std::vector<sf::VertexArray> x_lines_v;
    std::vector<sf::VertexArray> y_lines_v;

    int x_vel = 0;
    int y_vel = 0;
    bool grounded = true;
    bool debug_on = false;

//for_debug
    void for_debug();

//update position of mobs
    void move_slimes();

//check if sprites move off the screen TODO: y-direction
    void check_sprite_bounds();

//draw grid lines
    void initialize_grid_lines();

//updates canvas
    void draw_all();

//initalize_map
    void initialize_map();

//draw_all helper functions
    void draw_lines();
    void draw_player();
    void draw_mobs();
    void draw_map();

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

    void gravity();
   
//main function
    int main(){
        srand(time(NULL));
        initialize_map();
        initialize_grid_lines();
        initialize_player();
        initialize_mobs();

        while(window.isOpen()){
            event = sf::Event();

            while(window.pollEvent(event)){
                system_events();

                player -> prev_x = player -> getPosition().x;
                player -> prev_y = player -> getPosition().y;

                if(event.type == sf::Event::KeyPressed){
                    key_pressed_events();}
                if(event.type == sf::Event::KeyReleased){
                    key_released_events();}
            }
                move_slimes();
                if(!grounded)
                    gravity();
                check_sprite_bounds();
                for_debug();
                draw_all();
                std::cout << x_vel << std::endl;
        }
        return EXIT_SUCCESS;
    };

#endif
