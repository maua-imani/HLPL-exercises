#include <stdio.h>
#include <stdlib.h>


int count_local(int *arr, int len){
    if(len < 3){
        return 0;
    }
    int count = 0;
    for(int i = 1; i < len -1; i++){
        if(arr[i]< arr[i-1] && arr[i] < arr[i+1]){
            count++;
        }
    }

    return count;
}

int main(){
    while(1){
        puts("Enter your array:");
        int len; 
        if(scanf("%d", &len) == EOF){
            break;
        }
        int num[len];
        for(int i = 0; i < len; i++){
            scanf("%d", &num[i]);
        }

        int count = count_local(num, len);
        printf("%d\n", count);

    }

    return EXIT_SUCCESS;
}