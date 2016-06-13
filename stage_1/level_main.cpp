#include "level_main.h"

#define PI 3.14159265
#define block_unit 64 

using namespace std;

//debug function calls here, draw functions in draw_all()
void for_debug(){
    hit_box_main(*player, slimes);
}

//place mob movement functions in here
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
    check_sprite_bounds_utils(*player, slimes, stage.tiles, window_x, window_y);
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

void initialize_grid_lines(){
    stage.initialize_grid_lines();
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


