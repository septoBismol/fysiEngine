#ifndef PROGRAM_H
#define PROGRAM_H
#include <SDL2/SDL.h>
#include "axisrectangle.h"

class program {
public:
    SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);
    program(); // Constructor
    void run();
private:
    SDL_Texture* texture; // this is the background
    void windowLoop();
    bool init();
    void initObjects();
    void physics();
    void render();
    axisrectangle rectangle = axisrectangle(100,100,45,5);
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Renderer* renderer = NULL;
};

#endif 