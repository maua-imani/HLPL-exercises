#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int result = 1;
    for(int i = 1; i < argc; i++){
            int num = atoi(argv[i]);
            result *= num;
        }

printf("The result is %d\n", result);


    return EXIT_SUCCESS;
}