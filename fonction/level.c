#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int level_of_player(int xp){
    int level ;

    level = xp /15;

    return level;
}