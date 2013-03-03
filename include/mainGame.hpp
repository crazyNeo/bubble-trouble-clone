//mainGame.h
#ifndef MAINGAME_HPP
#define MAINGAME_HPP

#include <vector>
#include "allegro.h"
#include "sprite.hpp"
#include "balloon.hpp"
#include "input.hpp"
#include "functions.hpp"
#include "timer.hpp"

using namespace std;

int mainGame( BITMAP *&buffer, BITMAP *&back, Player *&player, vector<Bubble> &bubbles, int level, int lives );

#endif
