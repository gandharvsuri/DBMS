#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#include "pds.h"
#include "bst.h"

struct PDS_RepoInfo repo_handle;

// int pds_create(char *repo_name)
// {
//   char filename[30],indexfile[30];
//   strcpy(filename,repo_name);
//   strcpy(indexfile,repo_name);
//   strcat(filename,"_name.dat");
//   strcat(indexfile,"_index.dat");

//   FILE* fp = fopen(filename,"wb+");
//   FILE* ifp = fopen(indexfile,"wb+");

//   fclose(fp);
//   fclose(ifp);

//   return PDS_SUCCESS;
// }

int pds_open(char* repo_name,int rec_size)
{
  if(repo_handle.repo_status == 0) repo_handle.repo_status = PDS_REPO_CLOSED;

  if(repo_handle.repo_status == PDS_REPO_OPEN)
  {
    return PDS_REPO_ALREADY_OPEN;
  }
  else if(repo_handle.repo_status == PDS_REPO_CLOSED)
  {
    //Formality of file names
    char filename[30],indexfile[30];
    strcpy(filename,repo_name);
    strcpy(indexfile,repo_name);
    strcat(filename,".dat");
    strcat(indexfile,".ndx");

    FILE* fp = fopen(filename,"ab+");
    FILE* ifp = fopen(indexfile,"ab+");
    repo_handle.repo_status = PDS_REPO_OPEN;
    repo_handle.pds_data_fp = fp;
    repo_handle.pds_ndx_fp = ifp;

    repo_handle.rec_size = rec_size;

    return PDS_SUCCESS;
  }
  else return PDS_SUCCESS;
}

int put_rec_by_key(int key, void* rec)
{
  FILE* fp = repo_handle.pds_data_fp;
  FILE *ifp = repo_handle.pds_ndx_fp;

  // Because we don't know what the error could be
  if(fp == NULL || ifp == NULL) return PDS_FILE_ERROR;

  fseek(fp,0,SEEK_END);
  int offset = ftell(fp);
  
  fwrite(rec,repo_handle.rec_size,1,fp);

  struct PDS_NdxInfo *ndx = (struct PDS_NdxInfo*)calloc(sizeof(struct PDS_NdxInfo),1);
  ndx -> key = key;
  ndx -> offset = offset;

  int res = bst_add_node(&repo_handle.pds_bst,key,ndx);
  if(res == BST_SUCCESS) return PDS_SUCCESS;
  else if(res == BST_DUP_KEY) return PDS_ADD_FAILED;
  else return PDS_FILE_ERROR;
}

int get_rec_by_key(int key, void*rec)
{
  // bst_print(repo_handle.pds_bst);
  if(repo_handle.pds_bst == NULL) return PDS_FILE_ERROR;
  struct BST_Node* node = bst_search(repo_handle.pds_bst,key);
  if(node == NULL) 
  {
    return PDS_REC_NOT_FOUND;
  }
  else
  {
    struct PDS_NdxInfo* temp = node->data;
    FILE* fp = repo_handle.pds_data_fp;
    int offset = temp->offset;
    fseek(fp,offset,SEEK_SET);
    fread(rec,repo_handle.rec_size,1,fp);
    return PDS_SUCCESS;
  }
}

int pds_close()
{
  if(repo_handle.repo_status == PDS_REPO_CLOSED || repo_handle.repo_status == 0) return PDS_FILE_ERROR;
  else
  {
    FILE* fp = repo_handle.pds_data_fp;
    FILE *ifp = repo_handle.pds_ndx_fp;

    repo_handle.repo_status = PDS_REPO_CLOSED;
    strcpy(repo_handle.pds_name,"");
    fclose(fp);
    fclose(ifp);
    bst_free(repo_handle.pds_bst);
    repo_handle.rec_size = 0;
    return PDS_SUCCESS;
  }
}
