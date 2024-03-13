#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../asset/asset.h"

/**
 * build asset and overlay for the app
 *
 * @return 1 or 0 , corresponding if the asset setup correctly, 1 : error, 0 : success
 */
int builder_app(int *ptr_backup_key ){
    create_save_key(ptr_backup_key);
    int check_police = system("chcp 65001");
    int check_title = system("title \" IrWorld | Creation du Compte \" ");
    system("CLS");

    if (check_police == 0 && check_title == 0){
        return  0;   
    }
    else{
        return 1;
    }
}