#include <stdio.h>
#include <stdlib.h>

int main(){
    int len;
    int count;
    

    while(1){

        count = 0;
        scanf("%d", &len);
        if(len == 0){
            break;
        }
        int nums[len];
        int max;
        for(int i=0; i < len; i++){
            scanf("%d", &nums[i]);
        }
        for(int j=0; j < len; j++){
            max = nums[0];
            if(nums[j]> max){
                max = nums[j];
            }
        }

        for(int k = 0; k < len; k++){
            if(max==nums[k]){
                count++;

            }
        }
       printf("%d\n", count); 

    }





    return EXIT_SUCCESS;
}