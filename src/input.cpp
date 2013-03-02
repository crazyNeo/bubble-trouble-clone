//input.cpp
#include <allegro.h>

#include "headers/sprite.hpp"
bool getInput(Player *player)
{
     if ( keypressed () ) 
     {
          if ( key[KEY_ESC] ) return true;
     }
     
     if ( mouse_b & 1)
     {
        player->fire();
     }
     
     return false;
}
