#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Terrain/Square.h"
#include "../Terrain/Level.h"
#include "../GUI/gui.h"
#include "../Controls/keyListener.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Character {
    public:
        Level* currentLevel;
        Square* currentSquare;
        Square* previousSquare;
        Character() : currentLevel(NULL) {}
        Character(Level*);
        ~Character(void);
        void place(int row, int col);
        void move(int x, int y);
        void moveAnimation(string sprite, int spriteRenderCycle, Directions direction, int pixelOffset);
        void render(SDL_Rect* rect, string sprite);
    private:
        SDL_Texture* texture;
};

#endif