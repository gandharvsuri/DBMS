#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#include "pds.h"

// Define the global variable
struct PDS_RepoInfo repo_handle;

int pds_create( char *repo_name)
{
    int status = PDS_FILE_ERROR;
    FILE *fp;
    fp = fopen(repo_name,"rb+");
    if(!fp){
        printf("FILE HANDLING ERROR\n");
        return status;
    }
    fclose(fp);
    status = PDS_SUCCESS;
    return status;
}

int pds_open( char *repo_name )
{
    int status = PDS_FILE_ERROR;
    FILE *fp;
    fp = fopen(repo_name,"rb+");
    if(!fp){
        printf("FILE HANDLING ERROR\n");
        return status;
    }
    strcpy(repo_handle.pds_name,repo_name);
    repo_handle.pds_data_fp = fp;
    status = PDS_REPO_OPEN;
    return PDS_SUCCESS;
}

int put_rec_by_key( int key ,struct Contact *rec )
{
    fseek(repo_handle.pds_data_fp, 0 ,SEEK_END);
    fwrite(rec,sizeof(struct Contact),1,repo_handle.pds_data_fp);
    return PDS_SUCCESS;
}

int get_rec_by_key( int key ,struct Contact *rec )
{
    struct Contact temp;
    int status = PDS_REC_NOT_FOUND;
    fseek(repo_handle.pds_data_fp, 0 ,SEEK_SET);
    while(fread(rec,sizeof(struct Contact),1,repo_handle.pds_data_fp)!=0){
        if(key == rec->contact_id){
            status = PDS_SUCCESS;
            return status;
        }
    }
    return status;
}

int pds_close()
{
    fclose(repo_handle.pds_data_fp);
    return PDS_SUCCESS;
}

