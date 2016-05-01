#include <SFML/Graphics.hpp>
#include <iostream>
class Slime: public sf::Sprite{
    public:
        int mass; //kg
        int health;
        int attack_dmg; 
        sf::Texture texture;

        Slime(){
            std::cout << "slime" << std::endl;
            texture.loadFromFile("slime.png");
            setTexture(texture);}
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

