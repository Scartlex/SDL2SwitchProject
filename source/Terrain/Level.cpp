#include "Level.h"

void Level::render(int xOffset, int yOffset) {
    if(rows != -1 && cols != -1)
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                terrain[row][col].move(xOffset, yOffset);
                terrain[row][col].render();
            }
        }
}

void Level::load() {
    srand(time(NULL));
    if(rows != -1 && cols != -1)
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                double random = ((double) rand() / (RAND_MAX));
                switch(random < 0.5){
                    case true: terrain[row][col].load("grass");break;
                    case false: terrain[row][col].load("dirt");break;
                }
            }
        }
}

void Level::scrollAnimation(Directions direction) {
    switch(direction) {
            case NORTH: render(0, 4);break;
            case EAST:  render(-4, 0);break;
            case SOUTH: render(0, -4);break;
            case WEST:  render(4, 0);break;
        }
}

Square* Level::getSquare(int row, int col) {
    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        Square* square = &terrain[row][col];
        return square;
    } else return NULL;
}

Level::Level(int r, int c) {
    rows=r;
    cols=c;
    terrain.resize(r, vector<Square>(c)); //Resize and populate 2D-vector
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            terrain[row][col] = Square(row, col);
        }
    }
}

Level::~Level(void) {
    //Nothing to destroy here because there are no pointers involved (?)
}