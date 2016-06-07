#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "tile.cpp"

class Stage_Map{
    public:
        std::vector<Tile *> tiles;
        Stage_Map(){};
};
