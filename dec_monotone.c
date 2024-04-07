#include <stdio.h>
#include <stdlib.h>

int is_decreasing_monotone(int *arr, int len){
if(len < 1){
    return 0;
}
for(int i=0;i<len-1;i++){
    if(arr[i]>arr[i+1]){
        continue;
    }
    else{
        return 0;
    }
}

if(arr[len-2]> arr[len-1]){
    return 1;
}
else{
    return 0;
}
}




int main(){
int cases;
puts("How many cases do you want to check?");
scanf("%d", &cases);
int line_num = 0;
while(line_num<cases)
{
    int len;
    if(scanf("%d", &len) == EOF){
        break;
    }
    int num[len];
    for(int i = 0; i < len; i++){
        scanf("%d", &num[i]);
    }
    if(is_decreasing_monotone(num, len)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    line_num++;
}

    return EXIT_SUCCESS;
}