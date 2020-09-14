#include "IMT2017522-trec-write-num.h"
#include<string.h>

int main(int argc, char* argv[])
{
  char filename[30];
  if(argc!=2) {printf("Invalid Arguments\n"); return 0;}
  strcpy(filename,argv[1]);
  FILE *fp = fopen(filename,"w");
  if(fp==NULL) {printf("File does not exist\n"); return 0;}

  Student s1,s2,s3,s4,s5;
  s1.rollno = 522, s2.rollno = 43, s3.rollno = 521, s4.rollno = 2, s5.rollno = 11;
  s1.age = s2.age = s3.age = s4.age = s5.age = 20;
  strcpy(s1.name ,"Rathin");
  strcpy(s2.name,"Ssm");
  strcpy(s3.name ,"Ram");
  strcpy(s4.name ,"Appan");
  strcpy(s5.name ,"Koolz");

  Student *l = (Student*)calloc(5,sizeof(Student));
  l[0] = s1;
  l[1] = s2;
  l[2] = s3;
  l[3] = s4;
  l[4] = s5;

  for(int i=0;i<5;i++)
  {
    fprintf(fp,"%d,%s,%d,",l[i].rollno,l[i].name,l[i].age);
  }
  fclose(fp);
  return 0;
}