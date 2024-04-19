#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    //each argument here, ie, arguments read from the cli is a string therefore use atoi to convert them to integers

    int max  = atoi(argv[1]); //index here starts from one
    for(int i = 2; i<argc;i++){
        if(atoi(argv[i]> max)){
            max = atoi(argv[i]);

        }
    }
    
printf("%d\n", max);


    return EXIT_SUCCESS;
}