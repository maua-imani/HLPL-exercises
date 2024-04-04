#include <stdio.h>
#include <stdlib.h>
int fibo(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return (fibo(n-1)+fibo(n-2));
    }
}

int main(){
    int number;
    while(scanf("%d", &number) != EOF){
        for(int i=0; i <= number; i++){
            printf("%d ", fibo(i));
        }
        printf("\n");
        printf("= %d\n", fibo(number));
    }



    return EXIT_SUCCESS;
}