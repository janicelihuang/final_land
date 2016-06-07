#include <SFML/Graphics.hpp> 
class Tile: public sf::Sprite{
    public:
      sf::Texture texture;
        sf::FloatRect scale;
        
        Tile(int x, int y, std::string new_texture){
            texture.loadFromFile(new_texture);
            setTexture(texture);
            setScale(.5, .5);
            scale = getGlobalBounds();
            setPosition(sf::Vector2f(x, y));
        }
 };

