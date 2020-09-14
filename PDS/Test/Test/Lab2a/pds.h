#ifndef PDS_H
#define PDS_H

// Error codes
#define PDS_SUCCESS 0
#define PDS_FILE_ERROR 1
#define PDS_ADD_FAILED 2
#define PDS_REC_NOT_FOUND 3

// Repository status values
#define PDS_REPO_OPEN 10
#define PDS_REPO_CLOSED 11
#define PDS_REPO_ALREADY_OPEN 12

#include "contact.h"

struct PDS_RepoInfo{
	char pds_name[30];
	FILE *pds_data_fp;
	FILE *pds_ndx_fp;
	int repo_status; 
};

extern struct PDS_RepoInfo repo_handle;

int pds_create( char *repo_name);
int pds_open( char *repo_name );
int put_rec_by_key( int key, struct Contact *rec );
int get_rec_by_key( int key, struct Contact *rec );
int pds_close();

#endif



/*
 * We first use fseek(fp,0,SEEK_END);
 * offset = ftell(fp);
 * fwrite(fp,...);
 * index.key = key;
 * index.location = offset;
 * Add index to BST
 * 
 *
 * get_rec
 *
 * Search for key in BST
 * Identify offset  records
 * fseek(fp,offset,SEEK_SET); //ftell always tells the number of bytes after SEEK_SET
 *
 * */
