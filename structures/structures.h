#ifndef STRUCT_H
#define STRUCT_H
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
struct world{
        bool acces;
        char name[10];
        bool level_status[4];
        struct map *map;
        
};
struct inventory{
        char item_name[1000][100];
        int item_id[1000];
    };
struct player
{
    int xp_total;
    char name[100];
    struct inventory *Inventory;

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
/**
 * Struct of map 
 *
 * string line_1 -> _6 : the line for the map 
 * 
 */
struct map{

    char line_1[1000];
    char line_2[1000];
    char line_3[1000];
    char line_4[1000];
    char line_5[1000];
    char line_6[1000];
};
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
#endif 