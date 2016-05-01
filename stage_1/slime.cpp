#include <SFML/Graphics.hpp>
#include <iostream>
#include "extended_sprite.cpp"

class Slime: public Extended_Sprite{
    public:
        int mass, health, attack_dmg; 
        int sprite_x, sprite_y;
        int sprite_width, sprite_height;
        sf::Texture texture;
        sf::FloatRect scale;

        Slime(){
            texture.loadFromFile("slime.png");
            setTexture(texture);
            scale = getGlobalBounds();
            sprite_x = scale.left;
            sprite_y = scale.top;
            sprite_width = scale.width;
            sprite_height = scale.height;}
/*
        //copy constructor
        Slime(const Slime & slime){
                
        }

        //destructor helper class
        void clear(){
            delete 
        }

        //destructor
        ~Slime(){

        }

        //assignment operator
        Slime & operator=(const Slime & slime){

        }
*/

};

