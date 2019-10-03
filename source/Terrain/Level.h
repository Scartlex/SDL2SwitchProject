#ifndef LEVEL_H_
#define LEVEL_H_

#include <vector>
#include <SDL.h>
#include <time.h>
#include <unistd.h>
#include "Square.h"
#include "../GUI/gui.h"
#include "../Controls/keyListener.h"

using namespace std;

class Level {

    public:
        int rows, cols; //Dimensions
        vector< vector<Square> > terrain; //Main terrain, filled with squares
        Level(int r, int c); //Constructor will initialize the size of the board
        ~Level();
        void render(int xOffset, int yOffset);
        void load();
        void scrollAnimation(Directions direction);
        Square* getSquare(int row, int col);
};


#endif