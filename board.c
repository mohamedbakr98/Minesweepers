#include "Board.h"
#include "game.h"
#include "player.h"
#include <windows.h>
int rowsPos = 0;
int colsPos = 0;
int playerLost = 0;
int playerWon = 0;
int minesLeft = NUMBER_OF_MINES;
int coveredElementsLeft = DIMENSION * DIMENSION - NUMBER_OF_MINES;
int positionExists(int xPos,int yPos){
    return (xPos >= 0 && xPos < DIMENSION) && (yPos >= 0 && yPos < DIMENSION);
}
void setTouchingMinesNumbers(Element board[][DIMENSION]){
    int i,j;
    for(i = 0 ; i < DIMENSION ; i++){
        for(j = 0 ; j < DIMENSION ; j++){
            /// now we need to sum:
            /// up
            if(positionExists(i-1,j)){
                board[i][j].numOfMinesTouching += board[i-1][j].hasMine;
            }
            /// up right
            if(positionExists(i-1,j+1)){
                board[i][j].numOfMinesTouching += board[i-1][j+1].hasMine;
            }
            /// up left
            if(positionExists(i-1,j-1)){
                board[i][j].numOfMinesTouching += board[i-1][j-1].hasMine;
            }
            /// right
            if(positionExists(i,j+1)){
                board[i][j].numOfMinesTouching += board[i][j+1].hasMine;
            }
            /// left
            if(positionExists(i,j-1)){
                board[i][j].numOfMinesTouching += board[i][j-1].hasMine;
            }
            /// down
            if(positionExists(i+1,j)){
                board[i][j].numOfMinesTouching += board[i+1][j].hasMine;
            }
            /// down right
            if(positionExists(i+1,j+1)){
                board[i][j].numOfMinesTouching += board[i+1][j+1].hasMine;
            }
            /// down left
            if(positionExists(i+1,j-1)){
                board[i][j].numOfMinesTouching += board[i+1][j-1].hasMine;
            }
        }
    }
}
void fillBoard(Element board[][DIMENSION]){
    int j,i;
    for(i = 0 ; i < DIMENSION ; i++){
        for(j = 0 ; j < DIMENSION ; j++){
            board[i][j].isCovered = 1;
            board[i][j].hasMine = 0;
            board[i][j].numOfMinesTouching = 0;
            board[i][j].hasFlag = 0;
        }
    }
    setMines(board);
    setTouchingMinesNumbers(board);
}
void uncoverAllElements(Element board[][DIMENSION]){
    char i,j;
    for(i = 0 ; i < DIMENSION ; i++){
        for(j = 0 ; j < DIMENSION ; j++){
            board[i][j].isCovered  = 0;
        }
    }
}
void showBoard(Element board[][DIMENSION]){
    int cols,rows;
    for(rows = 0 ; rows < DIMENSION ; rows++){
        gotoxy_m(3*(DIMENSION)/2,(DIMENSION/4+rows));
        for(cols = 0 ; cols < DIMENSION ; cols++){
            if(rows == rowsPos && cols == colsPos){
                printf("* ");
            }else if(board[rows][cols].hasFlag == 1 && board[rows][cols].isCovered == 1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                printf("F ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
            }

            else if(board[rows][cols].isCovered == 1){
                printf("+ ");
            }
            else if(board[rows][cols].hasMine == 1 && board[rows][cols].isCovered == 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                printf("# ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
            }
            else if(board[rows][cols].isCovered == 0&& board[rows][cols].hasMine == 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
                printf("%d ",board[rows][cols].numOfMinesTouching);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
            }
        }
    }
}
int setCursorPosition(int pos){
    if(pos >= DIMENSION){
        pos = 0;
    }else if(pos <0){
        pos = DIMENSION -1;
    }
    return pos;
}
void setMines(Element board[][DIMENSION]){
    srand(time(NULL));
    int xPos,yPos,i = NUMBER_OF_MINES;
    while(i){
        xPos = rand() % DIMENSION;
        yPos = rand() % DIMENSION;
        if(board[xPos][yPos].hasMine == 0){
            board[xPos][yPos].hasMine = 1;
            i--;
        }
    }
}
void checkInSetPosition(Element board[][DIMENSION],int xPos,int yPos){
    if(coveredElementsLeft == 0 && playerLost == 0){
        playerWon = 1;
        time_t now = time(NULL);
        time_t diff = now - startingTime;
        newPlayer.timeScore = diff;
        draw_result();
    }
    if(board[xPos][yPos].isCovered == 1){
        openAllConnectedEmptyElementsRecursive(board,xPos,yPos,board[xPos][yPos].numOfMinesTouching > 0);
        draw_result();
    }
}
void draw_result(){
    gotoxy_m(10,20);
    if(playerLost == 1){
        uncoverAllElements(board);
        printf("Your soul is Mine.\n");
        showBoard(board);
        getch();
    }else if(playerWon == 1){
        printf("You Won, you beautiful son of a bitch.");
        getch();
    }
}
int openAllConnectedEmptyElementsRecursive(Element board[][DIMENSION],int row,int col,int lastOneWasTouchingAMine){
    if(board[row][col].isCovered == 0){
        return 0;
    }
    board[row][col].isCovered = 0;
    coveredElementsLeft--;
    if(board[row][col].hasMine){
        playerLost = 1;
        return 1;
    }
    else{
        if( board[row][col].numOfMinesTouching == 0){
            /// up
            if(positionExists(row-1,col) && board[row-1][col].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row-1,col,board[row][col].numOfMinesTouching > 0);
            }
            /// up right
            if(positionExists(row-1,col+1) && board[row-1][col+1].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row-1,col+1,board[row][col].numOfMinesTouching > 0);
            }
            /// up left
            if(positionExists(row-1,col-1) && board[row-1][col-1].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row-1,col-1,board[row][col].numOfMinesTouching > 0);
            }
            /// right
            if(positionExists(row,col+1) && board[row][col+1].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row,col+1,board[row][col].numOfMinesTouching > 0);
            }
            /// left
            if(positionExists(row,col-1) && board[row][col-1].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row,col-1,board[row][col].numOfMinesTouching > 0);
            }
            /// down right
            if(positionExists(row+1,col+1) && board[row+1][col+1].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row+1,col+1,board[row][col].numOfMinesTouching > 0);
            }
            /// down
            if(positionExists(row+1,col) && board[row+1][col].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row+1,col,board[row][col].numOfMinesTouching > 0);
            }
            /// down left
            if(positionExists(row+1,col-1) && board[row+1][col-1].hasMine == 0){
                openAllConnectedEmptyElementsRecursive(board,row+1,col-1,board[row][col].numOfMinesTouching > 0);
            }

        }
        return 0;
    }
}
