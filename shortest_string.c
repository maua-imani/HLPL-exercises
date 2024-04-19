#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[]){
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