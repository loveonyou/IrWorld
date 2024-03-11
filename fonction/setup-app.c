#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../asset/asset.h"


int builder_app(int *ptr_backup_key ){
    create_save_key(ptr_backup_key);
    system("chcp 65001");
    int check = system("title \" IrWorld | Creation du Compte \" ");
    system("CLS");
    return check;
}