#ifndef FONCTION_H
#define FONCTION_H
#include "../asset/asset.h"
#include "../structures/structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
int nav_menu();
int builder_app(int *ptr_backup_key);
void Start_menu(char *ptr_pseudo);
int choose_world();
void world_1(struct player *player, struct worlds *worlds);
int worlds_setup(struct world *world_builder, char world_name[], char Line_1[], char Line_2[], char Line_3[], char Line_4[], char Line_5[], char Line_6[], char Line_7[], char Line_8[], char Line_9[], char Line_10[],  char Line_11[], char Line_12[], char Line_13[], char Line_14[],char Line_15[],  char Line_16[], char Line_17[], char Line_18[], char Line_19[], char Line_20[]);
#endif