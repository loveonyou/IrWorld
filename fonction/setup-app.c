#include<stdlib.h>
#include <stdio.h>
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
int builder_app(int *ptr_backup_key ){
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
}
/**
 * build asset and overlay for the app
 *
 * @param world_builder : pointer to world, form struct wolrd
 * 
 * @param world_name : name of the world
 * 
 * @param line_1->6 : line of the world map , which goes from line_1 to line_6
 * 
 * @return 1 if the wolrds setup correctly
 */
int worlds_setup(struct world *world_builder, char world_name[], char Line_1[], char Line_2[], char Line_3[], char Line_4[], char Line_5[], char Line_6[], char Line_7[], char Line_8[], char Line_9[], char Line_10[],  char Line_11[], char Line_12[], char Line_13[], char Line_14[],char Line_15[],  char Line_16[], char Line_17[], char Line_18[], char Line_19[], char Line_20[]){

    world_builder->acces = false;
    strcpy(world_builder->name, world_name);
    for (int i = 0 ; i <= 4; i++){
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
    strcpy(world_builder->map->line [19] , Line_20 );

    return 0;
    
};

int sword_setup(struct sword *sword_builder,int id, char sword_name[],int tier, int damage   ){};

int armor_setup(struct sword *sword_builder, int id, char sword_name[], int hp_boost, int tier, int attack_boost){};

int magic_orb_setup(struct magic_orb *orb_builder, int id, char magic_orb_name[], char type_magic[], int tier, int damage_boost){};


