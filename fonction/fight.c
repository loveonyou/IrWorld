#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "../structures/structures.h    "

void hp_format(int hp, char *hp_format) {
    const int hp_length = 10;
    int interface_hp = (hp / hp_length);

    if (interface_hp > 9) {
        interface_hp = 9;
    }
    
    
    memset(hp_format, 'x', interface_hp);
}

void fight_interface(struct player *player/*, struct Maitre *Maitre */){
    char hp_player[20];
    //char hp_Maitre[20];
    hp_format(player->hp, hp_player);
    //hp_format(Maitre->hp, hp_Maitre);
    
    
    system("CLS");
    printf(" Vie                                 \t\t Attaque                              \t\t  Soins \n");
    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\t\t ╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\t\t ╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    printf("║ You                               ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("║                                   ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("║ Master                            ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("║                                   ║\t\t ║                                   ║\t\t ║                                   ║\n");
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\t\t ╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\t\t ╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");

    printf("\033[%d;%dH",4, 3);
    printf("%s", hp_player);

    printf("\033[%d;%dH",4, 52);
    printf("teste");

    printf("\033[%d;%dH",4, 100);
    printf("teste");

    printf("\033[%d;%dH",8, 0);
}
int fight_main(struct player *player/*, struct Maitre *Maitre*/){
    bool fight = true;
    int choix =  0;

    while(fight == true){
        fight_interface(player/*, Maitre*/);
        
        printf("-> : ");
        scanf("%d", &choix);
    }
}