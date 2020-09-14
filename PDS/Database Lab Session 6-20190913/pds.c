#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#include "pds.h"
#include "bst.h"
#include "contact.h"
// Define the global variable
struct PDS_RepoInfo repo_handle;
void pds_unload_ndx(struct BST_Node* root);

int pds_open( char *repo_name , int rec_size)
{
    int status = PDS_REPO_ALREADY_OPEN;

    if(repo_handle.repo_status == PDS_REPO_OPEN)
        return status;

    status = PDS_FILE_ERROR;
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
    repo_handle.pds_bst = NULL;

    pds_load_ndx();
    status = PDS_SUCCESS;
    return status;
}

int put_rec_by_key( int key ,void *rec )
{
    int status = PDS_REPO_NOT_OPEN;
    if(repo_handle.repo_status != PDS_REPO_OPEN)
        return status;

    struct PDS_NdxInfo *index = (struct PDS_NdxInfo *)malloc(sizeof(struct PDS_NdxInfo));
    
    fseek(repo_handle.pds_data_fp, 0 ,SEEK_END);
    long int offset = ftell(repo_handle.pds_data_fp); 
    index->key = key;
    index->offset = offset;
    index->is_deleted = 0;


    int bst_status = bst_add_node(&repo_handle.pds_bst, key, index);
    
    if(bst_status == BST_SUCCESS){
        fwrite(rec,repo_handle.rec_size,1,repo_handle.pds_data_fp);
        status = PDS_SUCCESS;
        return status;
    }
    return PDS_ADD_FAILED;
}

int get_rec_by_ndx_key( int key ,void *rec )
{
    int status = PDS_REC_NOT_FOUND;
    struct BST_Node *node = (struct BST_Node*)malloc(sizeof(struct BST_Node));
    node = bst_search(repo_handle.pds_bst, key);
    
    if(node == NULL)
        return PDS_REC_NOT_FOUND;
    
    struct PDS_NdxInfo *index = (struct PDS_NdxInfo*)malloc(sizeof(struct PDS_NdxInfo));
    
    index = node->data;    
    if(index->is_deleted == 1)
        return PDS_REC_NOT_FOUND;

    int offset = index->offset;

    fseek(repo_handle.pds_data_fp, offset, SEEK_SET);
    fread(rec, repo_handle.rec_size, 1, repo_handle.pds_data_fp);
    
    status = PDS_SUCCESS;
    return status;
}

int pds_close()
{   
    int status = PDS_FILE_ERROR;
    char *index_file = malloc(strlen(repo_handle.pds_name)+strlen(".ndx"));
    strcpy(index_file,repo_handle.pds_name);
    strcat(index_file,".ndx");

    FILE* fp_index = fopen(index_file,"wb+");

    repo_handle.pds_ndx_fp = fp_index;

    if(repo_handle.repo_status != PDS_REPO_OPEN)
        return status;

    repo_handle.repo_status = PDS_REPO_CLOSED;
    
    pds_unload_ndx(repo_handle.pds_bst);

    //fwrite(NULL,sizeof(struct PDS_NdxInfo),1,repo_handle.pds_ndx_fp);
    bst_destroy(repo_handle.pds_bst);
    
    fclose(repo_handle.pds_data_fp);
    fclose(repo_handle.pds_ndx_fp);

    status = PDS_SUCCESS;
    return status;
}

int pds_load_ndx()
{
    struct PDS_NdxInfo* index = (struct PDS_NdxInfo*)malloc(sizeof(struct PDS_NdxInfo));
    fseek(repo_handle.pds_ndx_fp, 0 ,SEEK_SET);
    while(fread(index, sizeof(struct PDS_NdxInfo), 1, repo_handle.pds_ndx_fp)){
        struct PDS_NdxInfo *temp = (struct PDS_NdxInfo *)malloc(sizeof(struct PDS_NdxInfo));
        temp->key = index->key;
        temp->offset = index->offset;    
        bst_add_node(&repo_handle.pds_bst, temp->key, temp);
    }
    fclose(repo_handle.pds_ndx_fp);
}

void pds_unload_ndx(struct BST_Node* root)
{
    if(root == NULL){
        return;
    }

    struct PDS_NdxInfo *index = (struct PDS_NdxInfo*)malloc(sizeof(struct PDS_NdxInfo));

    index = root->data;    
    fseek(repo_handle.pds_ndx_fp, 0 ,SEEK_END);
    if(index->is_deleted == 0)
        fwrite(root->data,sizeof(struct PDS_NdxInfo),1,repo_handle.pds_ndx_fp);
    pds_unload_ndx(root->left_child);
    pds_unload_ndx(root->right_child);
    
}

int get_rec_by_non_ndx_key(void *key, void *rec, int (*matcher)(void *rec, void *key), int *io_count)
{
    int status = PDS_REC_NOT_FOUND;
    int i = 0;

    fseek(repo_handle.pds_data_fp, 0 ,SEEK_SET);
    while(fread(rec,repo_handle.rec_size,1,repo_handle.pds_data_fp)!=0){
        i++;
        if(matcher(rec,key) == 0){

            int X = ((struct Contact*)rec)->contact_id;
            struct BST_Node *node = (struct BST_Node*)malloc(sizeof(struct BST_Node));
            
            node = bst_search(repo_handle.pds_bst, X);
            if(node == NULL){
                return status;}
        
            struct PDS_NdxInfo *index = (struct PDS_NdxInfo*)malloc(sizeof(struct PDS_NdxInfo));
            index = node->data;    
            if(index->is_deleted == 1)
                return status;
            
            status = PDS_SUCCESS;
            *io_count = i;
            break;
        }
    }
    return status;

}

int modify_rec_by_key( int key, void *rec )
{
    int status = PDS_REC_NOT_FOUND;
    struct BST_Node *node = (struct BST_Node*)malloc(sizeof(struct BST_Node));
    node = bst_search(repo_handle.pds_bst, key);
    if(node == NULL)
        return PDS_REC_NOT_FOUND;
    
    struct PDS_NdxInfo *index = (struct PDS_NdxInfo*)malloc(sizeof(struct PDS_NdxInfo));
    index = node->data;    
    if(index->is_deleted == 1)
        return status;
    int offset = index->offset;

    fseek(repo_handle.pds_data_fp, offset, SEEK_SET);
    fwrite(rec, repo_handle.rec_size, 1, repo_handle.pds_data_fp);
    

    status = PDS_SUCCESS;
    return status;
}

int delete_rec_by_ndx_key( int key )
{
    int status = PDS_DELETE_FAILED;
    struct BST_Node *node = (struct BST_Node*)malloc(sizeof(struct BST_Node));
    node = bst_search(repo_handle.pds_bst, key);
    if(node == NULL)
        return status;
    
    struct PDS_NdxInfo *index = (struct PDS_NdxInfo*)malloc(sizeof(struct PDS_NdxInfo));
    index = node->data;
     if(index->is_deleted == 1)
        return status;
    status = PDS_SUCCESS; 
    index->is_deleted == 1;

    node->data = index;
    return status;
}