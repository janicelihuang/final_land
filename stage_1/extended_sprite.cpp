#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#pragma once

class Extended_Sprite: public sf::Sprite{
    public:
        int mass, health, attack_dmg;
        int sprite_x, sprite_y;
        int sprite_width, sprite_height;
        int prev_x, prev_y;
        bool direction; //0 = left, 1 = right
        sf::Texture texture;
        sf::FloatRect scale;
        std::vector<sf::VertexArray> hit_box;

        Extended_Sprite(){
            scale = getGlobalBounds();
            sprite_x = scale.left;
            sprite_y = scale.top;
            sprite_width = scale.width;
            sprite_height = scale.height;
        }

        void update_bounds(){
            scale = getGlobalBounds();}
};
