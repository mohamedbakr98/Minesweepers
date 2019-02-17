#include "game.h"
#include "Board.h"
#include "frames.h"
#include "player.h"
void startgame(){
    playerLost = 0;
    playerWon = 0;
    startingTime = time(NULL);
    coveredElementsLeft = DIMENSION * DIMENSION - NUMBER_OF_MINES;
    fillBoard(board);
}

