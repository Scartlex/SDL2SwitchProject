#include "Character.h"

void Character::place(int row, int col) {
    Square* square = currentLevel->getSquare(row, col);
    if(square != NULL) {
        square->occupied = true;
        if(currentSquare != NULL)
            currentSquare->occupied = false;
        previousSquare = currentSquare;
        currentSquare = square;
    } else previousSquare = currentSquare;
}

void Character::move(int x, int y) {
    if(currentSquare != NULL)
        place(currentSquare->row + x, currentSquare->col + y);
    else
        place(0, 0);
}

void Character::moveAnimation(string sprite, int spriteRenderCycle, Directions direction, int pixelOffset) {
    int y=previousSquare->rect.y, x=previousSquare->rect.x;
    switch(direction) {
        case NORTH: y=previousSquare->rect.y-pixelOffset;break;
        case EAST:  x=previousSquare->rect.x+pixelOffset;break;
        case SOUTH: y=previousSquare->rect.y+pixelOffset;break;
        case WEST:  x=previousSquare->rect.x-pixelOffset;break;
    }
    std::cout << "\tpreviousX: " << previousSquare->rect.x << ", previousY: " << previousSquare->rect.y << "\n";
    std::cout << "\tPlacing character @ x: " << x << ", y: " << y << "\n";

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = previousSquare->rect.w;
    rect.h = previousSquare->rect.h;

    render(&rect, sprite + std::to_string(spriteRenderCycle));
}

void Character::render(SDL_Rect* rect, string sprite) {
    if(currentSquare != NULL) {
        if(sprite == "")
            texture = loadTexture("GUI/res/sprites/character/front/1.bmp");
        else texture = loadTexture(("GUI/res/sprites/character/" + sprite + ".bmp").c_str());

        if(rect == NULL)
            SDL_RenderCopy(renderer, texture, NULL, &currentSquare->rect);
        else SDL_RenderCopy(renderer, texture, NULL, rect);
    }
}

Character::Character(Level* level){
    currentLevel = level;
}

Character::~Character() {
    
}