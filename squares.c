#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_square(int num){
        double exp = 0.5;
        double digit = (double)num;
        double check = pow(digit, exp);
        int fin = pow((int)check, 2);
        if(num > 0 && num == fin){
            return 1;
        }
        return 0;
}

int count_square(int * arr, int len){
    int count = 0;
    for(int i = 0; i < len; i++){
        if(is_square(arr[i])){
            count ++;
        }

    }
    return count;

}

int main(){
    while(1){

        int len;
        if(scanf("%d", &len) == EOF){
            break;
        }
        int num[len];
        for(int i=0; i < len; i++){
            scanf("%d", &num[i]);
        }
        int count = count_square(num, len);
        printf("%d\n", count);
    }


    return EXIT_SUCCESS;
}