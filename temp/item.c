/**
 * Struct of Armor
 *
 * int id : id of the armor
 * 
 * char name : name of the armor
 * 
 * int hp_boost : number of hp the armor boost 
 * 
 * int attack_boost : number of armor up the damage
 * 
*/
struct armor{   
    int id; 
    char name[10];
    int hp_boost;  
    int attack_boost; 
};
/**
 * Struct of sword
 *
 * int id : id of the sword
 * 
 * char name : name of the sword
 * 
 * int damage : damage of the sword
 * 
*/
struct sword{
    int id;
    char name[15];
    int damage; 
};
/**
 * Struct of Magic Orb
 *
 * int id : id of the orb
 * 
 * char name : name of the orb
 * 
 * int damage_boost : damage of the orb boost the magic attack
 * 
*/
struct magic_orb{
    int id;
    char name[15]; 
    char type_magic[10]; 
    int damage_boost;
};
/**
 * Struct of Heal
 *
 * int id : id of the Heal
 * 
 * char name : name of the heal
 * 
 * int stock : stock the player have
 * 
 * int hp_recharge : hp the heal recharge
 * 
*/
struct heal{
    int id; 
    char name[15];
    int stock ;
    int hp_recharge;
};
