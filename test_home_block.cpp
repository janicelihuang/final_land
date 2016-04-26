#include <SFML/Graphics.hpp>
#include <iostream>


int window_x = 1000;
int window_y = 650;
int shape_size = 10;

int door_size_x = 7;
int door_size_y = 25;

sf::RectangleShape door_1;
sf::RectangleShape door_2;
sf::RectangleShape square;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Test_Home_Block");

sf::Vector2f v_1;
sf::Vector2f v_2;

float x_move = 0;
float y_move = 0;

int swap_counter = 1;

void getPosition_helper(){
    if(swap_counter % 2 == 0){
        v_1 = door_2.getPosition();
        v_2 = door_1.getPosition();
        return;}
        
    v_1 = door_1.getPosition();
    v_2 = door_2.getPosition();
}

void swapDoor_draw(){
    if(swap_counter % 2 == 0){
         if(v_1.x - door_size_x > 0){
            window.draw(door_2);}

        else if(v_2.x <= door_size_x){
            door_2.setPosition(window_x - v_2.x, window_y - door_size_y);
            window.draw(door_2);}
    }

    else{
        if(v_1.x - door_size_x > 0){
            window.draw(door_1);}

        else if(v_2.x <= door_size_x){
            door_1.setPosition(window_x - v_2.x, window_y - door_size_y);
            window.draw(door_1);}
        }


}

void drawDoor_helper(){
    if(swap_counter % 2 == 0){
        window.draw(door_1);
        return;}

    window.draw(door_2);
}

void swap_orientation(){    

     getPosition_helper();

     for(int i = 0; i < window_x - door_size_x; i++){
        door_1.move(-1, 0);
        door_2.move(-1, 0);

        getPosition_helper();

        window.clear();

        swapDoor_draw();
        drawDoor_helper();

        window.draw(square);
        window.display();
   }

}


int main(){
            square.setSize(sf::Vector2f(shape_size, shape_size));
            square.setFillColor(sf::Color(198, 113, 113));
            square.setPosition(window_x / 2, window_y - shape_size);
    
            door_1.setSize(sf::Vector2f(door_size_x, door_size_y));
            door_2.setSize(sf::Vector2f(door_size_x, door_size_y));
            door_1.setFillColor(sf::Color(255, 255, 255));
            door_2.setFillColor(sf::Color(225, 225, 225));
            door_1.setPosition(0, window_y - door_size_y);
            door_2.setPosition(window_x - door_size_x, window_y - door_size_y);
            
        while(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed){window.close();}
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                    window.close();}
            
                if(event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::Left){
                       square.move(x_move, 0);
                       x_move -= (x_move > 0) ? x_move - 4 : 4;}

                    else if(event.key.code == sf::Keyboard::Right){
                        square.move(x_move, 0);
                        x_move += 4;}

                    else if(event.key.code == sf::Keyboard::S){
                        swap_orientation();
                        ++swap_counter;}
                }
                /**/
                //std::cout << x_move << std::endl;
                /**/

                if(event.type == sf::Event::KeyReleased){
                   if(event.key.code == sf::Keyboard::Left){
                        square.move((x_move) / 2, 0);
                        x_move = 0;}

                   else if(event.key.code == sf::Keyboard::Right){
                        square.move(x_move / 2, 0);
                        x_move = 0;}
                }

                sf::Vector2f v = square.getPosition();
                if(v.x < 0){
                    square.setPosition(0, window_y - shape_size);}
                else if(v.x > window_x){
                    square.setPosition(window_x - shape_size, window_y - shape_size);}

                window.clear();
                window.draw(square);
                window.draw(door_1);
                window.draw(door_2);
                window.display();
            }




        }

        return EXIT_SUCCESS;
};


