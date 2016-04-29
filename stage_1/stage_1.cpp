#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "keyboard.cpp"

using namespace std;

//global variables
int window_x = 1000;
int window_y = 650;

sf::Event event; 
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Stage_1");

sf::Sprite player;
std::vector<sf::Sprite> mobs;

int x_vel = 0;
int y_vel = 0;

//updates canvas
void draw_all(){
    window.clear();
    window.draw(player);
    for (size_t i = 0; i < mobs.size(); i++){
    	window.draw(mobs[i]);}
    window.display();
}

//initializes square (user)
void initialize_player(){
    sf::Texture player_texture;
    player_texture.loadFromFile("player.png");
    player.setTexture(player_texture);
    player.setTextureRect(sf::IntRect(10, 10, 50, 30));
    player.setColor(sf::Color(255, 255, 255, 200));
    player.setPosition(100, 25);
}

void initialize_mobs(){
    sf::Texture mob_texture;
    mob_texture.loadFromFile("mob.png");

    for(int i = 0; i < 5; i++){
        sf::Sprite mob(mob_texture);
        mob.setTextureRect(sf::IntRect(10,10,50,30));
        mob.setColor(sf::Color(255, 0, 0, 200));
        mob.setPosition(rand() % 10, 25);	
        mobs.push_back(mob);}
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
        move_sprite(player, x_vel, y_vel, -2, -5, window_x, window_y);}

    else if(event.key.code == sf::Keyboard::Right){
        move_sprite(player, x_vel, y_vel, 2, 5, window_x, window_y);}

    else if(event.key.code == sf::Keyboard::Down){
        move_sprite(player, x_vel, y_vel, -4, -4, window_x, window_y);}
 
    else if(event.key.code == sf::Keyboard::Up){
        move_sprite(player, x_vel, y_vel, 4, 4, window_x, window_y);}
}

//keyboard inputs (release)
void key_released_events(){
   if(event.key.code == sf::Keyboard::Left){
        stop_sprite_x(player, x_vel, .5, window_x);}

   else if(event.key.code == sf::Keyboard::Right){
        stop_sprite_x(player, x_vel, .5, window_x);}

   else if(event.key.code == sf::Keyboard::Down){
        stop_sprite_y(player, y_vel, .5, window_y);}
 
   else if(event.key.code == sf::Keyboard::Down){
        stop_sprite_y(player, y_vel, .5, window_y);} 
}

//main function
int main(){
    srand(time(NULL));
    initialize_player();
    initialize_mobs();

    while(window.isOpen()){
        event = sf::Event();

        while(window.pollEvent(event)){
            system_events();

            if(event.type == sf::Event::KeyPressed){
                key_pressed_events();}
            if(event.type == sf::Event::KeyReleased){
                key_released_events();}
            }

            draw_all();
    }
    return EXIT_SUCCESS;
};


