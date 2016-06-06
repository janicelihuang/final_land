#include "level_main.h"

#define PI 3.14159265
#define block_unit 50

using namespace std;

void for_debug(){
    for(size_t i = 0; i < slimes.size(); i++){
        slimes[i] -> hit_box.clear();
        slimes[i] -> update_bounds();}
    player -> hit_box.clear();
    player -> update_bounds();

    for(size_t i = 0; i < 4; i++){
        player -> hit_box.push_back(sf::VertexArray(sf::Lines, 2));}
    for(size_t i = 0; i < slimes.size(); i++){
        for(size_t j = 0; j < 4; j++){
            slimes[i] -> hit_box.push_back(sf::VertexArray(sf::Lines, 2));}
    }

    for(size_t i = 0; i < slimes.size(); i++){
       generate_hit_boxes(*(slimes[i]), slimes[i] -> hit_box);}
    
    generate_hit_boxes(*player, player -> hit_box);
}

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

    for(size_t i = 0; i < slimes.size(); i++){
        pos = slimes[i] -> getPosition();
        std::vector<int> result = guided_mob_movement(*player, *slimes[i]);
        if(rand() % 100 >= 99){
            slimes[i] -> setPosition(pos.x + result[0], pos.y);}
    }
}

//check if sprites move off the screen
void check_sprite_bounds(){
    int sprite_width_var = player -> sprite_width;
    int sprite_height_var = player -> sprite_height;
    sf::Vector2f pos = player -> getPosition();

    //restrict player sprite movement
    if(pos.x - sprite_width_var <= 0){
        player -> setPosition(sprite_width_var, pos.y);}
    else if(pos.x + sprite_width_var >= window_x){
        player -> setPosition(window_x - player -> sprite_width, pos.y);}

    if(pos.y + sprite_height_var >= window_y){
        player -> setPosition(pos.x, window_y - sprite_height_var);}
    else if(pos.y <= 0){
        player -> setPosition(pos.x, 0);}
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

//updates canvas...COMMENTED OUT CODE FOR DEBUG
void draw_all(){
    window.clear(sf::Color(0, 0, 0, 255));

    for(size_t i = 0; i < x_lines_v.size(); i++){
        window.draw(x_lines_v[i]);
        window.draw(y_lines_v[i]);
        if(i < 4){
            window.draw(player -> hit_box[i]);}
    }

    for (size_t i = 0; i < slimes.size(); i++){
        for(size_t j = 0; j < 4; j++){
            window.draw((slimes[i] -> hit_box)[j]);}
    	window.draw(*(slimes[i]));
    }

    window.draw(*player);
    window.display();
}

//initializes square (user)
void initialize_player(){
    player -> setPosition(0, window_y - player -> sprite_height);
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



