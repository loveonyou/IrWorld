#ifndef STRUCT_H
#define STRUCT_H
#include <stdbool.h>
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
        bool level_status[5];
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
       struct attack *attack[16];
    };
/**
 * Struct of Inventory
 *
 * int xp_total : total of xp have player
 * 
 * int level : level of the player
 * 
 * char name[100] : name of player
 * 
 * struct inventory *Inventory  : reference to inventory structure
 * 
 * int hp : hp of player
 * 
 * int id_armor : id of armor the player equipe
 * 
 * int id_sword : id ofsword the player equipe
 * 
 * int id_magic_orb : id of magic orb the player equipe
*/
struct player
{
    int xp_total;
    int level;
    char name[100];
    struct inventory *Inventory;
    int hp;
    int damage_sword;
    int id_armor;
    int id_sword;
    int id_magic_orb;
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
 * int tier : tier of the armor
 * 
 * int hp_boost : number of hp the armor boost 
 * 
 * int attack_boost : number of armor up the damage
 * 
*/
struct armor{   
    int id; 
    char name[10];
    int tier;
    int hp_boost;  
    int attack_boost; 
    bool equipped;
    bool unlock ;
};
/**
 * Struct of sword
 *
 * int id : id of the sword
 * 
 * char name : name of the sword
 * 
 * int tier : tier of the sword
 * 
 * int damage : damage of the sword
 * 
 * bool equipped : boolean for check if the magic_orb is equipped
 * 
*/
struct sword{
    int id;
    char name[15];
    int tier;
    int damage; 
    bool equipped;
    bool unlock ;
};
/**
 * Struct of Magic Orb
 *
 * int id : id of the orb
 * 
 * char name : name of the orb
 * 
 * char type : type of magic
 * 
 * int tier : tier of the magic_orb
 * 
 * int damage_boost : damage of the orb boost the magic attack
 * 
 * bool equipped : boolean for check if the magic_orb is equipped
 * 
*/
struct magic_orb{
    int id;
    char name[15]; 
    char type[10]; 
    int tier;
    int damage_boost;
    bool equipped;
    bool unlock ;
};
/**
 * Struct of Heal
 *
 * int id : id of the Heal
 * 
 * char name : name of the heal
 * 
 * int tier : tier 
 * 
 * int hp_recharge : hp the heal recharge
 * 
 * 
*/
struct heal{
    int id; 
    char name[20];
    int tier;
    int hp_recharge;
    int quantity;
    
};
/**
 * Struct of master
 *
 * int id : id of the master
 * 
 * char name : name of the master
 * 
 * int hp : hp of the master
 * 
 * int damage_min
 *                  -> slice of damage can inflict the master
 * int damage_max
 * 
 * int xp_win_min
 *                  -> slice of the player can win
 * int xp_win_max
 
*/
struct mob {
    int id;
    char name[30];
    int hp;
    int damage_min;
    int damage_max;
    int xp_win_min;
    int xp_win_max;
};

struct attack{
    int id ;
    char name[50];
    int tier;
    int type;
    int damage;
    bool equipped;
    bool unlock ;
};
#endif 