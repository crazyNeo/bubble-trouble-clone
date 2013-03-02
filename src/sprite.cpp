//sprite.cpp

#include "headers/sprite.hpp"
#include "allegro.h"
//destructor for

Sprite::Sprite()
{
    img = NULL;
}

void Sprite::setImg( BITMAP *image )
{
     img = image;
}

Sprite::~Sprite()
{
     if ( img!= NULL)
          destroy_bitmap( img );        //there is a problem when destroying sprite                                        //i dont know the cause
}

BITMAP *Sprite::getImg()
{
       return (img);
}

int Sprite::getWidth()
{
    return img->w;
}

int Sprite::getHeight()
{
    return img->h;
}

void Sprite::setPosX( int x )
{
     this->x = x;
}

void Sprite::setPosY( int y )
{
     this->y = y;
}

int Sprite::getPosX()
{
    return x;
}

int Sprite::getPosY()
{
    return y;
}

void Sprite::loadBitmap()
{
     img = load_bitmap( "player.bmp", NULL);
}

void Sprite::setAlive( int val )
{
     alive = val;
}

int Sprite::getAlive()
{
     return alive;
}

void Sprite::setXspeed( int xs)
{
     xspeed = xs;
}

int Sprite::getXspeed()
{
    return xspeed;
}

void Sprite::setYspeed( int ys )
{
    yspeed = ys;
}

int Sprite::getYspeed()
{
    return yspeed;
}

void Sprite::drawSprite(BITMAP *buffer)
{
     if ( alive )
        draw_sprite( buffer, img, x - img->w / 2, y - img ->h / 2 );
}

void Sprite::update()
{
}

Bullet::Bullet():Sprite()
{
    alive = 0;
    createBullet();
}


void Bullet::createBullet()
{
     if ( img != NULL ) destroy_bitmap( img );
     img = create_bitmap( 7, 7 );
     clear_to_color( img, makecol( 255, 0 ,255 ) );
     circlefill( img, 3, 3, 3, makecol( 0, 0 ,0 ) );
}

void Bullet::setYspeed( int screen_h )
{
    yspeed = screen_h /150;
    tStart = screen_h*.9;
}

void Bullet::update()
{
     if (alive == 1 )
     {
        if( y >0 ) y -= yspeed;
        else alive = 0;
     }
}

void Bullet::drawSprite( BITMAP *buffer)
{
     if ( alive != 0 )
     {
         line(buffer, x, y, x, tStart, 23434 );
         Sprite::drawSprite( buffer );
     }
}

void Player::createPlayer()
{
    if ( img != NULL ) destroy_bitmap( img );
    img = create_bitmap( 50, 100);
    clear_to_color( img, makecol ( 255, 0, 255 ) );
    rectfill(img, 0, 40, 49, 99, makecol (255, 0 , 0) );
    circlefill( img, 25, 20, 20, makecol (0, 255, 34 ) );
}

Player::Player( int screen_h ):Sprite()
{
     alive = 1;
     bullet.setYspeed( screen_h );
}

void Player::fire()
{
     if ( bullet.getAlive() == 0 )
     {
         bullet.setAlive( 1 );
         bullet.setPosY( y );
         bullet.setPosX( x );
     }
}

void Player::bullet_update()
{
     bullet.update();
}
