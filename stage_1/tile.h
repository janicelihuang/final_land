#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile: public sf::Sprite{
     public:
        sf::Texture texture;
        sf::FloatRect scale;
        int sprite_width, sprite_height;
        bool block_hardness;

	  Tile();
	  Tile(int x, int y, std::string new_texture, bool block_hardness);
};
#endif
