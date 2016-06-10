#include "tile.h"

bool block_hardness;

Tile::Tile(){
      sprite_width = sprite_height = 0;
      block_hardness = 0;
}

Tile::Tile(int x, int y, std::string new_texture, bool hardness){
      texture.loadFromFile(new_texture);
      setTexture(texture);
      setScale(.25, .25);
      scale = getGlobalBounds();
      sprite_width = scale.width;
      sprite_height = scale.height;
      setPosition(sf::Vector2f(x, y));
      block_hardness = hardness;
}

