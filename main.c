#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonction/fonction.h"
#include "asset/asset.h"
int main(void) {

    int backup_key;
    char pseudo[100];
    int  app_create_value = builder_app(&backup_key);
    if (app_create_value == 1){

        printf("\x1b[31m[ERROR]\x1b[0m\nEn : Failed to setup IrWolrd Overlay\nFr : Une Erreur est arriver lors de la mise en place des overlay\n");
        system("pause");
        return 1;
    }
    else if (app_create_value == 0){
        nav_menu();
    }
    Start_menu(pseudo);
    
}