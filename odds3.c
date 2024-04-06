#include <stdio.h>
#include <stdlib.h>
int count_of_odds(int *arr, int len){
int count = 0;
for(int i=0; i < len; i++){
    if(arr[i]%2!=0){
        count++;
    }
}
return count++;
}

int main(){

    int line_num = 1;
    while(line_num < 3 || line_num <=10)
    {
        int len;
        scanf("%d", &len);
        if(len == 0){
            break;
        }
        int nums[len];
        for(int i =0; i < len; i++){
            scanf("%d", &nums[i]);
        }
        int count;
        count = count_of_odds(nums, len);
        printf("%d\n", count);
        line_num++;
    }




    return EXIT_SUCCESS;
}