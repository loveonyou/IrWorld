#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

    int gap_for_gap_number;

    *ptr_backup_key = reading + (gap_number + 100);

    printf("%i", *ptr_backup_key);

    return 0;
}