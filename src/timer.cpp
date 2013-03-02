//timer.cpp

#include "allegro.h"
//timer
//interrupt handler callback function
//calculate framerate once per second

        //timer variables
        extern int counter;
        extern int ticks;
        extern int framerate;
        extern int resting, rested;
        
        extern int ticks2;

void timer1(void)
{
    counter++;
    framerate = ticks;
    ticks=0;
    rested = resting;
}
END_OF_FUNCTION(timer1)

void timer2( void )
{
     ticks2++;
}

//do something while resting (?)
void rest1(void)
{
resting++;
}
