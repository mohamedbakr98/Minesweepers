#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
typedef struct player{
    time_t timeScore;
    char playerName[20];
}Player;
Player newPlayer;
void playerConstructor(Player *newPlayer);
int savePlayerToFile(Player p);
int fileExists(char *path);
int takePlayersDataInSaveToFile();

#endif // PLAYER_H_INCLUDED
