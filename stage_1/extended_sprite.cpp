#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Extended_Sprite: public sf::Sprite{
    public:
        int mass, health, attack_dmg;
        int sprite_x, sprite_y;
        int sprite_width, sprite_height;
        sf::Texture texture;
        sf::FloatRect scale;

        Extended_Sprite(){
            setScale(.1, .1);
            scale = getGlobalBounds();
            sprite_x = scale.left;
            sprite_y = scale.top;
            sprite_width = scale.width;
            sprite_height = scale.height;
        }
};
