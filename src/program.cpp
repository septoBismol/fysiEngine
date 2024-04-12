#include "../include/program.h"
#include "../include/constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
program::program(){
    
}
SDL_Texture* program::loadTexture(const char* path, SDL_Renderer* renderer){
    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
        return NULL;
    }

    // Create texture from surface pixels
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (texture == NULL) {
        printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        SDL_FreeSurface(loadedSurface);
        return NULL;
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

    return texture;
}
bool program::init(){
    bool success = false;
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("%s\n", SDL_GetError());
    }else{
        window = SDL_CreateWindow( "fysiEngine v0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return success;
        } else {
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		    {
			printf( "Warning: Linear texture filtering not enabled!" );
		    }
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                return success;
            }
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                return success;
            }
        }
    }
    success = true;
    return success;
}
void program::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderDrawColor( renderer, 0x0, 0xFF, 0x0, 0xFF );
    SDL_RenderDrawRect(renderer, &rectangle.rect);
    SDL_RenderDrawLine(renderer, floor(rectangle.x+rectangle.width/2), floor(rectangle.y+rectangle.height/2), floor(rectangle.x+rectangle.width/2)+ceil(sin(degreesToRadians(rectangle.dir)) * rectangle.width), floor(rectangle.y+rectangle.height/2)+ceil(cos(degreesToRadians(rectangle.dir)) * rectangle.height));
    SDL_SetRenderDrawColor( renderer, 0x80, 0x80, 0x80, 0xFF );
    SDL_RenderPresent(renderer);
}
void program::physics(){
    rectangle.stepMovement();
}
void program::windowLoop(){
    SDL_Event e; 
    bool quit = false; 
    while( quit == false ){ 
        while( SDL_PollEvent( &e ) ){
            if( e.type == SDL_QUIT ){
                quit = true; 
            } 
        } 
        physics();
        render();  
        SDL_Delay(33); 
    }
}
void program::initObjects(){
    texture = loadTexture("resources/pandabear.png", renderer);
    if (texture == NULL) {
        printf("Failed to load texture image!\n");
        return;
    }
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    if (SDL_SetTextureAlphaMod(texture, 128) == 0){
        printf("%s\n",SDL_GetError());
    }
    
}

void program::run(){
    init();
    initObjects();
    windowLoop();
    
      //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return;
}
