#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[])
{
  char filename[30];
  if(argc !=2) {printf("Invalid arguments\n"); return 0;}
  strcpy(filename,argv[1]);
  FILE *fp = fopen(filename,"rb");
  if(fp==NULL) return 0;

  int*m = (int*)calloc(20,sizeof(int));
  fread(m,sizeof(int),20,fp);
  
  for(int i=0;i<20;i++) printf("%d ",m[i]);
  printf("\n");
  fclose(fp);
  return 0;
}
