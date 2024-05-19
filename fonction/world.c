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
    int i =0;
    printf("  ____      _      ____    _____   _____ \n");
    printf(" / ___|    / \\    |  _ \\  |_   _| | ____| \n");
    printf("| |       / _ \\   | |_) |   | |   |  _|  \n");
    printf("| |___   / ___ \\  |  _ <    | |   | |___ \n");
    printf(" \\____| /_/   \\_\\ |_| \\_\\   |_|   |_____|\n\n");
                                        
    for(i ; i <=19 ; i++){
        printf("%s\n", worlds->World_1->map->line[i]);
    }

    printf("\n Salut, %s.\n Je te shouaite la bienvenue dans le monde de Foga.", player->name);

    scanf("%d");

    
}