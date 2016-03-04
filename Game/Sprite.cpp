//
//  Sprite.cpp
//  Game
//
//  Created by Christo on 2/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#include "Sprite.hpp"





Sprite::Sprite(std::string t, SDL_Renderer *r) {
    renderer = r;
    texture = loadTexture(t, renderer);
    sourceRect = NULL;
    targetRect = NULL;
}
           
           
           
           
           

SDL_Texture* Sprite::loadTexture( std::string path, SDL_Renderer *renderer )
    {
        //The final texture
        SDL_Texture* newTexture = NULL;
        
        //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		std::cout << path << std::endl;
        if( loadedSurface == NULL )
        {
            printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        }
        else
        {
            //Create texture from surface pixels
            newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
            if( newTexture == NULL )
            {
                printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            }
            
            //Get rid of old loaded surface
            SDL_FreeSurface( loadedSurface );
        }
        
        return newTexture;
    }
