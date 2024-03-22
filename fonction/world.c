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
    printf(" \\____| /_/   \\_\\ |_| \\_\\   |_|   |_____|\n");
                                        
    printf("%s\n",worlds->World_1->map->line_1);
    printf("%s\n",worlds->World_1->map->line_2);
    printf("%s\n",worlds->World_1->map->line_3);
    printf("%s\n",worlds->World_1->map->line_4);
    printf("%s\n",worlds->World_1->map->line_5);
    printf("%s\n",worlds->World_1->map->line_6);
    printf("%s\n",worlds->World_1->map->line_7);
    printf("%s\n",worlds->World_1->map->line_8);
    printf("%s\n",worlds->World_1->map->line_9);
    printf("%s\n",worlds->World_1->map->line_10);
    printf("%s\n",worlds->World_1->map->line_11);
    printf("%s\n",worlds->World_1->map->line_12);
    printf("%s\n",worlds->World_1->map->line_13);
    printf("%s\n",worlds->World_1->map->line_14);
    printf("%s\n",worlds->World_1->map->line_15);
    printf("%s\n",worlds->World_1->map->line_16);
    printf("%s\n",worlds->World_1->map->line_17);
    printf("%s\n",worlds->World_1->map->line_18);
    printf("%s\n",worlds->World_1->map->line_19);
    printf("%s\n",worlds->World_1->map->line_20);
    scanf("%d");
}