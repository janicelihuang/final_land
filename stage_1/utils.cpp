#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "extended_sprite.cpp"

void flip_sprite_left(Extended_Sprite & sprite){
    sf::Vector2f scl = sprite.getScale();
    sf::Vector2f ori = sprite.getOrigin();

    if(sprite.direction){
       sprite.setScale(-1 * scl.x, 1 * scl.y);
       sprite.setOrigin(sprite.sprite_width, ori.y);
       sprite.direction = !sprite.direction;}
    else{
        sprite.setScale(1 * scl.x, 1 * scl.y);
        sprite.setOrigin(0, ori.y);}
}

void flip_sprite_right(Extended_Sprite & sprite){
   sf::Vector2f scl = sprite.getScale();
   sf::Vector2f ori = sprite.getOrigin();

   if(sprite.direction){
       sprite.setScale(1 * scl.x, 1 * scl.y);
        sprite.setOrigin(0, ori.y);}
   else{
       sprite.setScale(-1 * scl.x, 1 * scl.y);
       sprite.direction = !sprite.direction;
        sprite.setOrigin(sprite.sprite_width, ori.y);}
}

//DEBUG PURPOSES//
void generate_hit_boxes(Extended_Sprite & sprite, std::vector<sf::VertexArray> & hit_box){
    sf::FloatRect sprite_scale = sprite.scale;
    hit_box[0][0].position = hit_box[3][1].position = sf::Vector2f(sprite_scale.left, sprite_scale.top);
    hit_box[0][1].position =  hit_box[1][0].position = sf::Vector2f(sprite_scale.left + sprite_scale.width, sprite_scale.top);
           
    //hit_box[1][0].position = sf::Vector2f(sprite_scale.left + sprite_scale.width, sprite_scale.top);
    hit_box[1][1].position =  hit_box[2][0].position = sf::Vector2f(sprite_scale.left + sprite_scale.width, sprite_scale.top + sprite_scale.height);
               
    //hit_box[2][0].position = sf::Vector2f(sprite_scale.left + sprite_scale.width, sprite_scale.top + sprite_scale.height);
    hit_box[2][1].position = hit_box[3][0].position = sf::Vector2f(sprite_scale.left, sprite_scale.top + sprite_scale.height);
           
    //hit_box[3][0].position = sf::Vector2f(sprite_scale.left, sprite_scale.top + sprite_scale.height);
    //hit_box[3][1].position = sf::Vector2f(sprite_scale.left, sprite_scale.top);
                   
     for(size_t i = 0; i < 4; i++){
       hit_box[i][0].color =
         hit_box[i][1].color = sf::Color::Green;}

}

std::vector<int> guided_mob_movement(Extended_Sprite & player, Extended_Sprite & mob){
    std::vector<int> ret;
    sf::Vector2f player_pos = player.getPosition();    
    sf::Vector2f mob_pos = mob.getPosition();
    float x = player_pos.x - mob_pos.x;
   // float y = player_pos.y - mob_pos.y;
    float returned_x, returned_y = 0;

    if(x > 0){
        ret.push_back(1);}
    else if(x < 0){
        ret.push_back(-1);}
    else{
        ret.push_back(0);}
    return ret;
}
