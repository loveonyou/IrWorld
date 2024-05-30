#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "../structures/structures.h"

void armor_boost(struct player *player, int type){
    for (int i= 1; i <= 5; i++){
        if ( player->Inventory->armors[i]->equipped == true && type == 1){
            player->hp = player->hp + player->Inventory->armors[i]->hp_boost;
        }
        if ( player->Inventory->armors[i]->equipped == true && type == 2){
            player->hp = player->hp - player->Inventory->armors[i]->hp_boost;
        }
    }
}

int sword_boost(struct player *player){
    for (int i= 1; i <= 5; i++){
        if ( player->Inventory->sword[i]->equipped == true){
            return player->Inventory->sword[i]->damage;
        }
    }
}
void fight_interface(struct player *player, struct mob *mob, int hp_player_in, int hp_mob_in){
    int row = 3;


    
    
    system("CLS");
    printf(" Vie                                 \t\t Attaque                              \t\t  Soins \n");
    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\t\t ╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\t\t ╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    printf("║                                   ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("║                                   ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("║                                   ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("║                                   ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("║                                   ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\t\t ╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\t\t ╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
    
    printf("\033[%d;%dH",3, 3);
    printf("%s", player->name);
    printf("\033[%d;%dH",5, 3);
    printf("%s", mob->name);
    printf("\033[%d;%dH",4, 3);
    printf("%i/%i", player->hp, hp_player_in);
    printf("\033[%d;%dH",6, 3);
    printf("%i/%i", mob->hp, hp_mob_in);

    for(int i = 1; i < 16; i++){
        if (row <= 6){
        if(player->Inventory->attack[i]->equipped == true){
             printf("\033[%d;%dH",row, 52);
             printf("[%i] %s",i, player->Inventory->attack[i]->name);
             row += 1;   
        }
        }
    }
    row = 3;
    for(int x = 1; x <= 5 ; x++){
        if (row <= 7){
            printf("\033[%d;%dH",row, 100);
            printf("[%i] %s : %i",x, player->Inventory->heal[x]->name,player->Inventory->heal[x]->quantity );
            row += 1;
        }
    }
    


    printf("\033[%d;%dH",9, 0);
}
int fight_main(struct player *player, struct mob *mob){
    bool fight = true;
    int choix =  0;
    int check_attack = 0;
    int check_heal = 0;
    int for_check = 0;
    int quantity = 0;
    int hp_remove, xp_win;

    int sword_boost_value = sword_boost(player);
    armor_boost(player, 1);
    int hp_mob_in = mob->hp;
    int hp_player_in = player->hp; 

    
    while(player->hp > 0 && mob->hp > 0){
        fight_interface(player,mob, hp_player_in, hp_mob_in);
        printf("[1] attaquer\n[2] soin\n");
        printf("-> : ");
        scanf("%d", &choix);
        if (choix == 1){
            printf("\nVeuillez saisir le chiffre devant l'attaque -> : ");
            scanf("%d", &check_attack);
            for_check = 0;
            for(int i = 1; i < 16; i++){
                if(player->Inventory->attack[i]->equipped == true){
                    for_check += 1;
                    if(check_attack == for_check ){

                        mob-> hp = mob->hp - ( player->Inventory->attack[i]->damage + sword_boost_value );
                        printf("Vouz avez retirer %i a l'adversaire\n", player->Inventory->attack[i]->damage + sword_boost_value);
                        
                    }
                }
            }
        
        }
        else if (choix == 2){
            printf("\nVeuillez saisir le chiffre devant le soin -> : ");
            scanf("%d", &check_heal);
            printf("Veillez entrer la quantité de %s, que vous voulez utilise\n", player->Inventory->heal[check_heal]->name);
            scanf("%d", &quantity);
            player->hp = player->hp + (player->Inventory->heal[check_heal]->hp_recharge * quantity );
            printf("Vous vous etes soigner de %i hp\n",player->Inventory->heal[check_heal]->hp_recharge * quantity );
            player->Inventory->heal[check_heal]->quantity = player->Inventory->heal[check_heal]->quantity - quantity;
        }
        else {
            continue;
        }
        if (mob->hp > 0){
            hp_remove = rand() % mob->damage_min + (mob->damage_max - mob->damage_min + 1) ;
            player->hp = player->hp - hp_remove ;
            printf("%s vous a retirer %i\n", mob->name, hp_remove);
        }
        system("pause");
        
    }
    
    if (mob->hp < 0){
        xp_win =  rand() %  mob->xp_win_min + (mob->xp_win_max - mob->xp_win_min + 1);
        printf("\n\033[0;32mBravo %s \033[0m \nVous avez  gagnez le combat face a %s, vous avez %i xp\n", player->name, mob->name, xp_win);
        player->xp_total = player->xp_total + xp_win;
        system("pause");
    }
    else if (player->hp < 0){
        printf("\n\033[0;31mDommage %s \033[0m \nVous avez perdu le combat face a %s", player->name, mob->name);
        system("pause");
    }

    // reset the hp of player & mob
    player->hp = hp_player_in;
    armor_boost(player, 2); 
    mob->hp = hp_mob_in;



    return 0;
}