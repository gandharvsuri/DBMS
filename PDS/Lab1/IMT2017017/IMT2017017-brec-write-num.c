#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IMT2017017-trec-write-num.h"

int main(int argc, char *argv[]){

    if(argc !=2){
        printf("Invalid number of arguments");
    }
    
    FILE *f;
    f= fopen(argv[1], "wb");
    
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


    fwrite(&s1,sizeof(struct student),1,f);
    fwrite(&s2,sizeof(struct student),1,f);
    fwrite(&s3,sizeof(struct student),1,f);
    fwrite(&s4,sizeof(struct student),1,f);
    fwrite(&s5,sizeof(struct student),1,f);

    fclose(f);
    return 0;
}