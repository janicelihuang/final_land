#include "level_main.h"

#define PI 3.14159265
#define block_unit 50

using namespace std;

void move_mobs(){
    sf::Vector2f pos = sf::Vector2f();
    std::vector<int> original_y_pos;

    for(size_t i = 0; i < slimes.size(); i++){
        original_y_pos.push_back((slimes[i] -> getPosition()).y);}

    for(size_t i = 0; i < slimes.size(); i++){
        pos = slimes[i] -> getPosition();
        float slime_sin_height = (float)sin(slimes[i] -> sin_degree * PI / 180) * 5;
        float new_height = (window_y - slimes[i] -> sprite_height) - (slime_sin_height);
        slimes[i] -> setPosition(pos.x, new_height); 
        slimes[i] -> sin_degree += (slime_sin_height < 0)? 5 : 1;
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
        grid_counter += window_y / 40;}
}

//updates canvas
void draw_all(){
    window.clear(sf::Color(0, 0, 0, 255));
    for(size_t i = 0; i < x_lines_v.size(); i++){
        window.draw(x_lines_v[i]);
        window.draw(y_lines_v[i]);}

    for (size_t i = 0; i < slimes.size(); i++){
    	window.draw(*(slimes[i]));}
    window.draw(*player);
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



