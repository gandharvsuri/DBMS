#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "pds.h"
#include "Item.h"

int add_item( struct Item *item )
{
    int status;

	status = put_rec_by_key( item->item_id, item );

	if(status != PDS_SUCCESS ){
		fprintf(stderr, "Unable to add Item with key %d. Error %d", item->item_id, status );
		return ITEM_FAILURE;
	}
	return status;
}

void print_item( struct Item *item )
{
    printf("Item Id: %d \nItem Name: %s\nItem Type : %s \nPrice: %f \nExpiry Date: %s \nVehicle Type: %s\nRetail Price: %d\n", 
            item->item_id,
            item->item_name,
            item->item_type,
            item->MRP,
            item->expiry_date,
            item->vehicle_type,
            item->retail_price);

}

int search_item( int item_id, struct Item *item  )
{
    return get_rec_by_ndx_key( item_id, item);
}

int search_item_by_name( char *item_name,struct Item *item)
{
    return get_rec_by_non_ndx_key(item_name, item, match_item_name);
}

int match_item_name( struct Item *item, char *item_name){

	if(item == NULL || item_name == NULL)
		return 2;
	
	else if (strcmp(item->item_name,item_name) == 0)
		return 0;

	return 1;
}

int modify_item(int item_id, struct Item *item)
{
    return modify_rec_by_key(item_id, item);
}

int delete_item(int item_id)
{
    return delete_rec_by_ndx_key(item_id);
}

float retail_price(float mrp, float discount)
{
    mrp -= ((mrp*discount)/100);
    return (int)(mrp + 0.5);
}
