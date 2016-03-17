//
//  Sprite.hpp
//  Game
//
//  Created by Christo on 2/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp
#include <string>
#include <stdio.h>
#include "SDL_image.h"
#include <iostream>

class Sprite{

public:

	Sprite(std::string t, SDL_Renderer *r);
    
    SDL_Texture* texture;
    SDL_Rect* targetRect;
    SDL_Rect* sourceRect;
    SDL_Renderer *renderer;
    
    
    
private:
    SDL_Texture* loadTexture( std::string path,SDL_Renderer *renderer  );
    
};


#endif /* Sprite_hpp */
