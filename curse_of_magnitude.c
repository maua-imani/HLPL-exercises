#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){
    int max = atoi(argv[1]);
    for(int i=1; i < argc; i++){
        int num = atoi(argv[i]);
        if(num > 0){
            continue;
        }
        if(num > max){
            max = num;
        }

    }

    printf("%d\n", max);
    return EXIT_SUCCESS;
}