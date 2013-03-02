//balloon.h
#ifndef BALLOON_HPP
#define BALLOON_HPP
#include "sprite.hpp"

class Balloon: public Sprite
{
      private:
              int radius;
              int yr;//y relative to the ground
              int start;
              int acc;
              float dt;
              int ylim;
//              int colour;
      public:
             Balloon();
             void setRadius( int rad );
             int getRadius();
//             void setColour();
//             void getColour();
             void createBalloon( long col );
             void update();
             void setYr( int val );
             int getYr();
             void setStart( int t );
             int getStart();
             void setAcc( int a);
             int getAcc();
             void setYlim( int yl  );
             int getYlim();
             bool collision_bull( int x, int y );             
             bool collision_player( int xx, int yy, int w, int h );
};

/*class Bubble
{
      private:
              
      public:
             Balloon *b;       
             Bubble();
             ~Bubble();                     
};
*/

class Bubble
{
      private:
             static int size;           
      public:
             Balloon *b;
             Bubble *next;   
             Bubble();
             ~Bubble();
             void operator ++();         //prefix ++
             void operator --();         //prefix --
             int getSize();
             void resetSize();
};
#endif
