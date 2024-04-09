#include <stdlib.h>
#include <stdio.h>


int has_parity(int *arr,int len){
    if(len < 1){
        return 0;
    }
    for(int i = 0; i < len; i++){
       if((arr[i]%2 == 0 && i%2 == 0)|| (arr[i]%2 != 0 && i%2 != 0)){
        continue;
       }
       else{
        return 0;
       }
       
    }
    return 1;
  
}
int main()
{
    while(1){
        int len;
        if(scanf("%d", &len) == EOF){
            break;
        }
        int num[len];
        for(int i = 0; i < len; i++){
            scanf("%d", &num[i]);
        }
        
        if(has_parity(num, len)){
            printf("True\n");
        }
        else{
            printf("False\n");
        }

    }
    return EXIT_SUCCESS;
}