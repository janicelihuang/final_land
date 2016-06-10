#include "level_main.h"

#define PI 3.14159265
#define block_unit 64 

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

void move_slimes(){
    sf::Vector2f pos = sf::Vector2f();
    std::vector<int> original_y_pos;

    for(size_t i = 0; i < slimes.size(); i++){
        pos = slimes[i] -> getPosition();
        slimes[i] -> move_slime(stage.tiles[0], window_y);}

    for(size_t i = 0; i < slimes.size(); i++){
        slimes[i] -> slime_track(*player);}
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

    pos = player -> getPosition();

    //check for player collision
    if(stage.tiles[(int)pos.y / ((window_y) / 16)][(int)pos.x / ((window_x) / 16)] -> getGlobalBounds().intersects(player -> getGlobalBounds()))
         player -> setPosition(player -> prev_x, player -> prev_y);

    //check for mob collision
    for(size_t i = 0; i < slimes.size(); i++){
        pos = slimes[i] -> getPosition();
        if(stage.tiles[(int)pos.y / ((window_y) / 16)][(int)pos.x / ((window_x) / 16)] -> getGlobalBounds().intersects(slimes[i] -> getGlobalBounds()))
             slimes[i] -> setPosition(slimes[i] -> prev_x, slimes[i] -> prev_y);
    }
}

//draw grid lines
void initialize_grid_lines(){
    stage.initialize_grid_lines();
}

//updates canvas
void draw_all(){
    window.clear(sf::Color(0, 0, 0, 255));
    draw_lines();
    draw_map();
    draw_player();
    draw_mobs();
    window.display();
}

//initialize tiles
void initialize_map(){
    stage.initialize_tiles();
}

//draw_all helper function
void draw_map(){
    if(!debug_on){
        for(size_t i = 0; i < stage.soft_blocks.size(); i++){
            window.draw(*(stage.soft_blocks[i]));}
    }

    for(size_t i = 0; i < stage.hard_blocks.size(); i++){
        window.draw(*(stage.hard_blocks[i]));}
}

//draw hit_boxes and grid_lines
void draw_lines(){
    if(debug_on){
        for(size_t i = 0; i < stage.x_lines_v.size(); i++){
            window.draw(stage.x_lines_v[i]);
            window.draw(stage.y_lines_v[i]);
            if(i < 4)
                //debug use
                window.draw(player -> hit_box[i]);}
    }
}

//draw mob sprites
void draw_mobs(){
    for (size_t i = 0; i < slimes.size(); i++){
            for(size_t j = 0; j < 4; j++){
                //debug use
                if(debug_on)
                    window.draw((slimes[i] -> hit_box)[j]);
            }
        window.draw(*(slimes[i]));
    }
}

//draw player sprite
void draw_player(){
    window.draw(*player);
}

//initializes square (user)
void initialize_player(){
    player -> setPosition(20, window_y - player -> sprite_height - stage.hard_blocks[0] -> sprite_height - 1);
}

//initializes mobs
void initialize_mobs(){
    for(int i = 0; i < 5; i++){
        Slime *slime = new Slime();
        slime -> setPosition(rand() % window_x, window_y - slime -> sprite_height - stage.hard_blocks[0] -> sprite_height - 1);
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
        move_sprite(*player, x_vel, y_vel, -4, 0);
        flip_sprite_left(*player);}

    else if(event.key.code == sf::Keyboard::Right){
        move_sprite(*player, x_vel, y_vel, 4, 0);
        flip_sprite_right(*player);}

    else if (event.key.code == sf::Keyboard::Up && grounded){
        y_vel = -6;
        grounded = false;
        move_sprite(*player, x_vel, y_vel, 0, 0);}

    if(event.key.code == sf::Keyboard::Num1){
        std::cout << debug_on << std::endl;
        debug_on = !debug_on;}
}

//keyboard inputs (release)
void key_released_events(){
   if(event.key.code == sf::Keyboard::Left){
        stop_sprite_x(*player, x_vel, .5);}

   else if(event.key.code == sf::Keyboard::Right){
        stop_sprite_x(*player, x_vel, .5);}

   else if(event.key.code == sf::Keyboard::Up){
       stop_sprite_y(*player, y_vel, .5);}
}

//gravity function
void gravity(){
    move_sprite(*player, x_vel, y_vel, 0, 1);
    sf::Vector2f pos = player -> getPosition();

    if(pos.y >= window_y - player -> sprite_height - stage.hard_blocks[0] -> sprite_height){
       grounded = true;
       player -> setPosition(pos.x + x_vel, window_y - player -> sprite_height - stage.hard_blocks[0] -> sprite_height - 1);}
}


