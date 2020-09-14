#include <stdio.h>

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

    int num[20];
    for(int i=1; i<21; i++){
        num[i-1]= i;
    //  fwrite(data_pointer,sizeof_object,number_of_objects,file_ptr);
    }

    fwrite(num,sizeof(int),20,f);

    fclose(f);
    return 0;
}