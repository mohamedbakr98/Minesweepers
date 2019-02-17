#include "player.h"

void playerConstructor(Player *newPlayer){
    char buffer[20];
    buffer[0] = '\0';
    char firstTime = 1;
    while(buffer[0] == '\0'){
        printf("Enter your Name: \n");
        if(!firstTime){
           printf("Please enter a valid name.\n");
        }
        firstTime = 0;
        GetName(buffer);
    }
    strcpy((*newPlayer).playerName,buffer);
}
/// first I want to check if a file exists
    /// if it exists then we want to open in 'a' mode
    /// if not we want to open in 'w' mode
int fileExists(char *file){
    WIN32_FIND_DATA FindFileData;
    HANDLE handle = FindFirstFile(file,&FindFileData);
    if(handle != INVALID_HANDLE_VALUE){
        FindClose(handle);
        return 1;
    }
    return 0;
}
int savePlayerToFile(Player p){
    FILE *database;
    if(fileExists("database.txt")){
        database = fopen("database.txt","a");
    }else{
        database = fopen("database.txt","w");
    }
    fprintf(database,"Player's Name: %s\n",p.playerName);
    fprintf(database,"Player's time: %d\n",p.timeScore);
    fprintf(database,"------\n");
}
int takePlayersDataInSaveToFile(){
    system("cls");
    playerConstructor(&newPlayer);
    savePlayerToFile(newPlayer);
}
