#include <stdio.h>
#include <stdlib.h>


int main(){
   int heads;
   int legs;
   while(scanf("%d %d", &heads, &legs) != EOF){
    int ppl;
    int dogs;
    dogs = (legs - (2*heads))/2;
    ppl = heads - dogs;
    printf("%d %d\n", ppl, dogs);
    }

    return EXIT_SUCCESS;
}