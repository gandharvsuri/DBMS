#include "IMT2017522-brec-write-num.h"

int main(int argc, char*argv[])
{
  char filename[30];
  if(argc !=2) {printf("Invalid arguments\n"); return 0;}
  strcpy(filename,argv[1]);
  FILE *fp = fopen(filename,"rb");

  Student *l = (Student*)calloc(5,sizeof(Student));
  fread(l,sizeof(Student),5,fp);

  for(int i=0;i<5;i++)
  {
    Student s = l[i];
    printf("Student s%d: %d %s %d\n",i,s.roll,s.name,s.age);
  }

  return 0;
}