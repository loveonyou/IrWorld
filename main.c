#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "fonction/fonction.h"
#include "asset/asset.h"
#include "structures/structures.h"




int main(void){
    
    // setup the list number for the next append
    int value_item_list = 0;

    // variables for the backup-key 
    int backup_key;
    
    // variables for the navigation in navigation, world, level 
    int nav_choose, wolrd_choose; 
    
    // setup all variables for check the status of setup
    int app_create_status,  world_setup_statuts_1, world_setup_statuts_2,world_setup_statuts_3,world_setup_statuts_4 ; 

    // value for stay a live the app
    bool app_status = true; 

    // setup seed for rand
    srand(time(NULL));

    // setup struct for the world and allocating memory for the pointers
    struct world *world_1_temp = malloc(sizeof(struct world)); 
    struct world *world_2_temp  = malloc(sizeof(struct world));
    struct world *world_3_temp  = malloc(sizeof(struct world));
    struct world *world_4_temp  = malloc(sizeof(struct world));
    world_1_temp->map = (struct map*)malloc(sizeof(struct map));
    world_2_temp->map = (struct map*)malloc(sizeof(struct map));
    world_3_temp->map = (struct map*)malloc(sizeof(struct map));
    world_4_temp->map = (struct map*)malloc(sizeof(struct map));

    // setup wolrds struct
    struct worlds *Worlds = malloc(sizeof(struct worlds));
    Worlds->World_1 = malloc(sizeof(struct world));
    Worlds->World_2 = malloc(sizeof(struct world));
    Worlds->World_3 = malloc(sizeof(struct world));
    Worlds->World_4 = malloc(sizeof(struct world));

    

    // setup mob 
    struct mob *mob_1 = malloc(sizeof(struct mob));
    struct mob *mob_2 = malloc(sizeof(struct mob));
    struct mob *mob_3 = malloc(sizeof(struct mob));
    struct mob *mob_4 = malloc(sizeof(struct mob));

    mob_setup(mob_1, "Maitre de Foga", 500, 30, 60, 3,5);
    mob_setup(mob_2, "Maitre de Tira", 600, 60, 80, 3,5);
    mob_setup(mob_3, "Maitre de Eclusia", 700, 90, 120, 3,5);
    mob_setup(mob_4, "Maitre de Spectro", 1000, 150, 299, 3,5);


    // setup player structure 
    struct player *ptr_player =malloc(sizeof(struct player));
    ptr_player->Inventory = (struct inventory *)malloc(sizeof(struct inventory));
    ptr_player->xp_total = 0;
    ptr_player->level = level_of_player(ptr_player->xp_total);
    ptr_player->hp = 150;

    // setup inventory 
    int i;
    for (i = 0; i < 15; i++){
        ptr_player->Inventory->armors[i] = malloc(sizeof(struct armor));
    }
    for (i = 0; i < 15; i++){
        ptr_player->Inventory->sword[i] = malloc(sizeof(struct sword));
    }
    for (i = 0; i < 15; i++){
        ptr_player->Inventory->magic_orb[i] = malloc(sizeof(struct magic_orb));
    }
    for (i = 0; i < 30; i++){
        ptr_player->Inventory->heal[i] = malloc(sizeof(struct heal));
    }
    for (i = 0; i < 16; i++){
        ptr_player->Inventory->attack[i] = malloc(sizeof(struct attack));
    }

    // setup the app 
    app_create_status = builder_app(&backup_key); 

    //setup the sword 

    sword_setup(ptr_player->Inventory->sword[1], 011, "cassé",  1, 15 );
    sword_setup(ptr_player->Inventory->sword[2], 012, "d'excalibur",  2, 25 );
    sword_setup(ptr_player->Inventory->sword[3], 013, "katana",  3, 45 );
    sword_setup(ptr_player->Inventory->sword[4], 014, "Nichirin",  4, 65 );
    sword_setup(ptr_player->Inventory->sword[5], 015, "de la gloire",  5, 100);


    
    //setup the armor 

    armor_setup(ptr_player->Inventory->armors[1], 021, "en cuivre", 1, 15, 15);
    armor_setup(ptr_player->Inventory->armors[2], 022, "en fer", 2, 30, 30);
    armor_setup(ptr_player->Inventory->armors[3], 023, "L'ō-yoroi", 3, 50, 50);
    armor_setup(ptr_player->Inventory->armors[4], 024, "fléau", 4, 75, 75);
    armor_setup(ptr_player->Inventory->armors[5], 025, "de la gloire", 5, 150, 150);

    //setup the magic_orb

    magic_orb_setup(ptr_player->Inventory->magic_orb[1], 0311, "feu", 1, "feu", 50 );
    magic_orb_setup(ptr_player->Inventory->magic_orb[2], 0312, "terre", 1, "terre", 50 );
    magic_orb_setup(ptr_player->Inventory->magic_orb[3], 0313, "eau", 1, "eau", 50 );
    magic_orb_setup(ptr_player->Inventory->magic_orb[4], 0314, "spectre", 1, "spectre", 50 );
    magic_orb_setup(ptr_player->Inventory->magic_orb[5], 0321, "universel", 2, "universel", 100 );

    

    //setup the heal

    heal_setup(ptr_player->Inventory->heal[1], 041, "pomme", 1, 20 );
    heal_setup(ptr_player->Inventory->heal[2], 042, "feu de vie", 2, 40 );
    heal_setup(ptr_player->Inventory->heal[3], 043, "bandage", 3, 60 );
    heal_setup(ptr_player->Inventory->heal[4], 044, "kit de soin", 4, 100 );
    heal_setup(ptr_player->Inventory->heal[5], 044, "coeur de cristal", 4, 100 );
    
    //setup the attack

    attack_setup(ptr_player->Inventory->attack[1], 0511, "punch", 1, 1, 25 );
    attack_setup(ptr_player->Inventory->attack[2], 0521, "sword stroke", 2, 1, 35 );
    attack_setup(ptr_player->Inventory->attack[3], 0531, "Sword-Dash", 3, 1, 50);
    attack_setup(ptr_player->Inventory->attack[4], 0512, "Aqua-dash", 1, 2, 30);
    attack_setup(ptr_player->Inventory->attack[5], 0522, "waterfall", 2, 2, 45);
    attack_setup(ptr_player->Inventory->attack[6], 0532, "SuperWawe", 3, 2, 65);
    attack_setup(ptr_player->Inventory->attack[7], 0513, "earthquake", 1, 3, 30);
    attack_setup(ptr_player->Inventory->attack[8], 0523, "earth ball", 2, 3, 45);
    attack_setup(ptr_player->Inventory->attack[9], 0533, "rockfall", 3, 3, 60);
    attack_setup(ptr_player->Inventory->attack[10], 0514, "katon", 1, 4, 30);
    attack_setup(ptr_player->Inventory->attack[11], 0524, "fireball", 2, 4, 45);
    attack_setup(ptr_player->Inventory->attack[12], 0534, "firewall", 3, 4, 60);
    attack_setup(ptr_player->Inventory->attack[13], 0515, "shadow handling", 1, 5, 30);
    attack_setup(ptr_player->Inventory->attack[14], 0525, "extension of the territory", 2, 5, 45);
    attack_setup(ptr_player->Inventory->attack[15], 0535, "world of shadows", 3, 5, 60);


    // setup all wolrds information
    world_setup_statuts_1  = worlds_setup(world_1_temp, "Foga", 
    "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗", 
    "║     ▒▒▒▒▒▒▒▒      ▒▒▒▒▒▒▒▒                                               _   |~  _      ║", 
    "║    ▒▐▒▐▒▒▒▒▌▒    ▒▒▌▒▒▐▒▒▌▒                                             [_]--'--[_]     ║", 
    "║     ▒▀▄█▒▄▀▒      ▒▀▄▒▌▄▀▒                             x                |'|''`''|'|     ║", 
    "║        ██            ██                     .-. _______|                | | /^\\ | |     ║",
    "║      ▄▄██▄    [1]   ▄██▄                    |=|/     /  \\               |_|_|5|_|_|     ║", 
    "║                ║                            | |_____|_''_|                   ║          ║", 
    "║                ╚═════════════════════════╗  |_|_[2]_|____|                   ║          ║", 
    "║                                     +    ║════════════════════════════════════╗         ║", 
    "║                                    / \\                                        ║         ║", 
    "║  _____         ____     __________/ o \\/\\_________      _________             ║         ║", 
    "║ |o o o|_______|    |___|   SHOP        | | # # #  |____|o o o o  | /\\         ║         ║", 
    "║ |o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |//\\\\        ║         ║", 
    "║ |o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |((|))       ║         ║", 
    "║ |o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |((|))       ║         ║", 
    "║ |_[]__|__[]___|_||_|__<|____________[0]|_|___/\\___|_.|_|____[]___|  |[3]      ║         ║", 
    "║  [4]                                                                  ║       ║         ║", 
    "║   ════════════════════════════════════════════════════════════════════════════          ║", 
    "║                                                                                         ║", 
    "╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝" );
    world_setup_statuts_2  = worlds_setup(world_2_temp, "Tira", 
    "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║",
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝" );
    world_setup_statuts_3  = worlds_setup(world_3_temp, "Eclusia", 
    "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║",
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝" );
    world_setup_statuts_4  = worlds_setup(world_4_temp, "Spectro", 
    "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║",
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "║                                                                                         ║", 
    "╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝" );
        
    
    // setup all wolrds in wolrds struct
    Worlds->World_1 = world_1_temp;
    Worlds->World_2 = world_2_temp;
    Worlds->World_3 = world_3_temp;
    Worlds->World_4 = world_4_temp;

    

    // free all dinamic memory allocate
    free(world_1_temp);
    free(world_2_temp);
    free(world_3_temp);
    free(world_4_temp);
    
    // default item for player
    ptr_player->Inventory->attack[1]->equipped = true;
    ptr_player->Inventory->attack[2]->equipped = true;
    ptr_player->Inventory->attack[3]->equipped = true;
    ptr_player->Inventory->heal[1]->quantity = 15;
    Worlds->World_1->acces = true;
    Worlds->World_1->level_status[1] = true;


    printf("\033[31mVeuillez mettre votre terminal en plein ecran pour le déroulement du jeux ! \033[37m\n");
    system("pause");


    
    if (world_setup_statuts_1 != 0  || world_setup_statuts_2 != 0 || world_setup_statuts_3 != 0 || world_setup_statuts_4 != 0 ){ // chedck if atll world are setup correctly
        printf("\x1b[31m[ERROR]\x1b[0m\nEn : Wolrds content failled to setup \nFr : Une erreur est survenue lors du chargement des contenue des mondes\n\n any probleme\n un probleme ?  : https://github.com/loveonyou/IrWorld");
        system("pause");
        return 1;
    }
    else if (app_create_status == 1){ // check if the app setup corectly

        printf("\x1b[31m[ERROR]\x1b[0m\nEn : Failed to setup IrWolrd Overlay & Police \nFr : Une erreur est arriver lors de la mise en place des overlay et de la police\n\n any probleme\n un probleme ?  : https://github.com/loveonyou/IrWorld");
        system("pause");
        return 1;
    }
    else if (app_create_status == 0){  // start of app 

        system("cls");
        Start_menu(ptr_player->name); 

        while (app_status == true){

            system("CLS");
            nav_choose = nav_menu(); 

            if (nav_choose == 0){

                break;

            }
            else if(nav_choose == 1){ // start history
                wolrd_choose = choose_world();

                system("CLS");

                if (wolrd_choose == 1){

                    if(Worlds->World_1->acces == true){

                        world_1(ptr_player, Worlds);

                    }
                }
            }
            else if (nav_choose == 2){ // show profile of player
                system("cls");
                printf("  ____                    __   _   _        \n");
                printf(" |  _ \\   _ __    ___    / _| (_) | |   ___ \n");
                printf(" | |_) | | '__|  / _ \\  | |_  | | | |  / _ \\ \n");
                printf(" |  __/  | |    | (_) | |  _| | | | | |  __/ \n");
                printf(" |_|     |_|     \\___/  |_|   |_| |_|  \\___|\n");
                printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                printf("║pseudo :                       ║\n");
                printf("║level :                        ║\n");
                printf("║Xp total win :                 ║\n");
                printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                printf("\033[%d;%dH",7, 11);
                printf("%s", ptr_player->name);
                printf("\033[%d;%dH",8, 10);
                printf("%i",level_of_player(ptr_player->xp_total));
                printf("\033[%d;%dH",9, 18  );
                printf("%i",ptr_player->xp_total);
                printf("\033[%d;%dH",11, 1  );
                system("pause");
                continue;
            }
            else if (nav_choose == 3){ // load and save

                printf("chargée une sauvagarde [no available]\n");
                system("pause");
                
            }
            else if (nav_choose == 4){ // show backup key

                    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                    printf("║           Backup-Key          ║\n");
                    printf("║              %i              ║\n", backup_key);
                    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                    system("pause");
            }
            else if (nav_choose == 10){ // show rules

                printf("Régles [no available]");
                system("pause");
            }
        }
    }
     
}

