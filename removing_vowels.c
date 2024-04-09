#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * remove_vowels(char * line){
    int len;
    len = strlen(line);
    char *remove = (char*)calloc(len, sizeof(char));
    int index = 0;
    for(int i=0; i<len; i++){
        if(strchr("aeiouAEIOU", line[i]) == NULL){
            remove[index++]=line[i];
        }
    }

    remove[index++]= '\0';

    return remove;
}

int main(){
    while(1)
    {
        char line[101];
        fgets(line, sizeof(line), stdin);
        if(strcmp(line, "\n")== 0){
            break;
        }
        char * no_vowels = remove_vowels(line);
        puts(no_vowels);
        free(no_vowels);
    }


    return EXIT_SUCCESS;
}