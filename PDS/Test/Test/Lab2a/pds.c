#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#include "pds.h"
#include "contact.h"


// Define the global variable
struct PDS_RepoInfo repo_handle;

int pds_create( char *repo_name)
{
  // To make sure the file we're writing into exists
  FILE* fp = fopen(repo_name,"wb+");
  fclose(fp);


  return PDS_SUCCESS;
}

int pds_open( char *repo_name )
{
  if(repo_handle.repo_status == 0) repo_handle.repo_status = PDS_REPO_CLOSED;

  if(repo_handle.repo_status == PDS_REPO_OPEN) 
  {
    return PDS_REPO_ALREADY_OPEN;
  }
  else if(repo_handle.repo_status == PDS_REPO_CLOSED)
  {
    FILE* fp = fopen(repo_name,"rb+");
    strcpy(repo_handle.pds_name,repo_name);
    repo_handle.repo_status = PDS_REPO_OPEN;
    repo_handle.pds_data_fp = fp;

    return PDS_SUCCESS;
  }

  return PDS_SUCCESS;
}

int put_rec_by_key( int key, struct Contact *rec )
{
  FILE* fp = repo_handle.pds_data_fp;

  if(fp == NULL) return PDS_FILE_ERROR;

  fseek(fp,0,SEEK_END);
  fwrite(rec,sizeof(struct Contact),1,fp);
  return PDS_SUCCESS;  
}

int get_rec_by_key( int key, struct Contact *rec )
{
  FILE* fp = repo_handle.pds_data_fp;

  if(fp == NULL) return PDS_FILE_ERROR;

  fseek(fp,0,SEEK_SET);

  int success = 0;

  while(fread(rec,sizeof(struct Contact),1,fp))
  {
    if(rec -> contact_id == key) 
    {
      success = 1;
      break;
    }
  }

  if(!success) return PDS_REC_NOT_FOUND;
  else return PDS_SUCCESS;
}

int pds_close()
{
  if(PDS_REPO_CLOSED == repo_handle.repo_status)
  {
    return PDS_SUCCESS;
  }

  fclose(repo_handle.pds_data_fp);

  repo_handle.repo_status = PDS_REPO_CLOSED;
  strcpy(repo_handle.pds_name,"");
  repo_handle.pds_data_fp = NULL;

  return PDS_SUCCESS;
}

