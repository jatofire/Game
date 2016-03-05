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

Game::~Game()
{
}

void Game::run() {
    
    SDL_Event e;
    float minFrameRate = 1000/60;
    //While application is running
   
    
	
    SDL_Rect renderQuad = { 43, 43, 43, 43 };
	GameObject *player = new GameObject(renderQuad, renderer);
    
    
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

					

                    int dif_x = x % 32;
                    int dif_y = y % 32;
                    
                    SDL_Rect r = { x - dif_x, y - dif_y, 32, 32 };
                    GameObject o = GameObject(r, renderer);
                    objs.push_back(o);
                   // std::cout << objs.size() << std::endl;

					//player->moveTo(x, y, 1.0f);
                    
                }
             
                if(e.button.button == SDL_BUTTON_RIGHT) {
                    int x = e.button.x;
                    int y = e.button.y;
                    
                    printf("Right Click x: %d y: %d\n", x, y);
					objectAt(x, y);
					//std::cout << "Hello: "  << o.getRect().x << std::endl;
                }
                    
            }
            
            
            
            
			if (e.type == SDL_MOUSEMOTION) {

				
				

                int x = e.button.x;
                int y = e.button.y;
             
            

			}
            
            
     
        }
      
        
        
        // Handle Update
		player->update();
        
        // Handle Rendering
        
        
        
        draw(player);
        
       
        
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

void Game::objectAt(int x, int y)
{
	SDL_Rect checkRect = { x, y, 1, 1 };
	SDL_Rect result;
	for (int i = 0; i < objs.size(); i++) {
		SDL_Rect c = objs[i].getRect();
		if (SDL_IntersectRect(&checkRect, &c, &result) ){
			objs.erase(objs.begin() + i);
			std::cout << "Erase" << std::endl;
		
		}
	}
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
        window = SDL_CreateWindow( "C++ Game",
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


void Game::draw(GameObject *obj) {
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    
    //Clear screen
    SDL_RenderClear( renderer );

   
	SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 0xFF);
	for (int i = 0; i < 800; i += 32) {
		//
			SDL_RenderDrawLine(renderer, i, 0, i, 450);
	}
	for (int j = 0; j < 450; j += 32) {
		SDL_RenderDrawLine(renderer, 0, j, 800, j);
	}
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x88);
	
	int difX = obj->getRect().x % 32;
	int difY = obj->getRect().y % 32;

    SDL_Rect r = {obj->getRect().x - difX, obj->getRect().y - difY, obj->getRect().w, obj->getRect().h};
	SDL_RenderFillRect(renderer, &r);
    
    for (int k = 0; k < objs.size(); k++) {
        // mstd::cout << k << " " << objs[k].getRect().x << std::endl;
        SDL_Rect r = objs[k].getRect();
        SDL_RenderFillRect(renderer, &r);

    }
    
	
	

	 SDL_RenderCopy( renderer, obj->getSprite()->texture, obj->getSprite()->sourceRect, &obj->getRect());

	 //SDL_RenderCopy( renderer, obj->getSprite()->texture, obj->getSprite()->sourceRect, obj->getRect());

    //Update screen
    SDL_RenderPresent( renderer );
}
