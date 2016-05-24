#include <SFML/Graphics.hpp>
#include "extended_sprite.cpp"

void flip_sprite_left(Extended_Sprite & sprite){
    sf::Vector2f scl = sprite.getScale();
    sprite.setScale(-1 * scl.x, 1 * scl.y);
}

void flip_sprite_right(Extended_Sprite & sprite){
   sf::Vector2f scl = sprite.getScale();
   sprite.setScale(1 * scl.x, 1 * scl.y); 
}
