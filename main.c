#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "fonction/fonction.h"
#include <string.h>
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

    // setup player structure 
    struct player *ptr_player =malloc(sizeof(struct player));
    ptr_player->Inventory = (struct inventory *)malloc(sizeof(struct inventory));
    ptr_player->xp_total = 25;
    ptr_player->level = level_of_player(ptr_player->xp_total);

    // setup inventory 


    // setup the app 
    app_create_status = builder_app(&backup_key); 

    //setup the sword 
    // part 1 : declare a variable and create the place in memory
    struct sword *sword_1 =malloc(sizeof(struct sword));
    struct sword *sword_2 =malloc(sizeof(struct sword));
    struct sword *sword_3 =malloc(sizeof(struct sword));
    struct sword *sword_4 =malloc(sizeof(struct sword));
    struct sword *sword_5 =malloc(sizeof(struct sword));

    // part 2 : fill in the variables

    sword_setup(sword_1, 011, "cassé",  1, 15 );
    sword_setup(sword_2, 012, "d'excalibur",  2, 25 );
    sword_setup(sword_3, 013, "katana",  3, 45 );
    sword_setup(sword_4, 014, "Nichirin",  4, 65 );
    sword_setup(sword_5, 015, "de la gloire",  5, 100);

    //setup the armor 
    // part 1 : declare a variable and create the place in memory
    struct armor *armor_1 =malloc(sizeof(struct armor));
    struct armor *armor_2 =malloc(sizeof(struct armor));
    struct armor *armor_3 =malloc(sizeof(struct armor));
    struct armor *armor_4 =malloc(sizeof(struct armor));
    struct armor *armor_5 =malloc(sizeof(struct armor));

    // part 2 : fill in the variables

    armor_setup(armor_1, 021, "en cuivre", 1, 15, 15);
    armor_setup(armor_2, 022, "en fer", 2, 30, 30);
    armor_setup(armor_3, 023, "L'ō-yoroi", 3, 50, 50);
    armor_setup(armor_4, 024, "fléau", 4, 75, 75);
    armor_setup(armor_5, 025, "de la gloire", 5, 150, 150);



    //setup the magic_orb
    // part 1 : declare a variable and create the place in memory
    struct magic_orb *magic_orb_1 = malloc(sizeof(struct magic_orb));
    struct magic_orb *magic_orb_2 = malloc(sizeof(struct magic_orb));
    struct magic_orb *magic_orb_3 = malloc(sizeof(struct magic_orb));
    struct magic_orb *magic_orb_4 = malloc(sizeof(struct magic_orb));
    struct magic_orb *magic_orb_5 = malloc(sizeof(struct magic_orb));

    // part 2 : fill in the variables
    magic_orb_setup(magic_orb_1, 0311, "feu", 1, "feu", 50 );
    magic_orb_setup(magic_orb_2, 0312, "terre", 1, "terre", 50 );
    magic_orb_setup(magic_orb_3, 0313, "eau", 1, "eau", 50 );
    magic_orb_setup(magic_orb_4, 0314, "spectre", 1, "spectre", 50 );
    magic_orb_setup(magic_orb_4, 0321, "universel", 2, "universel", 100 );

    

    //setup the heal
    // part 1 : declare a variable and create the place in memory
    struct heal *heal_1 = malloc(sizeof(struct heal));
    struct heal *heal_2 = malloc(sizeof(struct heal));
    struct heal *heal_3 = malloc(sizeof(struct heal));
    struct heal *heal_4 = malloc(sizeof(struct heal));
    struct heal *heal_5 = malloc(sizeof(struct heal));

    // part 2 : fill in the variables
    heal_setup(heal_1, 041, "pomme", 1, 20 );
    heal_setup(heal_2, 042, "feu de vie", 2, 40 );
    heal_setup(heal_3, 043, "bandage", 3, 60 );
    heal_setup(heal_4, 044, "kit de soin", 4, 100 );
    heal_setup(heal_4, 044, "coeur de cristal", 4, 100 );
    
    //setup the attack
    // part 1 : declare a variable and create the place in memory
    struct attack *attack_1  = malloc(sizeof(struct attack));
    struct attack *attack_2  = malloc(sizeof(struct attack));
    struct attack *attack_3  = malloc(sizeof(struct attack));
    struct attack *attack_4  = malloc(sizeof(struct attack));
    struct attack *attack_5  = malloc(sizeof(struct attack));
    struct attack *attack_6  = malloc(sizeof(struct attack));
    struct attack *attack_7  = malloc(sizeof(struct attack));
    struct attack *attack_8  = malloc(sizeof(struct attack));
    struct attack *attack_9  = malloc(sizeof(struct attack));
    struct attack *attack_10 = malloc(sizeof(struct attack));
    struct attack *attack_11 = malloc(sizeof(struct attack));
    struct attack *attack_12 = malloc(sizeof(struct attack));
    struct attack *attack_13 = malloc(sizeof(struct attack));
    struct attack *attack_14 = malloc(sizeof(struct attack));
    struct attack *attack_15 = malloc(sizeof(struct attack));

    // part 2 : fill in the variables
    

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

    printf("\033[31mVeuillez mettre votre terminal en plein ecran pour le déroulement du jeux ! \033[37m\n");
    system("pause");
    fight_main(ptr_player);
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
        Start_menu(ptr_player->name); 
        while (app_status == true){
            system("CLS");
            nav_choose = nav_menu(); 
            if (nav_choose == 0){
                break;
            }
            else if(nav_choose == 1){ // start history
                wolrd_choose = choose_world();
                if (wolrd_choose == 1){
                    world_1(ptr_player, Worlds);
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
                printf("%i",ptr_player->level);
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

