#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "../asset/asset.h"
#include "../structures/structures.h"
#include "fonction.h"
/**
 * Wolrd one
 * 
 * @param ptr_pseudo : pointer to pseudo of player 
 * 
*/

int level_1(struct player *player){

    system("title \" IrWorld | Foga : Feu de la foret  \" ");

    char choix_1;
    int win_fight;
    int win;
    int xp_win = 15;

    // Set up the mob use this level
    struct mob *mob_1 = malloc(sizeof(struct mob));
    mob_1->damage_max = 30;
    mob_1->damage_min = 5;
    mob_1->hp = 100;
    mob_1->xp_win_max = 0;
    mob_1->xp_win_min = 0;
    strcpy(mob_1->name, "Monstre de feux");





    printf("Maître Uchi : Bonjour %s, es-tu prêt à commencer ton entraînement ?(y(yes)\\n(no))\n", player->name);
    scanf(" %c", &choix_1);

    if (choix_1 == 'y'){

        printf("\nMaitre Uchi : Commencons t'on entrainement par les technique de base..");
        sleep(5);
        printf("\nVillageois : Des Monstre de feux se trouve dans la foret, nous avons besoin de votre aide Maitre Uchi");
        sleep(5);
        printf("\nMaitre Uchi : pas d'entraînement traditionnel, vous allez directement vous entraîner sur le terrain."); 
        sleep(5);

        printf("\nCe niveau servira de didacticiel dans l'histoire, assure-toi de bien comprendre comment cela fonctionne.\n");

        system("pause");
        win_fight = fight_main(player, mob_1);

        if (win_fight == 1){
            printf("\nMaitre Uchi : Bravo tu a compris comment fonctionn les combat et tu apris les technique de base, l'aventure t'attend ! \n");
            sleep(5);
            system("pause");
            win = 1;

        }
        else {
            printf("\nMaitre Uchi : Tu n'as pas réussi à combattre le monstre, tu dois recommencer.\n");
            sleep(5);
            system("pause");
            win = 0;
        }
        

    }
    else {
        printf("Au revoir %s, ton aventure s'arrête ici.\n", player->name);
        system("pause");
        exit(0);
    }

    free(mob_1);

    if (win == 1){
        return xp_win;
    }
    else {
        return 0;
    }

}
void world_1(struct player *player, struct worlds *worlds){
    system("cls");
    

    bool equipped = true;
    bool chooseinput = false;
    bool world_1_alive = true;

    int choose,caracter;
    int level_chose = 0, choose_equipped = 0, choose_equipped_2 = 0;
    int win_statut_1, win_statut_2,win_statut_3,win_statut_4,win_statut_5;
    

    printf("\nSalut, %s.\nJe te shouaite la bienvenue dans le monde de Foga.\n", player->name);
    system("pause\n");

    while (world_1_alive == true){

        system("title \" IrWorld | Monde Foga  \" ");
        system("cls");
        
        equipped = true;
        chooseinput = false;
        
        printf("  ____      _      ____    _____   _____ \n");
        printf(" / ___|    / \\    |  _ \\  |_   _| | ____| \n");
        printf("| |       / _ \\   | |_) |   | |   |  _|  \n");
        printf("| |___   / ___ \\  |  _ <    | |   | |___ \n");
        printf(" \\____| /_/   \\_\\ |_| \\_\\   |_|   |_____|\n\n");

        for(int i = 0; i <=19 ; i++){
            printf("%s\n", worlds->World_1->map->line[i]);
        }                                     
        printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
        printf("║[1]  : Feu de la foret                     ║\n");
        printf("║[2]  : Le katon                            ║\n");
        printf("║[3]  : Chez Kunomi                         ║\n");
        printf("║[4]  : La meilleur attaque c'est défense   ║\n");
        printf("║[5]  : Maitre du feux                      ║\n");
        printf("║[0]  : Quitter le monde                    ║\n");
        printf("║[10] : Inventaire                          ║\n");
        printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
        while (chooseinput == false){
            printf("-> : ");
            if(scanf("%i", &level_chose) == 1){
                chooseinput = true;
            }
            else{
                printf("Veuillez saisir un nombre\n");
                while ((caracter = getchar()) != '\n' && caracter != EOF);
            }
        }
        if (level_chose == 1){
                if (worlds->World_1->level_status[level_chose] == true){

                    win_statut_1 = level_1(player);
                    
                    if (win_statut_1 > 0){
                        player->xp_total += win_statut_1;

                        printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
                        printf("║       Item Debloque       ║\n");
                        printf("║ Attaque : Sword Stroke    ║\n");
                        printf("║ Attaque : Sword Dash      ║\n");
                        printf("║ Soin    : 15 Pommes       ║\n");
                        printf("║ Xp      : %i              ║\n", win_statut_1);
                        printf("║ Niveaux : 2               ║\n");
                        printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
                        }
                        worlds->World_1->level_status[2] = true;
                        player->Inventory->heal[1]->quantity += 15;
                        system("pause");
                }
                else {
                    printf("Vous n'avez pas atteint ce niveau.\n");
                    system("pause");
                }
            }
        else if (level_chose == 2){
            if (worlds->World_1->level_status[level_chose] == true){

            }
            else {
                    printf("Vous n'avez pas atteint ce niveau.\n");
                    system("pause");
                }
        }
        else if (level_chose == 3){
            if (worlds->World_1->level_status[level_chose] == true){

            }
            else {
                    printf("Vous n'avez pas atteint ce niveau.\n");
                    system("pause");
                }
        }
        else if (level_chose == 4){
            if (worlds->World_1->level_status[level_chose] == true){

            }
            else {
                    printf("Vous n'avez pas atteint ce niveau.\n");
                    system("pause");
                }
        }
        else if (level_chose == 5){
            if (worlds->World_1->level_status[level_chose] == true){

            }
            else {
                    printf("Vous n'avez pas atteint ce niveau.\n");
                    system("pause");
                }
        }
        else if (level_chose == 0) {

            world_1_alive = false;

        }
        else if (level_chose == 10) {

            printf("Armures : \n");
            for(int i = 1; i < 5; i++){
                if (player->Inventory->armors[i]->unlock == true){
                    printf("[%i] : Armure %s\n", i, player->Inventory->armors[i]->name);
                }
            }
            printf("Épées : \n");
            for(int i = 1; i <= 5; i++){
                if (player->Inventory->sword[i]->unlock == true){
                    printf("[%i] : Épée %s\n", i, player->Inventory->sword[i]->name);
                }
            }
            printf("Orb Magique : \n");
            for(int i = 1; i <= 5; i++){
                if (player->Inventory->magic_orb[i]->unlock == true){
                    printf("[%i] : Orb magique %s\n", i, player->Inventory->magic_orb[i]->name);
                }
            }
            printf("Attaques : \n");
            for(int i = 1; i <= 15; i++){
                if (player->Inventory->attack[i]->unlock == true){
                    printf("[%i] : %s\n", i, player->Inventory->attack[i]->name);
                }
            }
            printf("Soins : \n");
            for(int i = 1; i <= 5; i++){
                printf("[%i] : %s\n", i, player->Inventory->heal[i]->name);
            }
            system("pause");

            while (equipped == true){

                printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗");
                printf("║        Equiper            ║\n");
                printf("║ [1] : Armures             ║\n");
                printf("║ [2] : Épées               ║\n");
                printf("║ [3] : Orb Magique         ║\n");
                printf("║ [4] : Attaques            ║\n");
                printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");

                printf("-> : ");
                scanf("%i", &choose_equipped);

                if (choose_equipped == 1) {

                    printf("\nChoisi l'armure que tu veux equiper\n");
                    printf("-> : ");
                    scanf("%i", &choose_equipped_2);


                }
            }
        }
        else {

            printf("Choix Invalide");

        }
    }

}