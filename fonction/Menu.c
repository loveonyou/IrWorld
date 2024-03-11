#include <stdio.h>
int nav_menu(){ /*Main Menue for use Select World, Inventari, Select Level, Xp information, */
    int choix;
    printf("  _   _             _             _   _\n");             
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
    printf("║[5] afficher la backup key     ║\n");
    printf("║[0] Quitter                    ║\n");
    printf("║[10] Help                      ║\n");
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");

    printf("-> : ");
    scanf("%i", choix );
    return choix;

}

void Start_menu(char *ptr_pseudo){ /*Start Menu  for create name tag for create sesion or load and sesion */
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
    printf("-> : ");
    scanf("%s", ptr_pseudo);
} 


void choose_world(){
    int choix;
    printf("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    printf("║[1] Choix du monde             ║\n");
    printf("║[2] Profile                    ║\n");
    printf("║[3] Chargé une sauvegarde      ║\n");
    printf("║[5] afficher la backup key     ║\n");
    printf("║[0] Quitter                    ║\n");
    printf("║[10] Help                      ║\n");
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");

    printf("-> : ");
    scanf("%i", choix );
    return choix;

}