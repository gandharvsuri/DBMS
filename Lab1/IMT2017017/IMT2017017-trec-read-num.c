#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//strtok.h string tokenizer

int main(int argc, char *argv[]){

    if(argc !=2){
        printf("Invalid number of arguments");
    }
    
    FILE *f;
    f= fopen(argv[1], "r");
    
    
    if(!f){
        printf("File Handling Error");
        return 0;
    }

    int rollno;
    char name[30];
    int age;

    // char buff[1024];
    // while(fgets(buff,1024,f)){

    //     char *token = strtok(buff, ",");
        
    //     while(token!=NULL){
    //         printf("%s",token);
    //         token= strtok(NULL,",");
    //     }
    // 
    
    for(int i=0;i<5;i++){
        fscanf(f,"%d, %[^,], %d",&rollno,name,&age);
        printf("rollno:%d, name:%s, age:%d\n",rollno,name,age);
    }

    fclose(f);
    return 0;
}