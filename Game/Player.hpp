//
//  Player.hpp
//  Game
//
//  Created by Christo on 3/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Sprite.hpp"


class Player{

public:
    
    Player();
    ~Player();
    
    
private:
    
    Sprite *sprite;
    
};

#endif /* Player_hpp */
