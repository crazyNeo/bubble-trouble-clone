//function.cpp

#include <vector>
#include "headers/sprite.hpp"
#include "headers/balloon.hpp"

using namespace std;

//updating the sprite positions
void updateSprites(Player *player, vector<Bubble> &bubbles)
{
     player->bullet_update();//updating the positions ot the player
     for ( int i = 0; i < bubbles.size() ; i++ )
     {
         if ( bubbles[i].b!= NULL) bubbles[i].b->update();
     }
}

//drawing the updated sprites
void drawSprites(Player *player, vector<Bubble> &bubbles, BITMAP *buffer)
{
     player->bullet.drawSprite( buffer );//drawing hte bullet sprite in the buffer
     player->drawSprite( buffer );// drawing the player spirte in the buffer
     for ( int i = 0; i < bubbles.size() ; i++ )
     {
         if ( bubbles[i].b!= NULL) bubbles[i].b->drawSprite( buffer );
     }
     //if (bubbles.size() == 1)
     // bubbles[0].b->drawSprite( buffer );

}

void createNewBubbles( vector<Bubble> *ball, int i )
{
     vector<Bubble> &bubbles = *ball;
     int x = bubbles[i].b->getPosX();
     int y = bubbles[i].b->getPosY();
     int rd= int( bubbles[i].b->getRadius()*.7 );
     int xspeed = bubbles[i].b->getXspeed();
     bubbles[i].b->setAlive(1);
     bubbles[i].b->setRadius( rd );
     bubbles[i].b->createBalloon( makecol(rand()%150+50, rand()%150+50, rand()%150+50 ) );
     bubbles[i].b->setPosX( x - rd/2 );
     bubbles[i].b->setPosY( y );
     xspeed =2 + rand()%2;
     bubbles[i].b->setXspeed( xspeed );

     
//     Bubble bb;
//     bb.b= new Balloon;
//     bubbles.push_back( bb );
//       bubbles.insert(bubbles.begin(), b);     
     
     int j=-1;
     int nul=0;
     for ( int k = 0 ; k < bubbles.size() ; k++)
     {
         if (bubbles[k].b == NULL )
         {
              j =k;
              nul = 1;
              break;
         }
         else if ( bubbles[k].b->getAlive() == 0)
         {
              j = k;
              break;
         }
     }
     if ( j>-1 )
     {
         if ( nul ==1 ) bubbles[j].b = new Balloon;
    
         bubbles[j].b->setRadius( rd );
         bubbles[j].b->createBalloon( makecol(rand()%150+50, rand()%150+50, rand()%150+50 ) );
         
         bubbles[j].b->setAlive(1);
         bubbles[j].b->setPosX( x + rd/2 );
         bubbles[j].b->setPosY( y );
         bubbles[j].b->setXspeed( -xspeed );
         bubbles[j].b->setYspeed( bubbles[i].b->getYspeed() );
         bubbles[j].b->setYr( bubbles[i].b->getYr() );
         bubbles[j].b->setStart( bubbles[i].b->getStart() );
         bubbles[j].b->setAcc( bubbles[i].b->getAcc() );
         bubbles[j].b->setYlim( bubbles[i].b->getYlim() );
     }
     /*
     b.setRadius( rd );
     b.createBubble( 324523533 );
     b.setPosX( x + rd/2 );
     b.setPosY( y );
     b.setXspeed( -xspeed );
     b.setYspeed( bubbles[i].b->getYspeed() );
     b.setYr( bubbles[i].b->getYr() );
     b.setStart( bubbles[i].b->getStart() );
     b.setAcc( bubbles[i].b->getAcc() );
     b.setYlim( bubbles[i].b->getYlim() );
     */
}

int collisionCheck( vector<Bubble> *ball, Bullet &bullet, Player *player)
{
     int col =0;
     vector<Bubble> &bubbles = *ball;
     for (int i = 0; i < bubbles.size(); i++ )
     {
         if ( bubbles[i].b != NULL )
         {
             if ( bubbles[i].b->getAlive() && bubbles[i].b->collision_player( player->getPosX(), player->getPosY(), player->getWidth(), player->getHeight() ) )
             {
                  col = 1 ;
                  player->setAlive(0);
             }
             else 
             if ( bullet.getAlive() != 0 && bubbles[i].b->getAlive() && bubbles[i].b->collision_bull( bullet.getPosX(), bullet.getPosY() ) )
             {
                  bullet.setAlive( 0 );
                  bubbles[i].b->setAlive(0);
                  if (bubbles[i].b->getRadius()>15 )
                  {
                       createNewBubbles( ball , i );
                       ++bubbles[i];
                  }
                  else
                  {
                       --bubbles[i];
                       if ( !bubbles[i].getSize() ) col = 2;
                  }
                  //else bubbles.erase( bubbles.begin() + i);
             }
         }
     }
     return col;
}

/*
void createNewBubbles( vector<Bubble> *ball, int i)
{
     vector<Bubble> &bubbles = *ball;
     int x = bubbles[i].b->getPosX();
     int y = bubbles[i].b->getPosY();
     int rd= bubbles[i].b->getRadius();
     bubbles[i].b->setPosX(x);
     bubbles[i].b->setPosY(y);
     bubbles[i].b->setRadius( int(rd*.7) );     
}
*/
