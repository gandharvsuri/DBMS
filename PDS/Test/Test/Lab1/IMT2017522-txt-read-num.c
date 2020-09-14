#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[])
{
  char filename[30];
  if(argc!=2) {printf("Invlaid arguments\n"); return 0;}
  strcpy(filename,argv[1]);
  FILE *fp = fopen(filename,"r");
  int*m = (int*)calloc(20,sizeof(int));
  for(int i=0;i<20;i++) fscanf(fp,"%d",&m[i]);
  for(int i=0;i<20;i++) printf("%d ",m[i]);
  printf("\n");
  fclose(fp);
  return 0;
}

/*
blah blah

 */