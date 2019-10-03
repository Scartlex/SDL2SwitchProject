#include "Square.h"

void Square::load(std::string type) {
    texture = loadTexture("GUI/res/sprites/terrain/" + type + ".bmp");
}

int Square::render() {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Square::move(int x, int y) {
    place(rect.x+x, rect.y+y);
}

void Square::place(int x, int y) {
    rect.x = x;
    rect.y = y;
}

Square::Square(int xPos, int yPos) {
    row = xPos;
    col = yPos;
    rect.x = xPos*STANDARD_LENGTH;
    rect.y = yPos*STANDARD_LENGTH;
    rect.w = STANDARD_LENGTH;
    rect.h = STANDARD_LENGTH;
    occupied = false;
}

Square::~Square() {}