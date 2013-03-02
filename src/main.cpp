#include "definePrepro.hpp"


#include <vector>
#include <allegro.h>
#include "sprite.hpp"
#include "init_n_destroy.hpp"
#include "balloon.hpp"
#include "mainGame.hpp"
#include "starting.hpp"

using namespace std;

//#define MODE GFX_AUTODETECT_FULLSCREEN
#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 800
#define HEIGHT 600

        //timer variables
        volatile int counter;
        volatile int ticks;
        volatile int framerate;
        volatile int resting, rested;
        volatile int ticks2;

int main()
{
    //initialization
    allegro_init();
    set_color_depth(32);
    set_gfx_mode( MODE, WIDTH, HEIGHT, 0, 0 );
    
    //installing keyboard
    install_keyboard();
    
    //installing mouse
    install_mouse();
    
    //installing timer()//lock interrupt variables
    LOCK_VARIABLE(counter);
    LOCK_VARIABLE(framerate);
    LOCK_VARIABLE(ticks);
    LOCK_VARIABLE(ticks2);
    LOCK_FUNCTION(timer1);
    LOCK_FUNCTION(timer2);
    //create the interrupt handler
    install_int(timer1, 1000);
    install_int(timer2, 10);
        
//    textout_ex(screen, font, "Bubble Trouble", 1, 1, 10, -1);
//    textout_ex( screen, font, "Loadding", 1, 12, 11, -1 );
//    textout_ex(screen, font, "Press Enter to Start.", 1, 23, 11, -1);
    {
		starting();
		//exit(0);
		
        //declaring variables
        Player *player;//this is the sprite for the player
        player = new Player( SCREEN_H );
        
        BITMAP *buffer;//this is the screen buffer        
        BITMAP *back;
        vector<Bubble> bubbles(8);
        
        //initializing hte background and the buffer
        initBackground( back, buffer );
        initPlayer( player );
        
        int radius = 30;
        int no = 1;
    
        //initializing mouse
        set_mouse_sprite(NULL);
        show_mouse(screen);
                
        //hiding the mouse
        scare_mouse();
        
        int level = 1;
        int lives = 5;
        int col=0;
        do
        {
            initBubbles( bubbles, SCREEN_H, radius, no);
            
            col = mainGame( buffer, back, player, bubbles, level, lives );
            switch (col)
            {
                   case 1:
                        lives--;
                        player->setAlive(1);
                        break;
                        
                   case 2:
                        level++;
                        radius+= 10;
                        if ( radius > 51 )
                        {
                             radius = 35 - level;
                             no++;
                        }
                        break;
            }
        }while ( col && lives );
        
        //destroying the background and buffer
        {    
             destroy_bitmap( back );
             destroy_bitmap( buffer );
             delete player;
        }
    }
    //exit allegro
    allegro_exit();
    return 0;
}
END_OF_MAIN()
