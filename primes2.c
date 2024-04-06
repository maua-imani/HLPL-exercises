#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num){
    if(num <= 1){
        return 0; //these are never prime numbers.
    }
    for(int i =2; i < sqrt(num); i++){
        if(num%i == 0){
            return 0;
        }
    }
return 1;
}

int count_primes(int *arr, int len){
int count =0;
for(int i=0; i < len; i++){
    if(is_prime(arr[i])){
        count++;
    }
}

return count;
}

int main(){

while(1){
int len;
if(scanf("%d", &len) == EOF){//this serves the purpose of assigning the first int to len and also checking if len is eof
    break;
}
int num[len];
for(int i=0; i < len; i++){
    scanf("%d", &num[i]); // read the rest of the numbers into the array nums with a length of len
}
int count = count_primes(num, len);
printf("%d\n", count);
}


return EXIT_SUCCESS;
}