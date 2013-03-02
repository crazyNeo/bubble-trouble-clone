//sprite.cpp
//sprite class
#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <allegro.h>

class Sprite
{
      protected:
          int dir, alive;
          int x, y;
          int xspeed, yspeed;
          BITMAP *img;
          
      public:
             Sprite();
             ~Sprite();
             void initializePlayer();
             void setImg( BITMAP *image );
             void loadBitmap();
             BITMAP *getImg();
             int getWidth();
             int getHeight();
             void setPosX( int x );
             void setPosY( int y );
             int getPosX();
             int getPosY();
             void setXspeed( int xs);
             int getXspeed();
             void setYspeed( int ys );
             int getYspeed();
             void setAlive(int val);
             int getAlive();
             void drawSprite( BITMAP *buffer);
             virtual void update();//should have declared  pure virtual but Player class does not need update
};

class Bullet: public Sprite
{
      private:
              int tStart;//thread starting y coordindate
      public:
             Bullet();
             void setYspeed( int screen_h );
             void update();      
             void createBullet();      
             void drawSprite( BITMAP *buffer);
};

class Player: public Sprite
{
      private:
             
      public:
             Bullet bullet;
             
             Player( int screen_h );             
             void createPlayer();
             void fire();
             void bullet_update();
};

#endif
