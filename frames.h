#ifndef FRAMES_H_INCLUDED
#define FRAMES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Board.h"
#include "game.h"

int  rowsPos, colsPos;
void welcome();
void gotoxy_m(int x, int y);
void input();
void main_frame();
void draw_time(time_t startingTime);
void hidecursor();
struct tm* get_time();
void showTimeInMinutesAndSeconds(time_t time,int x,int y);
int askIfPlayerWantNewGame();
void printMenu();
#endif // FRAMES_H_INCLUDED
