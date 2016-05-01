#include <SFML/Graphics.hpp>
#include "extended_sprite.cpp"

void flip_sprite_left(Extended_Sprite & sprite){
    sprite.setScale(-1, 1);
}

void flip_sprite_right(Extended_Sprite & sprite){
   sprite.setScale(1, 1); 
}
