//init_n_destroy.h

#ifndef INIT_N_DESTROY_HPP
#define INIT_N_DESTROY_HPP

#include <vector>
#include "allegro.h"
#include "balloon.hpp"

using namespace std;

void initBackground( BITMAP *&back, BITMAP *&buffer );
BITMAP *createPlayer();
void initPlayer( Player *player );
void initBubbles( vector<Bubble> &bubbles, int yl, int r, int no );
#endif
