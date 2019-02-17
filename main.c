#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#include "game.h"
#include "Board.h"
#include "frames.h"
#include <conio.h>

int main()
{
    int ask;
    hidecursor();
    newGame = 1;
    welcome();
    SMALL_RECT windowSize = {0,0,100,50};
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("MineSweeper");
    SetConsoleWindowInfo(handle,1,&windowSize);
    while(newGame){
        startgame();
        main_frame();
        while(playerLost == 0){
            draw_time(startingTime);
            input();
            if(playerWon == 1){
                main_frame();
                takePlayersDataInSaveToFile();
                break;
            }
            printMenu();
        }
        system("cls");
        askIfPlayerWantNewGame();
        Sleep(1000);
    }
    return 0;
}
