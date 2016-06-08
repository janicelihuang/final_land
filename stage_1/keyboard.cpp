#include <SFML/Graphics.hpp>
#include <iostream>


void move_sprite(sf::Sprite & sprite, int & x_vel, int & y_vel, int x_acc, int y_acc){
    sprite.move(x_vel, y_vel);
    x_vel += x_acc;
    y_vel += y_acc;
}

void stop_sprite_x(sf::Sprite & sprite, int & x_vel, int accel){
    x_vel += x_vel * accel;
    sprite.move(x_vel, 0);
    x_vel = 0;
}

void stop_sprite_y(sf::Sprite & sprite, int & y_vel, int accel){
    y_vel += y_vel * accel;
    sprite.move(0, y_vel);
    y_vel = 0;
} 


