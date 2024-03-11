#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "fonction/fonction.h"
#include "asset/asset.h"
#include "structure/struct.h"


int main(void) {

    struct world world_1;
    
    bool app_statue = true;
    int backup_key, nav_choose;
    char pseudo[100];
    int  app_create_value = builder_app(&backup_key);
    if (app_create_value == 1){

        printf("\x1b[31m[ERROR]\x1b[0m\nEn : Failed to setup IrWolrd Overlay & Police \nFr : Une Erreur est arriver lors de la mise en place des overlay et de la police\n");
        system("pause");
        return 1;
    }
    else if (app_create_value == 0){
        Start_menu(pseudo);

        while (app_statue == true){
            nav_choose = nav_menu();
            if (nav_choose == 0){
                return 0;
            }
            else if(nav_choose == 1){
                
            }
        }
    }
    
    
}