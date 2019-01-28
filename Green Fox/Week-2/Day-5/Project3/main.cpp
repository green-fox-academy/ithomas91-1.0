#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void draw()
{
    int x = 20;
    int y = 340;
    int z = 0;

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(gRenderer, 20, 480, 340, 0);

    for(int i = 0; i <= 30; i++){

            x += 20;
            y += 10;
            z += 15;
            SDL_RenderDrawLine(gRenderer, x, 480, y, z);
    }

    int x1 = 330;
    int y1 = 15;
    int z1 = 640;

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(gRenderer, 340, 0, 660, 480);

    for(int i = 0; i < 31; i++) {
        SDL_RenderDrawLine(gRenderer, x1, y1, z1, 480);

        x1 -= 10;
        y1 += 15;
        z1 -= 20;
    }
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(gRenderer, 20, 480, 660, 480);

        int x2 = 20;
        int y2 = 480;
        int z2 = 660;
        int v2 = 480;

        for(int i = 0; i < 32; i++){
            SDL_RenderDrawLine(gRenderer, x2, y2, z2, v2);

            x2 += 10;
            y2 -= 15;
            z2 -= 10;
            v2 -=15;

        }





   // SDL_RenderDrawLine(gRenderer, 640, 480, 320, 0);
    //SDL_RenderDrawLine(gRenderer, 0, 480, 640, 480);







}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Horizontal lines", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN |SDL_WINDOW_ALLOW_HIGHDPI );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}