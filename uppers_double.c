//Duplicate upper case letters

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *duplicating_uppers(char *line){
    int len = strlen(line);
    char *result = (char *)calloc((len*2)+1, sizeof(char));
    int pos=0;
    for(int i=0; i < len; i++)
    {
        if(isupper(line[i])){
            result[pos++] = line[i];
        }
        result[pos++]=line[i];
    }
    result[pos++]='\0';
    return result;
}
int main()
{
    char line[100];
    while(fgets(line, sizeof(line), stdin)){
        if(line[0]=='\n'){
            break;
        }

         char *result = duplicating_uppers(line);
         puts(result);
         free(result);
    }
}