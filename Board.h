#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "frames.h"
int setCursorPosition(int pos);
int minesLeft;
int coveredElementsLeft;
int playerLost;
int playerWon;
typedef struct boardElement{
    char isCovered;
    char hasMine;
    char numOfMinesTouching;
    char hasFlag;

} Element;
Element board[DIMENSION][DIMENSION];
void setMines(Element board[][DIMENSION]);
void fillBoard(Element board[][DIMENSION]);
void showBoard(Element board[][DIMENSION]);
void checkInSetPosition(Element board[][DIMENSION],int xPos,int yPos);
void draw_result();
int openAllConnectedEmptyElementsRecursive(Element board[][DIMENSION],int row,int col,int lastOneWasTouchingAMine);
void openAllConnectedEmptyElementsIterative(Element board[][DIMENSION],int row,int col);
#endif // BOARD_H_INCLUDED
