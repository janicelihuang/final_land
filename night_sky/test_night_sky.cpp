#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int window_x = 1000;
int window_y = 650;
int shape_size = 10;

std::vector<sf::CircleShape> stars;
std::vector<sf::CircleShape>::iterator it;

sf::Event event; 
sf::RectangleShape square;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Test_Home_Block");

float x_move = 0;
float y_move = 0;

void draw_all(){
    window.clear();
    window.draw(square);
    
    it = stars.begin();
    while(it != stars.end()){
        window.draw(*it);}
    window.display();
}

void initialize_stars(){
    it = stars.begin();

    while(it != stars.end()){
        stars.push_back(sf::CircleShape(rand() % 4));
        it -> setFillColor(sf::Color(255, 255, 255));
        ++it;}
}

void initialize_square(){
    square.setSize(sf::Vector2f(shape_size, shape_size));
    square.setFillColor(sf::Color(198, 113, 113));
    square.setPosition(window_x / 2, window_y - shape_size);
}

void key_pressed_events(){
    if(event.type == sf::Event::Closed){window.close();}

    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
        window.close();}

    else if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Left){
           square.move(x_move, 0);
           x_move -= (x_move > 0) ? x_move - 4 : 4;}

        else if(event.key.code == sf::Keyboard::Right){
            square.move(x_move, 0);
            x_move += 4;}
    }
}

void key_released_events(){
   if(event.key.code == sf::Keyboard::Left){
        square.move((x_move) / 2, 0);
        x_move = 0;}

   else if(event.key.code == sf::Keyboard::Right){
        square.move(x_move / 2, 0);
        x_move = 0;}
}

int main(){
    initialize_stars();
    initialize_square();

   
        while(window.isOpen()){
        event = sf::Event();

 while(window.pollEvent(event)){

        key_pressed_events();

    if(event.type == sf::Event::KeyReleased){
        key_released_events();}
                sf::Vector2f v = square.getPosition();
        if(v.x < 0){
            square.setPosition(0, window_y - shape_size);}
        else if(v.x > window_x){
            square.setPosition(window_x - shape_size, window_y - shape_size);}

        draw_all();

        }

    }

    return EXIT_SUCCESS;
};


