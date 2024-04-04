#include <stdio.h>
#include <stdlib.h>



int main(void){

    int height = 0;
    scanf("%d", &height);

    //Row counter - this variable will help us to specify how each row looks like.
    for( int row = 0; row < height; row++){


        for(int spaces = height - row - 1; spaces > 0; spaces--){
            printf(" ");
        }
        for(int hash = row+1; hash > 0; hash--){

            printf("#");
        }
        printf("  ");
        for(int hash_r = row+1; hash_r > 0; hash_r--){
            printf("#");
        }
        printf("\n");


    }

return EXIT_SUCCESS;

}