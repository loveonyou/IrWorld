#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/**
 * Struct of level 
 *
 * int xp_win : xp can win at the end of level
 * 
 * string level_name : name of level
 */
struct level{
    int xp_win;
    char level_name[50];
    
};

/**
 * Struct of map 
 *
 * string ligne_1 -> _6 : the line for the map 
 * 
 */
struct map{

    char ligne_1[1000];
    char ligne_2[1000];
    char ligne_3[1000];
    char ligne_4[1000];
    char ligne_5[1000];
    char ligne_6[1000];
}
/**
 * Struct of world 
 *
 * bool acces : for check if the palyer have accces to the world
 * 
 * string name : name of the world
 * 
 * list[6] bool levelcompleted : check if level is completed or not
 * 
 * struct map *map : pointeur ref to map .   
 */
struct world
    {
        bool acces;
        char name[10];
        bool level_status[5];
        struct map *map;
        
};

/**
 * Struct of all Worlds
 *
 * struct world *Wolrd_1 -> _5 : pointeur ref to world
 * 
*/
struct worlds{

    struct world *World_1;
    struct world *World_2;
    struct world *World_3;
    struct world *World_4;
    struct world *World_5;
};