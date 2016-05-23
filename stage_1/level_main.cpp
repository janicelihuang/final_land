#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "keyboard.cpp"
#include "dark_adept.cpp"
#include "slime.cpp"
#include "utils.cpp"
#include "extended_sprite.cpp"

#define PI 3.14159265

using namespace std;

//global variables
int window_x = 1000;
int window_y = 650;

sf::Event event; 
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Stage_1");

Dark_Adept * player = new Dark_Adept();
std::vector<Slime *> slimes;

float grid_counter = 0;
//sf::VertexArray x_lines(sf::Lines, window_y / 10);
//sf::VertexArray y_lines(sf::Lines, window_x / 10);
std::vector<sf::VertexArray> x_lines_v;
std::vector<sf::VertexArray> y_lines_v;

int x_vel = 0;
int y_vel = 0;


void move_mobs(){
    sf::Vector2f pos = sf::Vector2f();
    std::vector<int> original_y_pos;

    for(size_t i = 0; i < slimes.size(); i++){
        original_y_pos.push_back((slimes[i] -> getPosition()).y);}

    for(size_t i = 0; i < slimes.size(); i++){
        pos = slimes[i] -> getPosition();
        int slime_sin_height = slimes[i] -> sin_degree;
        float new_height = original_y_pos[i] - (float)sin(slime_sin_height * PI / 180) / 10;
        slimes[i] -> setPosition(pos.x, new_height); 
       // std::cout << "original: " << original_y_pos[i] << std::endl;
       // std::cout << "new height: " << new_height << std::endl;
        slimes[i] -> sin_degree += (slime_sin_height >= 360)? -1 * 360 : 2;
    }
}

//check if sprites move off the screen TODO: y-direction
void check_sprite_bounds(){
    sf::Vector2f pos = player -> getPosition();
    if(pos.x < 0){
        player -> setPosition(0, pos.y);}
    else if(pos.x > window_x - player -> sprite_width){
       player -> setPosition(window_x - player -> sprite_width, pos.y);}
}

//draw grid lines
void initialize_grid_lines(){

for(size_t i = 0; i < window_x / 10; i++){
    if(i < window_y){
        y_lines_v.push_back(sf::VertexArray(sf::Lines, 2));}
    x_lines_v.push_back(sf::VertexArray(sf::Lines, 2));}

grid_counter = 0;

for(size_t i = 0; i < x_lines_v.size(); i += 2){
    x_lines_v[i][0] = sf::Vector2f(grid_counter, 0);
    x_lines_v[i][1] = sf::Vector2f(grid_counter, window_y);
    grid_counter += window_x / 50;}

grid_counter = 0;

for(size_t i = 0; i < y_lines_v.size(); i++){
    y_lines_v[i][0] = sf::Vector2f(0, grid_counter);
    y_lines_v[i][1] = sf::Vector2f(window_x, grid_counter);
    grid_counter += window_y / 50;}
}

//updates canvas
void draw_all(){
    window.clear(sf::Color(0, 0, 0, 255));
    for (size_t i = 0; i < slimes.size(); i++){
    	window.draw(*(slimes[i]));}
    window.draw(*player);
    for(size_t i = 0; i < x_lines_v.size(); i++){
        window.draw(x_lines_v[i]);
        window.draw(y_lines_v[i]);}
    window.display();
}

//initializes square (user)
void initialize_player(){
    player -> setPosition(0, window_y - 0.5 * player -> sprite_height);
}

void initialize_mobs(){
    for(int i = 0; i < 5; i++){
        Slime *slime = new Slime();
        slime -> setPosition(rand() % window_x, window_y - slime -> sprite_height);
        slimes.push_back(slime);}
}

//checks for system events
void system_events(){
    if(event.type == sf::Event::Closed){window.close();}

    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
        window.close();}
}

//keyboard inputs (pressed)
void key_pressed_events(){
    if(event.key.code == sf::Keyboard::Left){
        move_sprite(*player, x_vel, y_vel, -4,0, -5, window_x, window_y);
        flip_sprite_left(*player);}

    else if(event.key.code == sf::Keyboard::Right){
        move_sprite(*player, x_vel, y_vel, 4,0, 5, window_x, window_y);
        flip_sprite_right(*player);}

    else if(event.key.code == sf::Keyboard::Down){
        move_sprite(*player, x_vel, y_vel,0, 2, 5, window_x, window_y);}
 
    else if(event.key.code == sf::Keyboard::Up){
        move_sprite(*player, x_vel, y_vel,0, -2,- 5, window_x, window_y);}
}

//keyboard inputs (release)
void key_released_events(){
    
   if(event.key.code == sf::Keyboard::Left){
        stop_sprite_x(*player, x_vel, .5, window_x);}

   else if(event.key.code == sf::Keyboard::Right){
        stop_sprite_x(*player, x_vel, .5, window_x);}

   else if(event.key.code == sf::Keyboard::Up){
        stop_sprite_y(*player, y_vel, .5, window_y);}
 
   else if(event.key.code == sf::Keyboard::Down){
        stop_sprite_y(*player, y_vel, .5, window_y);} 
        
}

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


