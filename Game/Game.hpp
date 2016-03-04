//
//  Game.hpp
//  Game
//
//  Created by Christo on 2/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "Sprite.hpp"
#include <iostream>
#endif /* Game_hpp */


class Game{
    
public:
    
    // Constructor/Deconstructor
    
    Game();
    ~Game();
    
    // Functions
    
    bool init();
    void run();
    void draw(Sprite *s);
    
    // Variables
    bool quit;
    
private:
    
    // Functions
    
    
    // Variables
    SDL_Window *window;
    SDL_Renderer *renderer;
    
};