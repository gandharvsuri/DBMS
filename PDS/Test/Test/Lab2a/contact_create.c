#include <stdio.h>
#include <stdlib.h>
#include "pds.h"
#include "contact.h"

int main(int argc, char*argv[])
{

  if(argc != 2) 
  {
    fprintf(stderr, "Usage : contact_create <reponame>");
    return 0;
  }

  int status = pds_create(argv[1]);

  if(status == PDS_SUCCESS)
  {
    printf("PDF Repository %s created successfully!\n",argv[1]);
  }
  else
  {
    printf("Unalbe to create PDF repository file %s\n",argv[1]);
  }
}