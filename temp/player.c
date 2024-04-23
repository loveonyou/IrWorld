#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
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
/**
 * Struct of Inventory
 *
 * int xp_total : total of xp have player
 * 
 * char name[100] : name of player
 * 
 * struct inventory *Inventory  : reference to inventory structure
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
    char name[100];
    struct inventory *Inventory;
    int hp_total;
    int damage_sword;
    int id_armor;
    int id_sword;
    int id_magic_orb;
};

