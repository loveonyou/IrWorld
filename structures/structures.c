#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
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
        char level_name[50][4];
        struct map *map;
        
};
/**
 * Struct of Inventory
 *
 * list structure armor : list for all armor player have in this inventory
 * 
 * list structure sword : list for all sword player have in this inventory
 * 
 * list strucuture magic_orb : list for all magic_orb player have in this inventory
 * 
 * list structure heal : list for all heal player have in this inventory
 * 
*/
struct inventory{
       struct armor *armors[15];
       struct sword *sword[15];
       struct magic_orb *magic_orb[15];
       struct heal *heal[30];
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
 * string line_1 -> _20 : the line for the map 
 * 
 */
struct map{

    char line[20][1000];
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
/**
 * Struct of Armor
 *
 * int id : id of the armor
 * 
 * char name : name of the armor
 * 
 * int hp_boost : number of hp the armor boost 
 * 
 * int attack_boost : number of armor up the damage
 * 
*/
struct armor{   
    int id; 
    char name[10];
    int hp_boost;  
    int attack_boost; 
};
/**
 * Struct of sword
 *
 * int id : id of the sword
 * 
 * char name : name of the sword
 * 
 * int damage : damage of the sword
 * 
*/
struct sword{
    int id;
    char name[15];
    int damage; 
};
/**
 * Struct of Magic Orb
 *
 * int id : id of the orb
 * 
 * char name : name of the orb
 * 
 * int damage_boost : damage of the orb boost the magic attack
 * 
*/
struct magic_orb{
    int id;
    char name[15]; 
    char type_magic[10]; 
    int damage_boost;
};
/**
 * Struct of Heal
 *
 * int id : id of the Heal
 * 
 * char name : name of the heal
 * 
 * int hp_recharge : hp the heal recharge
 * 
*/
struct heal{
    int id; 
    char name[15];
    int hp_recharge;
};
