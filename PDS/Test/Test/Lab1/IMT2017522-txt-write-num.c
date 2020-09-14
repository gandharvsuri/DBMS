#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int  N = 20;

int main(int argc, char*argv[])
{
  char filename[30];
  if(argc !=2) {printf("Invalid arguments\n"); return 0;}
  strcpy(filename,argv[1]);
  FILE *fp = fopen(filename,"w");
  int *l = (int*)calloc(20,sizeof(int));
  for(int i=0;i<N;i++) l[i] = i;
  for(int i=0;i<N;i++) fprintf(fp,"%d ",l[i]);
  fclose(fp);
  return 0;
}
