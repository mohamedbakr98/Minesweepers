#include "frames.h"
#include "Board.h"
#include <windows.h>
void gotoxy_m(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void welcome(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    gotoxy_m(32,12);
    printf("---------->   ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    printf("Welcome press any key to begin");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    printf("   <----------");
    gotoxy_m(46,15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    getch();
}
void main_frame(){
    system("cls");
    showBoard(board);
    draw_result();
}
struct tm* get_time(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return timeinfo;
}
void draw_time(time_t startingTime){
    time_t now = time(NULL);
    time_t diff = now - startingTime;
    showTimeInMinutesAndSeconds(diff,48,4);
}
void showTimeInMinutesAndSeconds(time_t time,int x,int y){
    int minutes = time / 60;
    int seconds = time % 60;
    gotoxy_m(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("%d:%d",minutes,seconds);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void input(){
    if(_kbhit()){
        int c1 = getch();

        if(c1 == 224/**< One of the Arrow keys is Pressed */){
            switch(getch()){
                case 72: //up
                    rowsPos = setCursorPosition(rowsPos-1);
                    break;
                case 80: //down
                    rowsPos = setCursorPosition(rowsPos+1);

                    break;
                case 75: //left
                    colsPos = setCursorPosition(colsPos-1);

                    break;
                case 77: //right
                    colsPos = setCursorPosition(colsPos+1);
                    break;
            }
            system("cls");
            draw_result();
            showBoard(board);
        }else if(c1 == 13/**< ENTER */){
            /// Logic is done here.
            checkInSetPosition(board,rowsPos,colsPos);
            main_frame();
        }else if(c1 == 27/**< ESCAPE */){
            welcome();
            startgame();
            main_frame();
            /// this one clears the screen and return to the menu.
        }else if((c1 == 'f' || c1 == 'F') && board[rowsPos][colsPos].isCovered == 1){
            if(board[rowsPos][colsPos].hasFlag == 0){
                board[rowsPos][colsPos].hasFlag = 1;
            }else{
                board[rowsPos][colsPos].hasFlag = 0;
            }
        }
    }
}
int askIfPlayerWantNewGame(){
    system("cls");
    int noChange = 0;
    gotoxy_m(32,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("Do you want to player again? Press N if you want to quit.");
    switch(getch()){
    case 'n':
    case 'N':
        system("cls");
        gotoxy_m(5,30);
        exit(EXIT_SUCCESS);
        break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    return noChange;
}
void printMenu(){
    gotoxy_m(80,6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("Instructions:");
    gotoxy_m(81,8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    printf("1) Press Enter to Uncover a field");
    gotoxy_m(81,10);
    printf("2) Press F to put a ");
    gotoxy_m(81+strlen("2) Press F to put a "),10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    printf("Flag");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    printf(".");

}
