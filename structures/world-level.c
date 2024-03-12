#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


struct level{
    int xp_win;
    char level_name[50];
    
};


struct map{

    char ligne_1[1000];
    char ligne_2[1000];
    char ligne_3[1000];
    char ligne_4[1000];
    char ligne_5[1000];
    char ligne_6[1000];
}
struct world
    {
        bool acces;
        char name[10];
        int levelcompleted[6];
        struct map *map;
        
};
struct worlds{

    struct world *World_1;
    struct world *World_2;
    struct world *World_3;
    struct world *World_4;
    struct world *World_5;
};