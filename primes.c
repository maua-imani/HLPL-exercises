#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_prime(int num){
    if(num <= 1){
        return 0; 
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}


int count_of_primes(int *arr, int len){
    int count = 0;
    for(int i=0; i < len; i++){
        if(is_prime(arr[i])){
            count ++;
        }
    }

    return count; 

}
int main()
{
int line_num = 1;

while(1){
    if(line_num > 10){
        break;
    }
puts("Enter the values of the array:");
int len;
scanf("%d", &len);
int nums[len];
for(int i=0; i<len;i++){
    scanf("%d", &nums[i]);
}
int count = count_of_primes(nums, len);
printf("%d\n", count);
line_num++;
}

return EXIT_SUCCESS;
}