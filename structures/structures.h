#ifndef STRUCT_H
#define STRUCT_H
struct world
    {
        bool acces;
    };
struct inventory{
        char item_name[1000][100];
        int item_id[1000];
    };
struct player
{
    int xp_total;
    char name[100];
    struct inventory *Inventory;

};


#endif 