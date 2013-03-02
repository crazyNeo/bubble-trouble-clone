//functions.h

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include "balloon.hpp"

using namespace std;

void updateSprites(Player *player, vector<Bubble> &bubbles);
void drawSprites(Player *player, vector<Bubble> &bubbles, BITMAP *buffer);
int collisionCheck( vector<Bubble> *ball, Bullet &bullet, Player *player);
void createNewBubbles( vector<Bubble> *ball, int i);

#endif
