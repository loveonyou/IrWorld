#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Create the backup key
 * 
 * @param ptr_backup_key pointeur of the backup key
 * 
 * return 0 on success
*/
int create_save_key(int *ptr_backup_key){
    srand((unsigned)time(NULL));

    int reading = rand() % 2;

    if (reading == 0) {
        reading = 01;
    }
    else if (reading == 1) {
        reading = 10;
    }

    int gap_number = rand() % 11;

    *ptr_backup_key = reading + (gap_number + 100);
    
    return 0;
}