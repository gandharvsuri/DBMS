#include "IMT2017522-brec-write-num.h"

int main()
{
  FILE *fp = fopen("Student.dat","wb");
  
  Student s1,s2,s3,s4,s5;
  s1.roll = 522, s2.roll = 43, s3.roll = 521, s4.roll = 2, s5.roll = 11;
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
  fwrite(l,sizeof(Student),5,fp);
  fclose(fp);
  return 0;
}