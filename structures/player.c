#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/**
 * Struct of Inventory
 *
 * list char itemname[1000][100] : list of inventory items name
 * 
 * list int item_id[1000] : list of inventory items id
 * 
*/
struct inventory{
        char item_name[1000][100];
        int item_id[1000];
    };
/**
 * Struct of Inventory
 *
 * int xp_total : total of xp have player
 * 
 * char name[100] : name of player
 * 
 * struct inventory *Inventory  : reference to inventory structure
*/
struct player
{
    int xp_total;
    char name[100];
    struct inventory *Inventory;

};

