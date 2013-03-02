//mainGame.cpp
#include "mainGame.hpp"

extern int ticks;
extern int counter;
extern int framerate;
extern int resting;
extern int rested;
extern int ticks2;

int mainGame( BITMAP *&buffer, BITMAP *&back, Player *&player, vector<Bubble> &bubbles, int level, int lives )
{
        bool exitLoop = false;
        int col = 0;
        do
        {             
             player->setPosX(mouse_x-player->getWidth()/2);
             blit( back, buffer, 0 ,0 ,0, 0, back->w, back->h );
//             draw_sprite( buffer, player->getImg(), player->getPosX(), player->getPosY() );
             textprintf_ex( buffer, font, 10, 10,23434445, 3242344343, "Level: %d", level );
             textprintf_ex( buffer, font, 10, 20,23434445, 3242344343, "Lives:%d", lives );
//             textprintf_ex( buffer, font, 10, 30,23434445, 3242344343, "bubble count:%d", bubbles[0].getSize() );
             
             updateSprites( player, bubbles );//updating the sprite positions
             
             col = collisionCheck( &bubbles, player->bullet, player );
             
             drawSprites( player, bubbles, buffer );//drawing the sprites in the buffer
                
             //update ticks
                ticks++;
                //display framerate
                blit(back, buffer, 320-70, 330, 320-70, 330, 140, 30);
                textprintf_centre_ex(buffer,font,320,330, 343434343,-1,"COUNTER %d", counter);
                textprintf_centre_ex(buffer,font,320,340, 343434343,-1,"FRAMERATE %d", framerate);
                textprintf_centre_ex(buffer,font,320,350, 343434343,-1,"RESTING %d", rested);
                textprintf_centre_ex(buffer,font,320,360, 343434343,-1,"TICKS2 %d", ticks2);
             
             acquire_screen();
             blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
             release_screen();
             exitLoop = getInput(player);
             
             //slow the game down
            resting=0;
            rest_callback(10, rest1);
        }while (!exitLoop && !col);
        
            textprintf_ex(screen,font,20,30,3242334,0,"COL:%d",col );
            rest (800);
        if ( col ) 
        {
             textprintf_ex(screen,font,30,40,3242334,0,"resting");
             rest (1000);
        }
        return col;
}
