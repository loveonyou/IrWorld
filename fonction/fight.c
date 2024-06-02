#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "../structures/structures.h"

/**
 * Find the armor and team and its life advantage
 * 
 * @param player  pointeur of struct player
 * 
 * @param type type to determine whether advantage is being subtracted or added 
 * 

*/
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

/**
 * Find the team sword and its attack advantage 
 * 
 * @param player pointeur of struct player
*/
int sword_boost(struct player *player){
    for (int i= 1; i <= 5; i++){
        if ( player->Inventory->sword[i]->equipped == true){
            return player->Inventory->sword[i]->damage;
        }
    }
}

/**
 * display combat interface 
 * 
 * @param player pointeur of struct player
 * 
 * @param mob pointeur of struct mob
 * 
 * @param hp_player_in player's initial life
 * 
 * @param hp_mob_in mob's initial life
 * 
 * @return 1 : win, 0 : loose

*/
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
    
    // display the names and lives of combatants 
    printf("\033[%d;%dH",3, 3);
    printf("%s", player->name);
    printf("\033[%d;%dH",5, 3);
    printf("%s", mob->name);
    printf("\033[%d;%dH",4, 3);
    printf("%i/%i", player->hp, hp_player_in);
    printf("\033[%d;%dH",6, 3);
    printf("%i/%i", mob->hp, hp_mob_in);

    // display attacks
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

    // display treatments
    for(int x = 1; x <= 5 ; x++){

        if (row <= 7){

            printf("\033[%d;%dH",row, 100);
            printf("[%i] %s : %i",x, player->Inventory->heal[x]->name,player->Inventory->heal[x]->quantity );
            row += 1;

        }
    }
    

    // renisialising the cursor
    printf("\033[%d;%dH",9, 0);
}
/**
 * main combat function, life saving, care management and attack 
 * 
 * @param player pointeur of struct player
 * 
 * @param mob pointeur of struct mob
*/
int fight_main(struct player *player, struct mob *mob){
    
    bool fight = true;
    int choix =  0;
    int check_attack = 0;
    int check_heal = 0;
    int check_info = 0;
    int check_info_2 = 0;
    int for_check = 0;
    int quantity = 0;
    int hp_remove, xp_win;
    int win = 0 ;

    // affect the effects of objects on the player
    int sword_boost_value = sword_boost(player);
    armor_boost(player, 1);

    //save the initial life of the player and the monster
    int hp_mob_in = mob->hp;
    int hp_player_in = player->hp; 

    
    while(player->hp > 0 && mob->hp > 0){
        //display combat interface
        fight_interface(player,mob, hp_player_in, hp_mob_in);

        printf("[1] attaquer\n[2] soin\n[3] information\n");
        printf("-> : ");
        scanf("%d", &choix);
        
        if (choix == 1){ //choice of attack and calculation of damage inflicted
            for_check = 0;

            printf("\nVeuillez saisir le chiffre devant l'attaque -> : ");
            scanf("%d", &check_attack);

            for(int i = 1; i < 16; i++){

                if(player->Inventory->attack[i]->equipped == true){

                    for_check += 1;

                    if(check_attack == for_check ){

                        mob-> hp = mob->hp - ( player->Inventory->attack[i]->damage + sword_boost_value ); // remove the attack from the monster's life
                        printf("Vouz avez retirer %ihp a l'adversaire\n", player->Inventory->attack[i]->damage + sword_boost_value); // damage display
                        
                    }
                }
            }
        
        }
        else if (choix == 2){

            // choice of treatment
            printf("\nVeuillez saisir le chiffre devant le soin -> : ");
            scanf("%d", &check_heal);

            // select quantity
            printf("Veillez entrer la quantité de %s, que vous voulez utilise\n", player->Inventory->heal[check_heal]->name);
            scanf("%d", &quantity);

            // care and care number support
            if ((player->Inventory->heal[check_heal]->hp_recharge * quantity ) > (hp_player_in - player->hp)){ // if the treatment exceeds the player's initial life
                
                player->hp = hp_player_in;
                player->Inventory->heal[check_heal]->quantity = player->Inventory->heal[check_heal]->quantity - quantity;
            }
            else {
                player->hp = player->hp + (player->Inventory->heal[check_heal]->hp_recharge * quantity );
                player->Inventory->heal[check_heal]->quantity = player->Inventory->heal[check_heal]->quantity - quantity;
            }


            // treatment display
            printf("Vous vous etes soigner de %i hp\n",player->Inventory->heal[check_heal]->hp_recharge * quantity );
            
        }
        else if ( choix == 3){

            // choice of information
            printf("[1] attaquer\n[2] soin\n");
            printf("-> : ");      
            scanf("%d", &check_info);


            if (check_info == 1){ // attack information
                for_check = 0;

                printf("\nVeuillez saisir le chiffre devant l'attaque -> : ");
                scanf("%d", &check_info_2);

                
                for(int i = 1; i < 16; i++){

                    if(player->Inventory->attack[i]->equipped == true){

                        for_check += 1;

                        if(check_info_2 == for_check ){
                            
                            // displays attack information 
                            printf("\n[INFO] : %s", player->Inventory->attack[i]->name);
                            printf("\ndégât : %i", player->Inventory->attack[i]->damage);
                            printf("\ntier  : %i\n", player->Inventory->attack[i]->tier);
                            system("pause");

                        }
                    }
                }
                
            }    
            else if (check_info == 2){ // treatment information

                printf("\nVeuillez saisir le chiffre devant le soin -> : ");
                scanf("%d", &check_info_2);

                // displays treatment information 
                printf("\n[INFO] : %s", player->Inventory->heal[check_info_2]->name);
                printf("\nSoin   : %i", player->Inventory->heal[check_info_2]->hp_recharge);
                printf("\ntier   : %i\n", player->Inventory->heal[check_info_2]->tier);
                system("pause");

            }  
            continue;
        }
        else {
            continue;
        }
        if (mob->hp > 0){

            // calculer les dégât infliger par l'adversaire et soutraction des dégât infliger a l'utilisateur
            hp_remove = rand() % mob->damage_min + (mob->damage_max - mob->damage_min + 1) ;
            player->hp = player->hp - hp_remove ;
            

            printf("%s vous a retirer %ihp\n", mob->name, hp_remove);
        }
        system("pause");
        
    }
    
    if (mob->hp <= 0){
        if (mob->xp_win_min > 0){ 
            xp_win =  rand() %  mob->xp_win_min + (mob->xp_win_max - mob->xp_win_min + 1);
            player->xp_total = player->xp_total + xp_win;
        }
        else {
            xp_win = 0;
        }
        if (xp_win  == 0){
            printf("\n\033[0;32mBravo %s \033[0m \nVous avez  gagnez le combat face a %s\n", player->name, mob->name);
        }
        else {
            printf("\n\033[0;32mBravo %s \033[0m \nVous avez  gagnez le combat face a %s, vous avez %i xp\n", player->name, mob->name, xp_win);

        }
        win = 1;
        system("pause");

    }
    else if (player->hp <= 0){
        printf("\n\033[0;31mDommage %s \033[0m \nVous avez perdu le combat face a %s", player->name, mob->name);
        system("pause");
    }

    // reset the hp of player & mob
    player->hp = hp_player_in;
    armor_boost(player, 2); 
    mob->hp = hp_mob_in;

    return win;
}