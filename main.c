#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "fonction/fonction.h"
#include <string.h>
#include "asset/asset.h"
#include "structures/structures.h"



int main(void) {

    // setup the list number for the next append
    int value_item_list = 0, backup_key, nav_choose; 
    
    // setup all variables for check the status of setup
    int app_create_status,  world_setup_statuts_1, world_setup_statuts_2,world_setup_statuts_3,world_setup_statuts_4 ; 

    // value for stay a live the app
    bool app_status = true; 
    
    // setup struct for the world and allocating memory for the pointers
    struct world *world_1 = malloc(sizeof(struct world)); 
    struct world *world_2 = malloc(sizeof(struct world));
    struct world *world_3 = malloc(sizeof(struct world));
    struct world *world_4 = malloc(sizeof(struct world));
    world_1->map = (struct map*)malloc(sizeof(struct map));
    world_2->map = (struct map*)malloc(sizeof(struct map));
    world_3->map = (struct map*)malloc(sizeof(struct map));
    world_4->map = (struct map*)malloc(sizeof(struct map));
    
    // setup wolrds struct
    struct worlds *Worlds = malloc(sizeof(struct worlds));

    // setup player structure 
    struct player *ptr_player =malloc(sizeof(struct player));
    ptr_player->Inventory = (struct inventory *)malloc(sizeof(struct inventory));

    // setup the app 
    app_create_status = builder_app(&backup_key); 

    // setup all wolrds information
    world_setup_statuts_1  = worlds_setup(world_1, "Foga", "-1------------", "-2----------", "-3----------", "-4----------", "-5----------", "------------" );
    world_setup_statuts_2  = worlds_setup(world_2, "Tira", "-1------------", "-2----------", "-3----------", "-4----------", "-5----------", "------------" );
    world_setup_statuts_3  = worlds_setup(world_3, "Eclusia", "-1------------", "-2----------", "-3----------", "-4----------", "-5----------", "------------" );
    world_setup_statuts_4  = worlds_setup(world_4, "Spectro", "-1------------", "-2----------", "-3----------", "-4----------", "-5----------", "------------" );

    // setup all wolrds in wolrds struct
    Worlds->World_1 = world_1;
    Worlds->World_2 = world_2;
    Worlds->World_3 = world_3;
    Worlds->World_4 = world_4;

    // free all dinamic memory allocate
    free(world_1);
    free(world_2);
    free(world_3);
    free(world_4);
    

    if (world_setup_statuts_1 != 0  || world_setup_statuts_2 != 0 || world_setup_statuts_3 != 0 || world_setup_statuts_4 != 0 ){ // chedck if atll world are setup correctly
        printf("\x1b[31m[ERROR]\x1b[0m\nEn : Wolrds content failled to setup \nFr : Une erreur est survenue lors du chargement des contenue des mondes\n\n any probleme\n un probleme ?  : https://github.com/loveonyou/IrWorld");
    }
    else if (app_create_status == 1){ // check if the app setup corectly

        printf("\x1b[31m[ERROR]\x1b[0m\nEn : Failed to setup IrWolrd Overlay & Police \nFr : Une erreur est arriver lors de la mise en place des overlay et de la police\n\n any probleme\n un probleme ?  : https://github.com/loveonyou/IrWorld");
        system("pause");
        return 1;
    }
    else if (app_create_status == 0){  // start of app 
        Start_menu(ptr_player->name); 
        while (app_status == true){
            nav_choose = nav_menu(); 
            if (nav_choose == 0){
                return 0;
            }
            else if(nav_choose == 1){
                
            }
        }
    }
}
