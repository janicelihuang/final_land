#include <SFML/Graphics.hpp>
#include <iostream>
#include "extended_sprite.cpp"

class Dark_Adept: public Extended_Sprite{
    public:
        /*
        int mass, health, attack_dmg;
        int sprite_x, sprite_y;
        int sprite_width, sprite_height;
        sf::Texture texture;
        sf::FloatRect scale;
        */

        Dark_Adept(){
            texture.loadFromFile("dark_adept.png");
            setTexture(texture);
            setScale(.5, .5);
            scale = getGlobalBounds();
            sprite_x = scale.left;
            sprite_y = scale.top;
            sprite_width = scale.width;
            sprite_height = scale.height;}
};
