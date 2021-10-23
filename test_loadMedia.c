#include "maze.h"

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
    if(gHelloWorld == NULL)
    {
        printf( "Unable to load image SDL Error: %s\n", SDL_GetError() );
        success = false;
    }

    return success;
}
