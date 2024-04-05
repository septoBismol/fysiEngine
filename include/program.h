#ifndef PROGRAM_H
#define PROGRAM_H
#include <SDL2/SDL.h>

class program {
public:
    SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);
    program(); // Constructor
    void run();
private:
    SDL_Texture* texture; // this is the background
    void windowLoop();
    bool init();
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Renderer* renderer = NULL;
};

#endif 