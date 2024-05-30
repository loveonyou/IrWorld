#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "../asset/asset.h"
#include "../structures/structures.h"

/**
 * build asset and overlay for the app
 *  
 * @param ptr_backup_key : pointer to backup key to restore save
 * 
 * @return 1 or 0 , corresponding if the asset setup correctly, 1 : error, 0 : success
 */
int builder_app(int *ptr_backup_key){
    create_save_key(ptr_backup_key);
    int check_police = system("chcp 65001");
    int check_title = system("title \" IrWorld | Creation du Compte \" ");
    system("CLS");

    if (check_police == 0 && check_title == 0){
        return  0;   
    }
    else{
        return 1;
    }
    return 0;
}       
/**
 * build asset and overlay for the app
 *
 * @param world_builder : pointer to world, form struct wolrd
 * 
 * @param world_name : name of the world
 * 
 * @param line_1->6 : line of the world map , which goes from line_1 to line_20
 * 
 * @return 1 if the wolrds setup correctly
 */
int worlds_setup(struct world *world_builder, char world_name[], char Line_1[], char Line_2[], char Line_3[], char Line_4[], char Line_5[], char Line_6[], char Line_7[], char Line_8[], char Line_9[], char Line_10[],  char Line_11[], char Line_12[], char Line_13[], char Line_14[],char Line_15[],  char Line_16[], char Line_17[], char Line_18[], char Line_19[], char Line_20[]){

    world_builder->acces = false;
    strcpy(world_builder->name, world_name);
    for (int i = 0 ; i <= 5; i++){
        world_builder->level_status[i] = false;    
    }


    strcpy(world_builder->map->line[0] , Line_1 );
    strcpy(world_builder->map->line[1] , Line_2 );
    strcpy(world_builder->map->line[2] , Line_3 );
    strcpy(world_builder->map->line[3] , Line_4 );
    strcpy(world_builder->map->line[4] , Line_5 );
    strcpy(world_builder->map->line[5] , Line_6 );
    strcpy(world_builder->map->line[6] , Line_7 );
    strcpy(world_builder->map->line[7] , Line_8 );
    strcpy(world_builder->map->line[8] , Line_9 );
    strcpy(world_builder->map->line[9] , Line_10);
    strcpy(world_builder->map->line[10] , Line_11);
    strcpy(world_builder->map->line[11] , Line_12);
    strcpy(world_builder->map->line[12] , Line_13 );
    strcpy(world_builder->map->line[13] , Line_14);
    strcpy(world_builder->map->line[14] , Line_15);
    strcpy(world_builder->map->line[15] , Line_16);
    strcpy(world_builder->map->line[16] , Line_17);
    strcpy(world_builder->map->line[17] , Line_18);
    strcpy(world_builder->map->line[18] , Line_19);
    strcpy(world_builder->map->line[19] , Line_20 );

    return 0;
    
}
/**
 * setup the variables for the sword
 *
 * @param sword_builder : reference to an sword for building it
 * 
 * @param id : id of the sword
 * 
 * @param sword_name : name of the sword
 * 
 * @param tier : tier of the sword
 * 
 * @param damage : damage of the sword
 
*/
int sword_setup(struct sword *sword_builder,int id, char sword_name[],int tier, int damage   ){
    sword_builder->id = id;
    strcpy(sword_builder->name, sword_name);
    sword_builder->tier = tier;
    sword_builder->damage = damage;
    sword_builder->equipped = false;
    sword_builder->unlock = false ;

}
/**
 * setup the variables for the armor
 *
 * @param armor_builder : reference to an armor for building it
 * 
 * @param id : id of the armor
 * 
 * @param armor_name : name of the armor
 * 
 * @param hp_boost : hp the armor boost the live of player
 * 
 * @param tier : tier of the armor
 * 
 * @param attack_boost : attack boost of the armor
 
*/
int armor_setup(struct armor *armor_builder, int id, char armor_name[], int tier, int hp_boost, int attack_boost){
    armor_builder->id = id;
    strcpy(armor_builder->name, armor_name);
    armor_builder->hp_boost = hp_boost;
    armor_builder->tier = tier;
    armor_builder->attack_boost = attack_boost;
    armor_builder->equipped = false;
    armor_builder->unlock = false;
  
}

int magic_orb_setup(struct magic_orb *orb_builder, int id, char magic_orb_name[],  int tier, char type_magic[], int damage_boost){
    orb_builder->id = id;
    strcpy(orb_builder->name, magic_orb_name);
    strcpy(orb_builder->type, type_magic);
    orb_builder->tier = tier;
    orb_builder->damage_boost = damage_boost;
    orb_builder->equipped = false;


}

int heal_setup(struct heal *heal_builder, int id ,char heal_name[],int tier, int hp_recharge){
    heal_builder->id = id;
    strcpy(heal_builder->name, heal_name);
    heal_builder->tier = tier;
    heal_builder->hp_recharge = hp_recharge;
    heal_builder->quantity = 0;


}

int attack_setup(struct attack *attack_builder, int id ,char attack_name[],int tier, int type, int damage){
    attack_builder->id = id;
    strcpy(attack_builder->name, attack_name);
    attack_builder->tier = tier;
    attack_builder->type = type;
    attack_builder->damage = damage;
    attack_builder->equipped = false;
    attack_builder->unlock = false;
}

int mob_setup(struct mob *mob_builder ,char name[], int hp , int damage_min, int damage_max, int xp_win_min, int xp_win_max){
    strcpy(mob_builder->name, name);
    mob_builder->hp = hp;
    mob_builder->damage_min = damage_min;
    mob_builder->damage_max = damage_max;
    mob_builder->xp_win_min = xp_win_min;
    mob_builder->xp_win_max = xp_win_max;
}
