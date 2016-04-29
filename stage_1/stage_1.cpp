//Author: jchang82
//Date: 4-26-16

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <keyboard.cpp>

using namespace std;

//global variables
int window_x = 1000;
int window_y = 650;
int shape_size = 10;

std::vector<sf::CircleShape>::iterator it;

sf::Event event; 
sf::RectangleShape square;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Test_Home_Block");

float x_move = 0;
float y_move = 0;

//updates canvas
void draw_all(){
    window.clear();
    window.draw(square);
    window.display();
}

//initializes square (user)
void initialize_square(){
    square.setSize(sf::Vector2f(shape_size, shape_size));
    square.setFillColor(sf::Color(198, 113, 113));
    square.setPosition(window_x / 2, window_y - shape_size);
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
        move_shape(square, x_move, 0, -2, -5);}

    else if(event.key.code == sf::Keyboard::Right){
        move_shape(square, x_move, 0, 2, 5);}
}

//keyboard inputs (release)
void key_released_events(){
   if(event.key.code == sf::Keyboard::Left){
        square.move((x_move) / 2, 0);
        x_move = 0;}

   else if(event.key.code == sf::Keyboard::Right){
        square.move(x_move / 2, 0);
        x_move = 0;}
}

//set square (user) position
void set_square_position(){
    sf::Vector2f v = square.getPosition();

    if(v.x < 0){
        square.setPosition(0, window_y - shape_size);}

    else if(v.x > window_x){
        square.setPosition(window_x - shape_size, window_y - shape_size);}
}

//main function
int main(){
    srand(time(NULL));
    initialize_square();

    while(window.isOpen()){
        event = sf::Event();

        while(window.pollEvent(event)){
            system_events();

            if(event.type == sf::Event::KeyPressed){
                key_pressed_events();}
            if(event.type == sf::Event::KeyReleased){
                key_released_events();}
            }

            set_square_position();
            draw_all();
    }
    return EXIT_SUCCESS;
};


