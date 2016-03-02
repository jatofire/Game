//
//  Game.cpp
//  Game
//
//  Created by Christo on 2/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#include "Game.hpp"


Game::Game() {
    quit = false;
}

void Game::run() {
    
    SDL_Event e;
    float minFrameRate = 1000/60;
    //While application is running
    while( !quit )
    {
        
        //get framstarttime
        Uint32 startTime = SDL_GetTicks();
        
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        
        
        
        // Handle Update
        
        
        // Handle Rendering
        
        
        
        
        
       
        
        //get frame end time
        Uint32 endTime = SDL_GetTicks();
        
        if((endTime - startTime) < minFrameRate) {
            //SDL_Delay(minFrameRate - (endTime - startTime));
        }
        
       //                                   std::cout << 1000 / (SDL_GetTicks() - startTime) << std::endl;
        
        
    }
    
    
    SDL_DestroyWindow(window);
    
    // Clean up
    SDL_Quit();
}


bool Game::init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  450,
                                  SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                // gScreenSurface = SDL_GetWindowSurface( window );
            }
        }
    }
    
    
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    
    if( renderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Initialize renderer color
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        
    }
    
    
    return success;
}


void Game::draw() {
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0xFF, 0xFF );
    
    //Clear screen
    SDL_RenderClear( renderer );
    
    ////Render texture to screen
    //SDL_Rect renderQuad = { 43, 43, 43, 43 };
    //SDL_RenderCopy( renderer, gTexture, NULL,&renderQuad);
    
    
    
    //Update screen
    SDL_RenderPresent( renderer );
}
