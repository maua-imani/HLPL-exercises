#include <stdio.h>
#include <stdlib.h>


void printArray(int* numbers, int length){
    //printf("%d\n");
    for (int i = 1; i<length;i++){
        printf("%d\n", numbers[i]);
    }
}

int main(){
    int numbers[5]; //this is how to declare an array in C.
    numbers[0] = 0;
    numbers[1] = 1;
    numbers[2] = 2;
    numbers[3] = 3;
    numbers[4] = 3;


for(int i = 0; i < 5; i++){
    printf("#%d %d %p %d\n", i, numbers[i], &numbers[i], *(numbers + i));
}
printArray(numbers, sizeof(numbers)/sizeof(int));





//-1 in C means that we will read the element in the -1 memory space.
printf("%d\n", numbers[4]);

    return EXIT_SUCCESS;
}