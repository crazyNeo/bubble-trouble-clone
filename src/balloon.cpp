//balloon.cpp

#include <cmath>
#include "headers/balloon.hpp"

/*
Balloon::Balloon()//:Sprite()
{
  alive = 1;
}*/

void Balloon::setRadius( int rad )
{
     radius = rad;
}

int Balloon::getRadius()
{
     return radius;
}

void Balloon::createBalloon(long col)
{
     if ( img != NULL ) destroy_bitmap( img );
     img = create_bitmap( 2 * radius + 1, 2* radius +1 );
     clear_to_color( img, makecol(255, 0, 255 ) );
     circlefill( img, radius, radius, radius, col );
     setPosX( 400 );
     setPosY( 300 );
//     int h = radius * 13;
//     yspeed = sqrt( 2 * acc * h );
}

void Balloon::update()
{
     if ( alive == 1)
     {
         extern int ticks2;
    //     static int c= 0;
         if (! ( 0 <= (x - radius)  && ( x + radius ) < 800 ) )
            xspeed*=-1;// change in direction of velocity when the ball stirke the side walls
         //if (! ( y > 0 + radius && y < 600 - radius ) )
         //   yspeed*=-1;// change in direction of velocity when the ball stirke the ground
    //     c++;
         dt = ( ticks2 - start )/5.0;
         //dt=c/4.0;
         x += xspeed;//updating the xspeed
         yr = int (yspeed * dt - acc * dt *dt /2.0 ); //s= ut+at*t/2;
         if ( yr < 0 )
         {  
              //yr = 0;
    //          c=0;
    //          rest (500);
              start = ticks2;
              yr = 0;
              if ( yspeed * yspeed / (2 *acc ) > radius * 11 ) yspeed -= 2;
         }
         y = (ylim - radius) - yr ;
     }
}

void Balloon:: setYr( int val )
{
     yr = val;
}

void Balloon::setStart( int t )
{
     start = t;
}

void Balloon::setAcc( int a)
{
     acc = a;
}

void Balloon::setYlim( int yl )
{
     ylim = yl;
}

int Balloon::getYr()
{
    return yr;
}

int Balloon::getStart()
{
    return start;
}

int Balloon::getAcc()
{
    return acc;
}

int Balloon::getYlim()
{
    return ylim;
}

bool Balloon::collision_bull( int x1, int y1 )
{
     //           * is the position of the balloon
     
     //          |__________|  
     //          V          V    
     ////////////|*///000///|/////////////////
     ////////////|//0000000/|/////////////////
     ////////////|00000^0000|//////////////   << above the radius so collisoin this case is theoritically less likely to occur
     ////////////|/0000|000/|/////////////////...IN BETWEEN CANT SAY
     ////////////|///00|0///|/////////////////...
     ////////////|/////|////|///////////////  <---- if below the radius then no collision
     ////////////|/////|//^/|/////////////////
     ////////////|/////|//|/|/////////////////
     ////////////|/////|//|/|/////////////////
     ////////////|/////|//|/|/////////////////
     //                   |
     //                   |
     //                   no collision
     
     if ( x - radius-4 <= x1 && x1 <= x + radius + 4 )//making sure x of bullet is inside the range of the radius of the bubble
     {
          if ( y >= y1 )//<< above the radius so collisoin this case is theoritically less likely to occur
               return true;
          else
          {
               int dist = sqrt( pow(( x - x1 ),2) + pow(( y - y1 ),2) );
               if ( dist <= radius  )
               return true;
//               textprintf_ex(screen,font,200,200,3242334,0,"dist" );
          }
              
     }
     return false;
}

/*inline bool pInsideRad( int x1, int y1, int xx, int yy, int r)
{
       if ( sqrt( pow( x1 - xx, 2) + pow( y1 - yy, 2) ) < r )
          return true;
       else return false;
}*/

bool Balloon::collision_player( int xx, int yy, int w, int h )
{    
     int pY1 = yy - h/4;
     int pY2 = yy + h/4;
     int pX = xx;
     int rad1 = w/2;
     int rad2 = h/4;
     int meanRad = ( rad1 + rad2 ) / 2 + radius;
     
     if ( sqrt( pow( x - pX, 2) + pow( y - pY1, 2) ) < meanRad*.95  || //head is smaller
          sqrt( pow( x - pX, 2) + pow( y - pY2, 2) ) < meanRad  )
        return true;
     else
        return false;
}

Balloon:: Balloon():Sprite()
{
  alive = 1;
}


int Bubble::size = 0;

Bubble::Bubble()
{
    b = NULL;
    size++;
}

Bubble::~Bubble()
{
     if ( b != NULL ) delete b;
     size--;
}

void Bubble::operator ++()
{
     ++size;
}

void Bubble::operator --()
{
     --size;
}

int Bubble::getSize()
{
    return size;
}

void Bubble::resetSize()
{
     size = 0;
}
