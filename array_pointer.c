#include <stdio.h>
double getAverage(int *arr, int size){
    //here, we are not actually passing the array itself into the function argument, but a pointer to the base 
    //address of the array.
    double avg;
    double sum = 0;
    for(int i = 0; i<size; i++){
        sum += arr[i];
    }

    avg = sum/size;
    return avg;

}


int main(){

int balance[5] = {1000, 2, 3, 17, 50}; //declare and initialize an array, balance.
double avg; //declare a double variable avg;
avg = getAverage(balance, 5);
printf("Average value is %.2f\n", avg);


return 0;

}