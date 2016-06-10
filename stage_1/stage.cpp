#include <SFML/Graphics.hpp>
#include "tile.cpp"

class Stage{
    public:
        std::vector<std::vector<Tile *> > tiles; 
        std::vector<std::vector<bool> > block_hardness;  //0 for soft, 1 for hard

        std::vector<sf::VertexArray> x_lines_v;
        std::vector<sf::VertexArray> y_lines_v;

        int window_x, window_y;

        //initialize tiles and block_hardness fields
        Stage(int window_x, int window_y){
            std::vector<Tile *> temp_v;
            std::vector<bool> temp_b;
            for(size_t i = 0; i < window_y / 16; i++){
                for(size_t j = 0; j < window_x / 16; j++){
                    temp_v.push_back(new Tile());
                    temp_b.push_back(0);}
                tiles.push_back(temp_v);
                temp_v.clear();
            }
        }

        void initialize_tiles(){
            for(size_t j = 0; j <= window_x / 16; j++){
                tiles[0][j] = new Tile(j * 16, window_y - 16, "ground_tile.png");}

            for (size_t i = 1; i <= window_y / 16; i++){
                for (size_t j = 0; j < window_x / 16; j++){
                    tiles[i][j] = new Tile(j * 16, i * 16, "sky_tile.png");}
            }

        }

        void initialize_grid_lines(){
            float grid_counter = 0;
            for(size_t i = 0; i < window_x / 10; i++){
                if(i < window_y){
                    y_lines_v.push_back(sf::VertexArray(sf::Lines, 2));}
                x_lines_v.push_back(sf::VertexArray(sf::Lines, 2));}

            grid_counter = 0;

            for(size_t i = 0; i < x_lines_v.size(); i += 2){
                x_lines_v[i][0] = sf::Vector2f(grid_counter, 0);
                x_lines_v[i][1] = sf::Vector2f(grid_counter, window_y);
                grid_counter += window_x / 50;}

            grid_counter = 0;

            for(size_t i = 0; i < y_lines_v.size(); i++){
                y_lines_v[i][0] = sf::Vector2f(0, grid_counter);
                y_lines_v[i][1] = sf::Vector2f(window_x, grid_counter);
                grid_counter += window_y / 40;}
        }




};