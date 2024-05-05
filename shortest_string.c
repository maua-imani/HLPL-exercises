#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[]){
    if(argc <2){
        printf("Add arguments to the command line, please :)");
        return EXIT_FAILURE;
    }
    int len = strlen(argv[1]);
    for(int i =1; i<argc;i++)
    {
        int comp = strlen(argv[i]);
        if(comp < len){
            printf("%s\n", argv[i]);
        }
    }
    return EXIT_SUCCESS;
}