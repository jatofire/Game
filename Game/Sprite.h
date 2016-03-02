//
//  Sprite.hpp
//  Game
//
//  Created by Christo on 2/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h
#include <string>
#include <stdio.h>
#include "SDL2_image/SDL_image.h"

class Sprite {

public:

    Sprite();

private:
    SDL_Texture* loadTexture( std::string path,SDL_Renderer *renderer  );
    
};


#endif /* Sprite_hpp */
