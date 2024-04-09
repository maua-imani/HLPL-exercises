#include <stdio.h>
#include <stdlib.h>


int count_decreasing_neighbors(int *arr, int len){
    int count = 0;
    if(len < 2){
        return 0;
    }
    for(int i =0; i<len-1; i++){
        if(arr[i]>=arr[i+1]){
            count++;
            continue;
        }
        
    }

    return count;
    
}

int main(){
    while(1)
    {
        int len;
        scanf("%d", &len);
        if(len == 0){
            break;
        }
        int num[len];
        for(int i=0; i<len;i++){
            scanf("%d", &num[i]);
        }

    int count = count_decreasing_neighbors(num, len);
    printf("%d\n", count);
        }

    return EXIT_SUCCESS;
}