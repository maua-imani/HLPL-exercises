#include <stdio.h>
#include <stdlib.h>


int main(){
    int count = 0;
    while(1){
    int len;
    scanf("%d", &len); 
    if(len == 0){
        break;
    }
    int max;
    scanf("%d", &max);
    count = 0; 
    for(int i =1; i <= len; i++){
    int num;
    scanf("%d", &num);
    if(num > max){
        max = num;
        count = 1;
    }
    if(num == max){
        count++;
    }
    }
    
   printf("%d\n", count);
    }
    return EXIT_SUCCESS;

}