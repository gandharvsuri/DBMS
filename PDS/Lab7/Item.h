#ifndef ITEM_H
#define ITEM_H

#define ITEM_SUCCESS 0
#define ITEM_FAILURE 1

struct Item
{
    int item_id;
    char item_name[30];
    char item_type[50]; // Engine Oil, car wax, Bearings etc.
    float MRP;
    char entry_date[30];
    char expiry_date[30];
    float discount_percentage;
    char vehicle_type[30]; //Car, Two weeler
    char part_number[30];
    float retail_price;
    
};

int add_item( struct Item *item );

void print_item( struct Item *item );

int search_item( int item_id, struct Item *item  );

int search_item_by_name( char *item_name,struct Item *item);

int match_item_name(struct Item *item, char* name);

int modify_item(int item_id, struct Item *item);

int delete_item(int item_id);

float retail_price(float mrp,float discount);

#endif