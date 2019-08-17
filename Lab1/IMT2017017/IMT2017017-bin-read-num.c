#include <stdio.h>
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

    int num[20];

    fread(num,sizeof(int),20,f);
    
    for(int i=0; i<20; i++){
        printf("%d\n",num[i]);
    //  fwrite(data_pointer,sizeof_object,number_of_objects,file_ptr);
    }

    fclose(f);
    return 0;
}