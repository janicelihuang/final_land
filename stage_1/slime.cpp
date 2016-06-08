#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "extended_sprite.cpp"
#include "tile.cpp"
#include "utils.cpp"
#define PI 3.14159265

class Slime: public Extended_Sprite{
    public:
        int sin_degree;

        Slime(){
            direction = rand() % 1;
            texture.loadFromFile("slime.png");
            setTexture(texture);
            setScale(.4, .4);
            scale = getGlobalBounds();
            sprite_x = scale.left;
            sprite_y = scale.top;
            sprite_width = scale.width;
            sprite_height = scale.height;
            sin_degree = 0;}

        void move_slime(std::vector<Tile *> & hard_blocks, int window_y){
            sf::Vector2f pos = getPosition();
           float slime_sin_height = (float) sin(sin_degree * PI / 180) * 5;
           float new_height = (window_y - sprite_height - hard_blocks[0] -> sprite_height) - (slime_sin_height);
           setPosition(pos.x, new_height); 
           sin_degree += (slime_sin_height < 0)? 5 : 1;
        }

        void slime_track(Extended_Sprite & player){
            sf::Vector2f pos = getPosition();
            prev_x = pos.x;
            prev_y = pos.y;
            std::vector<int> result = guided_mob_movement(player, *this);
            if(rand() % 100 >= 90){
                setPosition(pos.x + result[0], pos.y);}
        }
};

