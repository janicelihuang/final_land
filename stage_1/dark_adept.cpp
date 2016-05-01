#include <SFML/Graphics.hpp>
#include <iostream>

class Dark_Adept: public sf::Sprite{
    public:
        int mass;
        int health;
        int attack_dmg;
        sf::Texture texture;

        Dark_Adept(){
            std::cout << "works" << std::endl;
            texture.loadFromFile("dark_adept.png");
            setTexture(texture);}
};
