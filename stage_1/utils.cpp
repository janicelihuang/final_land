#include <SFML/Graphics.hpp>
#include <iostream>
#include "extended_sprite.cpp"

void flip_sprite_left(Extended_Sprite & sprite){
    sf::Vector2f scl = sprite.getScale();

    if(sprite.direction){
       sprite.setScale(-1 * scl.x, 1 * scl.y);
       sprite.direction = !sprite.direction;}
    else{
        sprite.setScale(1 * scl.x, 1 * scl.y);}
}

void flip_sprite_right(Extended_Sprite & sprite){
   sf::Vector2f scl = sprite.getScale();

   if(sprite.direction){
       sprite.setScale(1 * scl.x, 1 * scl.y);}
   else{
       sprite.setScale(-1 * scl.x, 1 * scl.y);
       sprite.direction = !sprite.direction;}
}
