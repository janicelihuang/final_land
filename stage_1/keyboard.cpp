#include <SFML/Graphics.hpp>
#include <iostream>


void gravity(sf::Shape shape, int & x_move, int & y_move, int window_x, int window_y){
    /*
    while(){

    )
    */
}

void move_shape(sf::Shape shape, int & x_move, int & y_move, int vel, int max_vel){
    shape.move(x_move, y_move);
    x_move += vel;
    y_move += vel;
    if(x_move <= max_vel){x_move = max_vel;}
}

void stop_shape(sf::Shape shape, int & x_move, int & y_move, int accel){
    shape.move((x_move) / 
}


