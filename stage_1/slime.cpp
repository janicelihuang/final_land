#include <SFML/Graphics.hpp>
#include <iostream>
#include "extended_sprite.cpp"

class Slime: public Extended_Sprite{
    public:
        int sin_degree;

        Slime(){
            texture.loadFromFile("slime.png");
            setTexture(texture);
            scale = getGlobalBounds();
            sprite_x = scale.left;
            sprite_y = scale.top;
            sprite_width = scale.width;
            sprite_height = scale.height;
            sin_degree = 0;}
};

