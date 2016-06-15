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
           
    hit_box[1][1].position =  hit_box[2][0].position = sf::Vector2f(sprite_scale.left + sprite_scale.width, sprite_scale.top + sprite_scale.height);
               
    hit_box[2][1].position = hit_box[3][0].position = sf::Vector2f(sprite_scale.left, sprite_scale.top + sprite_scale.height);
           
     for(size_t i = 0; i < 4; i++){
       hit_box[i][0].color =
         hit_box[i][1].color = sf::Color::Green;}

}

template<typename T>
void hit_box_main(Extended_Sprite & player, std::vector<T *> & mobs){
    for(size_t i = 0; i < mobs.size(); i++){
        mobs[i] -> hit_box.clear();
        mobs[i] -> update_bounds();}
    player.hit_box.clear();
    player.update_bounds();

    for(size_t i = 0; i < 4; i++){
        player.hit_box.push_back(sf::VertexArray(sf::Lines, 2));}
    for(size_t i = 0; i < mobs.size(); i++){
        for(size_t j = 0; j < 4; j++){
            mobs[i] -> hit_box.push_back(sf::VertexArray(sf::Lines, 2));}
    }

    for(size_t i = 0; i < mobs.size(); i++){
       generate_hit_boxes(*(mobs[i]), mobs[i] -> hit_box);}
    
    generate_hit_boxes(player, player.hit_box);

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

template<class M, class T>
void check_sprite_bounds_utils(Extended_Sprite & player, std::vector<M *> & mobs, std::vector<std::vector<T *> > & tiles, int window_x, int window_y){

    int sprite_width_var = player.sprite_width;
    int sprite_height_var = player.sprite_height;
    sf::Vector2f pos = player.getPosition();

    //restrict player sprite movement
    if(pos.x - sprite_width_var <= 0){
        player.setPosition(sprite_width_var, pos.y);}
    else if(pos.x + sprite_width_var >= window_x){
        player.setPosition(window_x - player.sprite_width, pos.y);}

    if(pos.y + sprite_height_var >= window_y){
        player.setPosition(pos.x, window_y - sprite_height_var);}
    else if(pos.y <= 0){
        player.setPosition(pos.x, 0);}

    pos = player.getPosition();

    //check for player collision
    if(tiles[(int)(window_y - pos.y) / ((window_y) / 16)][(int)(pos.x) / ((window_x) / 16)] -> getGlobalBounds().intersects(player.getGlobalBounds())){
        player.setPosition(player.prev_x, player.prev_y);}

    //check for mob collision
    for(size_t i = 0; i < mobs.size(); i++){
        pos = mobs[i] -> getPosition();
        if(tiles[(int)pos.y / ((window_y) / 16)][(int)pos.x / ((window_x) / 16)] -> getGlobalBounds().intersects(mobs[i] -> getGlobalBounds()))
             mobs[i] -> setPosition(mobs[i] -> prev_x, mobs[i] -> prev_y);
    }
}
