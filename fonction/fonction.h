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
int sword_setup(struct sword *sword_builder,int id, char sword_name[],int tier, int damage);
int armor_setup(struct armor *armor_builder, int id, char armor_name[], int tier, int hp_boost, int attack_boost);
int magic_orb_setup(struct magic_orb *orb_builder, int id, char magic_orb_name[],  int tier, char type_magic[], int damage_boost);
int heal_setup(struct heal *heal_builder, int id ,char heal_name[],int tier, int hp_recharge);
int level_of_player(int xp);
int fight_main(struct player *player,struct mob *mob);
int attack_setup(struct attack *attack_builder, int id ,char attack_name[],int tier, int type, int damage);
void fight_interface(struct player *player, struct mob *mob, int hp_player_in, int hp_mob_in);
int mob_setup(struct mob *mob_builder ,char name[], int hp , int damage_min, int damage_max, int xp_win_min, int xp_win_max);
void armor_boost(struct player *player, int type);
int sword_boost(struct player *player);
#endif