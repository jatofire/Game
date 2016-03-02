//
//  main.cpp
//  Game
//
//  Created by Christo on 1/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#include <iostream>
#include "SDL2/SDL.h"
#include "Sprite.h"

SDL_Window *window;
SDL_Surface *gScreenSurface;
SDL_Renderer *gRenderer;
SDL_Texture* gTexture = NULL;



SDL_Texture* loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    return newTexture;
}







int main(int argc, const char * argv[]) {
    
    bool quit = false;
    SDL_Event e;
    init();

    
    gTexture = loadTexture("avatar.png");
    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    
        //Clear screen
        SDL_RenderClear( gRenderer );
        
        //Render texture to screen
        SDL_Rect renderQuad = { 43, 43, 43, 43 };
        SDL_RenderCopy( gRenderer, gTexture, NULL,&renderQuad);
        
        
        
        //Update screen
        SDL_RenderPresent( gRenderer );
    }
    

    SDL_DestroyWindow(window);
    
    // Clean up
    SDL_Quit();
    
    return 0;
}
