#include <stdio.h>
#include <stdlib.h>

int main(){
int pos = 0;
int neg = 0;
int line_num = 1;
int len;

while(1){
    scanf("%d", &len);
    if(len == 0){
        break;
    }
    for(int i = 1; i <= len; i++){
        int num;
        scanf("%d", &num);
        printf("%d \n", num);
        if(num > 0){
            pos++;
        }
        else if(num < 0){
            neg++;
        }
        else{
            continue;
        }
    }
  

    if(pos > neg){
        printf("%d\n", line_num);
    }

    line_num++;

  

}

return EXIT_SUCCESS;

}