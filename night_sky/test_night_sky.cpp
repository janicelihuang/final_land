//Author: jchang82
//Date: 4-26-16

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

//global variables
int window_x = 1000;
int window_y = 650;
int shape_size = 10;
int star_count = 50;
int star_size = 2;

std::vector<sf::CircleShape> stars;
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

    it = stars.begin();
    while(it != stars.end()){
        window.draw(*it);
        ++it;}

    window.display();
}

//initializes vector of stars
void initialize_stars(){
    int star_count_val = 0;
    while(star_count_val <= star_count){
        int x_pos = rand() % window_x;
        int y_pos = rand() % window_y;

        stars.push_back(sf::CircleShape(rand() % (star_size + 1 - window_y / 1500) + window_y / 2600));
        stars[star_count_val].setPosition(x_pos, y_pos);
        stars[star_count_val].setFillColor(sf::Color(255, 255, 255));
        ++star_count_val;}
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

    else if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Left){
           square.move(x_move, 0);
           x_move -= (x_move > 0) ? x_move - 4 : 4;}

        else if(event.key.code == sf::Keyboard::Right){
            square.move(x_move, 0);
            x_move += 4;}
    }
}

//keyboard inputs (pressed)
void key_pressed_events(){
    if(event.key.code == sf::Keyboard::Left){
       square.move(x_move, 0);
       x_move -= (x_move > 0) ? x_move - 2 : 2;
       if(x_move <= -5){x_move = -5;}

       
       it = stars.begin();
       while(it != stars.end()){
            it -> move(x_move / 4, 0);
            it -> setFillColor(sf::Color(rand() % (255 + 1 - 240) + 240,
                    rand() % (255 + 1 - 240) + 240,
                    rand() % (255 + 1 - 240) + 240));
            ++it;}
    }

    else if(event.key.code == sf::Keyboard::A){
       it = stars.begin();
       while(it != stars.end()){
            it -> move(6 / -4, 0);
            it -> setFillColor(sf::Color(rand() % (255 + 1 - 240) + 240,
                    rand() % (255 + 1 - 240) + 240,
                    rand() % (255 + 1 - 240) + 240));
            ++it;}
    }

    else if(event.key.code == sf::Keyboard::Right){
        square.move(x_move, 0);
        x_move += 2;
        if(x_move >= 5){x_move = 5;}

       it = stars.begin();
       while(it != stars.end()){
           it -> move(x_move / 4, 0);
           it -> setFillColor(sf::Color(rand() % (255 + 1 - 240) + 240,
                rand() % (255 + 1 - 240) + 240,
                rand() % (255 + 1 - 240) + 240));
           ++it;}
    }

    else if(event.key.code == sf::Keyboard::D){
       it = stars.begin();
       while(it != stars.end()){
            it -> move(6 / 4, 0);
            it -> setFillColor(sf::Color(rand() % (255 + 1 - 240) + 240,
                    rand() % (255 + 1 - 240) + 240,
                    rand() % (255 + 1 - 240) + 240));
            ++it;}
    }


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
    initialize_stars();
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


