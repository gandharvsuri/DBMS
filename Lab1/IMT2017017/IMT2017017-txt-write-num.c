#include <stdio.h>

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

    for(int i=1; i<21; i++){
        fprintf(f,"%d\n",i);
    }

    fclose(f);
    return 0;
}