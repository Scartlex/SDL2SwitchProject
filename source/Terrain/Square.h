#ifndef SQUARE_H_
#define SQUARE_H_

#include "../GUI/gui.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#define STANDARD_LENGTH 64

class Square {

    public:
        int row;
        int col;
        SDL_Rect rect;
        bool occupied;
        Square() : row(-1), col(-1), occupied(0) {}
        Square(int xPos, int yPos);
        ~Square(void);
        void load(std::string type);
        int render();
        void move(int x, int y);
        void place(int x, int y);
    private:
        SDL_Texture* texture;
};

#endif