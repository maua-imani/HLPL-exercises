#include <stdio.h>
#include <stdlib.h>

int is_palindrome(int *numbers, int length){

for(int i=0; i<length/2;i++){

    if(numbers[i] != numbers[length-1-i]){
        return 0;
    }
}
return 1;
}

int main(){

    return EXIT_SUCCESS;
}