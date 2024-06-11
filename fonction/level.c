#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

/**
 * Calculate the level of the player
 * 
 * @param xp xp total of the playe
 * 
 * return the level of the player
*/
int level_of_player(int xp){
    int level ;

    level = xp /15;

    return level;
}