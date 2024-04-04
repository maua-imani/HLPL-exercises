#include <stdlib.h>
#include <stdio.h>

int it_factorial(int a){
int result = 1;
for(int i=1; i <= a; i++){
    result *= i;
}

return result;
}

int re_factorial(int a){
    //return a==0? 1: a * re_factorial(a-1);
    //This is read as: if a is 0, return 1 otherwise, return a*re_factorial(a-1)
    if (a == 0){
        return 1;
    }
    else{
        return a * re_factorial(a-1);
    }
}


int main(){
int a;
puts("Enter the number whose factorial you want to compute:\n");
scanf("%d", &a);
printf("%d! is %d\n", a, it_factorial(a));
printf("%d! is %d\n", a, re_factorial(a));
}