#include <SFML/Graphics.hpp>
#include "extended_sprite.cpp"

void flip_sprite_left(Extended_Sprite & sprite){
    sprite.setOrigin(((float)sprite.getLocalBounds().width) / 2, ((float)sprite.getLocalBounds().width) / 2);
    sprite.setScale(-1, 1);
}

void flip_sprite_right(Extended_Sprite & sprite){
   sprite.setOrigin(sprite.getLocalBounds().width, 0);
   sprite.setScale(1, 1); 
}
