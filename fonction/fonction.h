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
void world_1(char *ptr_pseudo);
int worlds_setup(struct world *world_builder, char world_name[], char Line_1[], char Line_2[], char Line_3[], char Line_4[], char Line_5[], char Line_6[]);
#endif