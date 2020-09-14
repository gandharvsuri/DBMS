#include <stdio.h>

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
    
    int num;
    for(int i=0; i<20; i++){
        fscanf(f,"%d",&num);
        printf("%d\n",num);
    }

    fclose(f);
    return 0;
}