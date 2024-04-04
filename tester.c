#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int max;

    scanf("%d", &num);
    max=num;

    while(scanf("%d", &num) != EOF){
        if(num > max){
            max=num;
        }
    }


printf("The biggest number computed is %d\n", max);

    return EXIT_SUCCESS;
}