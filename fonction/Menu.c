#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
//
/**
 * Main Menue for use Select World, Inventari, Select Level, Xp information
 *
 * @return choose : int number, corresponding to a action for navagation menu
 */
int nav_menu(){
    bool chooseinput = false; 
    int choose, caracter;
    printf("  _   _              _             _   _\n");             
    printf(" | \\ | |           (_)           | | (_)\n");            
    printf(" |  \\| | __ ___   ___  __ _  __ _| |_ _  ___  _ __ \n"); 
    printf(" | . ` |/ _` \\ \\ / / |/ _` |/ _` | __| |/ _ \\| '_ \\ \n");
    printf(" | |\\  | (_| |\\ V /| | (_| | (_| | |_| | (_) | | | |\n");
    printf(" |_| \\_|\\__,_| \\_/ |_|\\__, |\\__,_|\\__|_|\\___/|_| |_|\n");
    printf("                       __/ |                        \n");
    printf("                      |___/                       \n");
    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    printf("║[1] Choix du monde             ║\n");
    printf("║[2] Profile                    ║\n");
    printf("║[3] Chargé une sauvegarde      ║\n");
    printf("║[4] afficher la backup key     ║\n");
    printf("║[0] Quitter                    ║\n");
    printf("║[10] Help                      ║\n");
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
    while ((caracter = getchar()) != '\n' && caracter != EOF);
    while(chooseinput == false){
    printf("-> : ");
    if(scanf("%i", &choose) == 1){
        chooseinput = true;
        }
    else{
            printf("Veuillez saisir un nombre\n");
            while ((caracter = getchar()) != '\n' && caracter != EOF);
        }
    }
    return choose;
}
/**
 * Menu for starting and choose pseudo
 *
 * @param ptr_pseudo pseudo of user, type string .
 */
void Start_menu(char *ptr_pseudo){ /*Start Menu  for create name tag for create sesion or load and sesion */
    bool psdinput = false;
    int caracter;
    printf("▄█     ▄████████       ▄█     █▄   ▄██████▄     ▄████████  ▄█       ████████▄  \n");
    printf("███    ███    ███      ███     ███ ███    ███   ███    ███ ███       ███   ▀███\n");
    printf("███    ███    ███      ███     ███ ███    ███   ███    ███ ███       ███   ▀███ \n");
    printf("███▌   ███    ███      ███     ███ ███    ███   ███    ███ ███       ███    ███ \n");
    printf("███▌  ▄███▄▄▄▄██▀      ███     ███ ███    ███  ▄███▄▄▄▄██▀ ███       ███    ███ \n");
    printf("███▌ ▀▀███▀▀▀▀▀        ███     ███ ███    ███ ▀▀███▀▀▀▀▀   ███       ███    ███ \n");
    printf("███  ▀███████████      ███     ███ ███    ███ ▀███████████ ███       ███    ███ \n");
    printf("███    ███    ███      ███     ███ ███    ███   ███    ███ ███       ███    ███ \n");
    printf("█▀     ███    ███       ▀███▀███▀   ▀██████▀    ███    ███ █████▄▄██ ████████▀  \n");
    printf("       ███    ███                               ███    ███ ▀      \n");
    printf("                                                                                  ©adn\n");
    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    printf("║Bienvenue dans Iris World.     ║\n");
    printf("║Entre votre pseudonyme         ║\n");
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");
    while( psdinput == false){
    printf("-> : ");
    if(scanf("%s", ptr_pseudo) == 1){
        psdinput = true;
        }
    else{
            printf("Veuillez saisir un pseudo valide\n");
            while ((caracter = getchar()) != '\n' && caracter != EOF);
        }
    }
} 
/**
 * Menu for choose world
 *
 * @return choose : int number, corresponding to a world
 */
int choose_world(){
    bool chooseinput = false;
    int choose,caracter;
    printf("|  \\/  |                     | |\n");       
    printf("| \\  / |   ___    _ __     __| |   ___\n"); 
    printf("| |\\/| |  / _ \\  | '_ \\   / _` |  / _ \\ \n");
    printf("| |   | | | (_) | | | | | | (_| | |  __/\n");
    printf("|_|   |_|  \\n___/  |_| |_|  \\__,_|  \\___|\n");
                    
    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    printf("║[1] Tira                       ║\n");
    printf("║[2] Foga                       ║\n");
    printf("║[3] Spectro                    ║\n");
    printf("║[4] Eclusia                    ║\n");
    printf("║[?] ?                          ║\n");
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");

    while(chooseinput == false){
    printf("-> : ");
    if(scanf("%i", &choose) == 1){
        chooseinput = true;
        }
    else{
            printf("Veuillez saisir un nombre\n");
            while ((caracter = getchar()) != '\n' && caracter != EOF);
        }
    }
    return choose;
}