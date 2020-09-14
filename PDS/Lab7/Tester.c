#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Item.h"
#include "pds.h"
#include "bst.h"

void Usage(){
    printf("Commands to use the PDS system\n\n");
    printf("ADD <name> <id> : add a new item\n");
    printf("FIND <name/id> <0/1> : search an existing item\n");
    printf("CHANGE <name> <id> : modiftg an existing item\n");
    printf("DELETE <name> <id> : delete an item\n");
    printf("QUIT : exit the PDS system\n");
    printf("\n \n \n");
}

int main()
{
    Usage();
    long int i = 100000;

    int status;

    status = pds_open("Garage", sizeof(struct Item));
    if(status == PDS_SUCCESS)
			printf("File Opened\n");
	else
    {
        printf("Error in Pds open\n.");
        exit(1);
    }

    while(1){

        struct Item test_item;

        char command[50],param1[50];
        int param2;
        scanf("%s",command);

        if(!strcmp(command,"QUIT"))
        {
            status = pds_close();
            if(status == PDS_SUCCESS)
            {
			    printf("Succesfully out\n");
                exit(1);
            }
	        else
            {   
                printf("FAIL\n");
                printf("Error in Pds close.\n");
            }
        }

        scanf("%s%d",param1,&param2);
        if(!strcmp(command,"ADD"))
        {
    
            strcpy(test_item.entry_date,"Today's Date");

            sprintf(test_item.item_name, "%s", param1);
            test_item.item_id= param2;
            printf("Item Type ");
            scanf("%s",&(test_item.item_type));
            printf("Vehicle Type ");
            scanf("%s",&(test_item.vehicle_type));
            printf("Part Number ");
            scanf("%s",&(test_item.part_number));
            printf("MRP");
            scanf("%s",&(test_item.MRP));
            printf("Expiry Date ");
            scanf("%s",&(test_item.expiry_date));
            printf("discount percentage");
            scanf("%s",&(test_item.discount_percentage));




            status = put_rec_by_key(test_item.item_id,&test_item);
            if(status == PDS_SUCCESS)
			printf("Item Added Succesfully\n");
	        else
            {
                printf("FAIL\n");
                printf("Error in Pds put_rec_by_key.\n");
            }
        }   

        if(!strcmp(command,"FIND"))
        {
            if(param2 == 0){
                status = search_item_by_name(param1,&test_item);
                if(status == PDS_SUCCESS)
			    {   printf("Found \n");
                    print_item(&test_item);
                }
	            else
                {
                    printf("FAIL\n");
                    printf("Error in Pds put_rec_by_name.");
                }
            }

            else if(param2 == 1){
                int x;
                sscanf(param1,"%d",&x);
                status = search_item(x,&test_item);
                if(status == PDS_SUCCESS)
			    {   printf("Found \n");
                    print_item(&test_item);
                }
	            else
                {
                    printf("FAIL\n");
                    printf("Error in Pds put_rec_by_key.\n");
                }
            }
        }

        if(!strcmp(command,"CHANGE"))
        {
            strcpy(test_item.entry_date,"Today's Date");

            sprintf(test_item.item_name, "%s", param1);
            test_item.item_id= param2;
            printf("Item Type ");
            scanf("%s",&(test_item.item_type));
            printf("Vehicle Type ");
            scanf("%s",&(test_item.vehicle_type));
            printf("Part Number ");
            scanf("%s",&(test_item.part_number));
            printf("MRP ");
            scanf("%s",&(test_item.MRP));
            printf("Expiry Date ");
            scanf("%s",&(test_item.expiry_date));

            test_item.retail_price = retail_price(test_item.MRP,test_item.discount_percentage);

            status = modify_item(test_item.item_id,&test_item);
            if(status == PDS_SUCCESS)
			    printf("Item Modified Succesfully\n");
	        else
            {
                printf("FAIL\n");
                printf("Error in Pds modify_rec_by_key.\n");
            }
        }
    
        if(!strcmp(command,"DELETE"))
        {
            status = delete_item(param2);
            if(status == PDS_SUCCESS)
			    printf("Item deleted Succesfully\n");
	        else
            {
                printf("FAIL\n");
                printf("Error in Pds delete_rec_by_key.\n");
            }
        }

        else
            Usage();
    }
}

