//
//  main.cpp
//  Game
//
//  Created by Christo on 1/03/2016.
//  Copyright © 2016 Christopher Moltzen. All rights reserved.
//

#include <iostream>
#include "Game.hpp"











int main(int argc, const char * argv[]) {
    
    Game *game = new Game();
    game->init();
    game->run();


    
    
   
    
    return 0;
}
