#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IMT2017017-trec-write-num.h"
//strtok.h string tokenizer

int main(int argc, char *argv[]){

    if(argc !=2){
        printf("Invalid number of arguments");
    }

    FILE *f;
    f= fopen(argv[1], "rb");
    
    if(!f){
        printf("File Handling Error");
        return 0;
    }
    
    struct student s;
    for(int i=0;i<5;i++){
        fread(&s,sizeof(struct student),1,f);
        printf("%d,%s,%d\n",s.rollno,s.name,s.age);
    }

    fclose(f);
    return 0;
}