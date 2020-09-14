#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "IMT2017522-trec-write-num.h"

int main(int argc, char*argv[])
{
  char filename[30];
  if(argc!=2) {printf("Invalid Arguments\n"); return 0;}
  strcpy(filename,argv[1]);

  FILE *fp = fopen(filename,"r");
  if(fp==NULL) {printf("File does not exist\n"); return 0;}

  for(int i=0;i<5;i++)
  {
    Student s;
    fscanf(fp,"%d,%[^,],%d,",&s.rollno,s.name,&s.age);
    printf("Student s%d: %d %s %d\n",i,s.rollno,s.name,s.age);
  }

  // printf("Student s2: %d %s %d\n",s2.rollno,s2.name,s2.age);
  fclose(fp);
  return 0;
}