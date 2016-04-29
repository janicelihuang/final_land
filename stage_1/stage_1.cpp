#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <keyboard.cpp>

using namespace std;

//global variables
private:
    int window_x = 1000;
    int window_y = 650;

    sf::Event event; 
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Stage_1");
   
    sf::Sprite player;
    std::vector<sf::Sprite> mobs;

//updates canvas
void draw_all(){
    window.clear();
    window.draw(player);
    for (size_t i = 0; i < mobs.size(); i++)
	window.draw(mobs[i]);
    window.display();
}

//initializes square (user)
void initialize_player(){
    sf::Texture player_texture;
    player_texture.loadFromFile("player.png");
    player.setTexture(player_texture);
    player.setTextureRect(sf::IntRect(10,10,50,30));
    player.setColor(sf::Color(255,255,255,200));
    player.setPosition(100,25);
}

void initialize_mobs(){
    sf::Texture mob_texture;
    mob_texture.loadFromFile("mob.png");

    for(int i = 0; i <5; i++)
    {
	sf::Sprite mob(mob_texture);
	mob.setTextureRect(sf::IntRect(10,10,50,30));
	mob.setColor(sf::Color(255, 0, 0, 200));
	mob.setPosition(rand()%10,25);	
	mobs.push_back(mob);
    }
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

            set_square_position();
            draw_all();
    }
    return EXIT_SUCCESS;
};


