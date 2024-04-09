//Write a program that reads input for the user and for any digit, doubles it. The user should be able to continue entering data
//until they input "END"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char * double_digits(char * original){
    int len = strlen(original);
    char * result = (char *)calloc((len*2)+1, sizeof(char));
    int pos=0;
    for(int i=0; i<len;i++){
        if(isdigit(original[i])){
            result[pos++]=original[i];
        }
        result[pos++]=original[i];
    }

    result[pos++] = '\0';

    return result;
}


int main(){
while(1){
    char line[101];
    fgets(line, sizeof(line), stdin);
    if(strcmp(line, "END\n")==0){
        break;
    }
    char * final = double_digits(line);
    puts(final);
    free(final);
}
}