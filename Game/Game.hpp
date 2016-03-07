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
#include "Camera.hpp"
#include "GameObject.hpp"
#include <iostream>
#include <vector>
#endif /* Game_hpp */


class Game{
    
public:
    
    // Constructor/Deconstructor
    
    Game();
    ~Game();
    
    // Functions
    
    bool init();
	void draw(GameObject * obj);
    void run();
  
    std::vector<GameObject> objs;
    // Variables
    bool quit;
	std::vector<SDL_Rect> rects;
    
    Camera camera;
    GameObject *gCam;
private:
    
    // Functions
    
    
    // Variables
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    void objectAt(int x, int y);
    
};