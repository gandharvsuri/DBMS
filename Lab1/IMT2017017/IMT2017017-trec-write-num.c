#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IMT2017017-trec-write-num.h"

int main(int argc, char *argv[]){


    if(argc !=2){
        printf("Invalid number of arguments");
    }
    
    FILE *f;
    f= fopen(argv[1], "w");
    
    if(!f){
        printf("File Handling Error");
        return 0;
    }
    
    struct student s1;
    struct student s2;
    struct student s3;
    struct student s4;
    struct student s5;

    s1.rollno = 10;
    strcpy(s1.name , "AAA");
    s1.age = 24;

    s2.rollno = 20;
    strcpy(s2.name , "AAA");
    s2.age = 24;
    
    s3.rollno = 30;
    strcpy(s3.name , "AAA");
    s3.age = 24;
    
    s4.rollno = 40;
    strcpy(s4.name , "AAA");
    s4.age = 24;
    
    s5.rollno = 50;
    strcpy(s5.name , "AAA");
    s5.age = 24;

    fprintf(f,"%d,%s,%d\n",s1.rollno,s1.name,s1.age);
    fprintf(f,"%d,%s,%d\n",s2.rollno,s2.name,s2.age);
    fprintf(f,"%d,%s,%d\n",s3.rollno,s3.name,s3.age);
    fprintf(f,"%d,%s,%d\n",s4.rollno,s4.name,s4.age);
    fprintf(f,"%d,%s,%d\n",s5.rollno,s5.name,s5.age);

    fclose(f);
    return 0;
}
