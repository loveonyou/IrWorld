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
int worlds_setup(struct world *world_builder, char world_name[], char Line_1[], char Line_2[], char Line_3[], char Line_4[], char Line_5[], char Line_6[]){

    world_builder->acces = false;
    strcpy(world_builder->name, world_name);
    for (int i = 0 ; i <= 4; i++){
        world_builder->level_status[i] = false;    
    }
    strcpy(world_builder->map->line_1 , Line_1 );
    strcpy(world_builder->map->line_2 , Line_2 );
    strcpy(world_builder->map->line_3 , Line_3 );
    strcpy(world_builder->map->line_4 , Line_4 );
    strcpy(world_builder->map->line_5 , Line_5 );
    strcpy(world_builder->map->line_6 , Line_6 );

    return 0;
    
};
