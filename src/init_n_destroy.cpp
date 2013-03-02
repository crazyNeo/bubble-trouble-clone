//init_sprites.cpp
//initialize player

#include <vector>
#include <time.h>
#include <cmath>
#include "allegro.h"
#include "headers/sprite.hpp"
#include "headers/balloon.hpp"

using namespace std;
//initializing the background
void initBackground( BITMAP *&back, BITMAP *&buffer )
{
     buffer = create_bitmap( SCREEN_W, SCREEN_H );
     back = create_bitmap( SCREEN_W, SCREEN_H );
     clear_to_color( back, makecol( 89,78,10) );
//     rectfill( back, 89, 40, 340, 170, makecol( 23, 132, 43 ) );
     rectfill( back, 0, int(SCREEN_H *.9), SCREEN_W-1, SCREEN_H-1, makecol( 23, 54, 222 ) );
}
/*
BITMAP *createPlayer()
{
    BITMAP *img = create_bitmap( 50, 100);
    clear_to_color( img, makecol ( 255, 0, 255 ) );
    rectfill(img, 0, 40, 49, 99, makecol (255, 0 , 0) );
    circlefill( img, 25,20, 20, makecol (0, 255, 34 ) );
    return img;
}*/

void initPlayer( Player *player )
{
//    player.setImg( createPlayer() );
//      player->loadBitmap();
      player->createPlayer();
    player->setPosX( SCREEN_W/2);
    player->setPosY( int(SCREEN_H*.9)-player->getHeight()/2 );    
}

void initBubbles( vector<Bubble> &bubbles, int yl, int r, int no )
{
     srand(time(NULL));
     extern int ticks2;
     for (int i = 0 ; i < no; i++ )
     {
         int xspeed = 2 + rand()%3;
         int yspeed = sqrt( 2 * 1 * r * 13);
         int acc = 1;
         int ylim = yl * .9;
         int start = ticks2 - yspeed/acc * 5;
         bubbles[i].resetSize();
//         if ( bubbles[i].b == NULL ) 
            bubbles[i].b= new Balloon;
         ++bubbles[i];
         bubbles[i].b->setRadius( r );
         bubbles[i].b->createBalloon( makecol(rand()%150+50, rand()%150+50, rand()%150+50 ) );
         bubbles[i].b->setPosX(rand() %600 + 100);
         bubbles[i].b->setPosY(100);//useless
         bubbles[i].b->setXspeed( xspeed );
         bubbles[i].b->setYspeed( yspeed );
         bubbles[i].b->setYr(0);//useless
         bubbles[i].b->setAcc( acc );
         bubbles[i].b->setYlim( ylim );
         bubbles[i].b->setStart( start );
     }
     for (int i = no ; i < bubbles.size(); i++ )
     {
         if ( bubbles[i].b!=NULL ) bubbles[i].b->setAlive( 0 );
     }
}
