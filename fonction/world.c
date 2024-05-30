#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "../asset/asset.h"
#include "../structures/structures.h"
/**
 * Wolrd one
 * 
 * @param ptr_pseudo : pointer to pseudo of player 
 * 
*/
void world_1(struct player *player, struct worlds *worlds){

    printf("  ____      _      ____    _____   _____ \n");
    printf(" / ___|    / \\    |  _ \\  |_   _| | ____| \n");
    printf("| |       / _ \\   | |_) |   | |   |  _|  \n");
    printf("| |___   / ___ \\  |  _ <    | |   | |___ \n");
    printf(" \\____| /_/   \\_\\ |_| \\_\\   |_|   |_____|\n\n");
                                        
    

    printf("\n Salut, %s.\n Je te shouaite la bienvenue dans le monde de Foga.\n", player->name);
    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    printf("║[1] : %s                       ║\n", worlds->World_1->level_name[1]);
    printf("║[2] : %s                       ║\n", worlds->World_1->level_name[2]);
    printf("║[3] : %s                       ║\n", worlds->World_1->level_name[3]);
    printf("║[4] : %s                       ║\n", worlds->World_1->level_name[4]);
    printf("║[5] : %s                       ║\n", worlds->World_1->level_name[4]);
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
    system("pause");

    
}