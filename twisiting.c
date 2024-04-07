#include <stdio.h>
#include <stdlib.h>

int is_twisting(int *arr, int len){
    if(len < 2){
        return 0;
    }
    
    for(int i=0; i<len-1;i++){
        if((arr[i]<0 && arr[i+1]>0)|| (arr[i]>0 && arr[i+1]<0)){
            continue;
        }
        else{
            return 0;
        }
    }
    if((arr[len-2]<0 && arr[len-1]>0)||(arr[len-2]>0 && arr[len-1]<0)){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    int cases;
    puts("How many arrays do you want to check for?");
    scanf("%d", &cases);
    int line_num = 0;
    while(line_num < cases)
    {
        int len;
        scanf("%d", &len);
        int num[len];
        for(int i=0;i<len;i++){
            scanf("%d", &num[i]);
        }
        if(is_twisting(num, len)){
            printf("True\n");
        }
        else{
            printf("False\n");
        }
        line_num++;
    }





    return EXIT_SUCCESS;
}