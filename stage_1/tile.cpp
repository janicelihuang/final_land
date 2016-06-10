#include <SFML/Graphics.hpp> 
class Tile: public sf::Sprite{
    public:
      sf::Texture texture;
      sf::FloatRect scale;
      int sprite_width, sprite_height;
        
        Tile(){
            sprite_width = sprite_height = 0;
        }

        Tile(int x, int y, std::string new_texture){
            texture.loadFromFile(new_texture);
            setTexture(texture);
            setScale(.25, .25);
            scale = getGlobalBounds();
            sprite_width = scale.width;
            sprite_height = scale.height;
            setPosition(sf::Vector2f(x, y));
        }
 };

