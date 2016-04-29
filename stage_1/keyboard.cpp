#include <SFML/Graphics.hpp>
#include <iostream>


void gravity(sf::Shape shape, int & x_move, int & y_move, int window_x, int window_y){
    /*
    while(){

    )
    */
}

void move_sprite(sf::Sprite & sprite, int & x_vel, int & y_vel, int vel, int max_vel){
    sprite.move(x_vel, y_vel);
    x_vel += vel;
    y_vel += vel;
    if(x_vel <= 0 && x_vel <= max_vel ||
            x_vel > 0 && x_vel >= max_vel){x_vel = max_vel;}
    if(y_vel <= 0 && y_vel <= max_vel ||
            y_vel > 0 && y_vel >= max_vel){y_vel = max_vel;}
}

void stop_sprite_x(sf::Sprite & sprite, int & x_vel, int & y_vel, int accel){
    x_vel -= x_vel * accel;
    y_vel -= y_vel * accel;
    sprite.move(x_vel, y_vel);
    x_vel = 0;
}


