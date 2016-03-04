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
   
    
    Sprite *s = new Sprite("avatar.png", renderer);
    SDL_Rect renderQuad = { 43, 43, 43, 43 };

    s->targetRect = &renderQuad;
    
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
            //Set texture based on current keystate
            const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
            if( currentKeyStates[ SDL_SCANCODE_UP ] )
            {
                           }
            else if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
            {
                
            }
            else if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
            {
              std::cout << "LEFT" << std::endl;
                SDL_Rect renderQuad = { s->targetRect->x + 2, 43, 43, 43 };
                
                s->targetRect = &renderQuad;
            }
            else if( currentKeyStates[ SDL_SCANCODE_W] )
            {
               std::cout << "LEFTw" << std::endl;
            }
            else
            {
            }
            
            
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                /* If the left button was pressed. */
                if (e.button.button == SDL_BUTTON_LEFT) {
                    
                    int x = e.button.x;
                    int y = e.button.y;
                    
                    printf("Click x: %d y: %d\n", x, y);
                    SDL_Rect renderQuad = { x, y, s->targetRect->w + 10, s->targetRect->h + 10 };
                    
                    s->targetRect = &renderQuad;
                    
                }
                /* Quit the application */
                    
            }
            
            
     
        }
      
        
        
        // Handle Update
        
        
        // Handle Rendering
        
        
        
        draw(s);
        
       
        
        //get frame end time
        Uint32 endTime = SDL_GetTicks();
        
        if((endTime - startTime) < minFrameRate) {
            SDL_Delay(minFrameRate - (endTime - startTime));
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


void Game::draw(Sprite *s) {
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    
    //Clear screen
    SDL_RenderClear( renderer );

    SDL_RenderCopy( renderer, s->texture, s->sourceRect, s->targetRect);

    //Update screen
    SDL_RenderPresent( renderer );
}
