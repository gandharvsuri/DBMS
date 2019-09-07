#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#include "pds.h"
#include "bst.h"

// Define the global variable
struct PDS_RepoInfo repo_handle;

int pds_create( char *repo_name)
{
    int status = PDS_FILE_ERROR;
    FILE *fp_data;
    FILE *fp_index;

    char *data_file = malloc(strlen(repo_name)+strlen(".dat"));
    char *index_file = malloc(strlen(repo_name)+strlen(".ndx"));
    strcpy(data_file,repo_name);
    strcat(data_file,".dat");
    strcpy(index_file,repo_name);
    strcat(index_file,".ndx");

    fp_data = fopen(data_file,"ab+");
    fp_index = fopen(index_file,"ab+");
    
    if(!fp_data || !fp_index){
        printf("FILE OPENING ERROR\n");
        return status;
    }
    fclose(fp_data);
    fclose(fp_index);

    status = PDS_SUCCESS;
    return status;
}

int pds_open( char *repo_name , int rec_size)
{
    int status = PDS_FILE_ERROR;
    FILE *fp_data;
    FILE *fp_index;
    char *data_file = malloc(strlen(repo_name)+strlen(".dat"));
    char *index_file = malloc(strlen(repo_name)+strlen(".ndx"));
    strcpy(data_file,repo_name);
    strcat(data_file,".dat");
    strcpy(index_file,repo_name);
    strcat(index_file,".ndx");

    fp_data = fopen(data_file,"ab+");
    fp_index = fopen(index_file,"ab+");

    if(!fp_data || !fp_index){
        printf("FILE OPENING ERROR\n");
        return status;
    }

    strcpy(repo_handle.pds_name,repo_name);
    repo_handle.pds_data_fp = fp_data;
    repo_handle.pds_ndx_fp= fp_index;
    repo_handle.rec_size = rec_size;
    repo_handle.repo_status = PDS_REPO_OPEN;

    status = PDS_SUCCESS;
    return status;
}

int put_rec_by_key( int key ,void *rec )
{
    int status = PDS_ADD_FAILED;
    struct PDS_NdxInfo *index = (struct PDS_NdxInfo *)malloc(sizeof(struct PDS_NdxInfo));
    long int offset = ftell(repo_handle.pds_data_fp);

    fseek(repo_handle.pds_data_fp, 0 ,SEEK_END);
    fwrite(rec,repo_handle.rec_size,1,repo_handle.pds_data_fp);
    index->key = key;
    index->offset = offset;
    bst_add_node(&repo_handle.pds_bst, key, index);

    status = PDS_SUCCESS;
    return status;
}

int get_rec_by_key( int key ,void *rec )
{
    int status = PDS_REC_NOT_FOUND;
    struct BST_Node *node = bst_search(repo_handle.pds_bst, key);
    if(node == NULL)
        return PDS_REC_NOT_FOUND;
   
    struct PDS_NdxInfo *index = (struct PDS_NdxInfo*)malloc(sizeof(struct PDS_NdxInfo));
    index = node->data;    
    int offset = index->offset;

    fseek(repo_handle.pds_data_fp, offset, SEEK_SET);
    fread(rec, repo_handle.rec_size, 1, repo_handle.pds_data_fp);
    
    status = PDS_SUCCESS;
    return status;
}

int pds_close()
{   
    int status = PDS_FILE_ERROR;
    FILE *fp_data = repo_handle.pds_data_fp;
    FILE *fp_index = repo_handle.pds_ndx_fp;
    
    if(repo_handle.repo_status != PDS_REPO_OPEN)
        return status;

    if(!fp_index)
    repo_handle.repo_status = PDS_REPO_CLOSED;
    fclose(fp_data);
    fclose(fp_index);

    status = PDS_SUCCESS;
    return status;
}

