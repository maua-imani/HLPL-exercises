#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char *delete_consonants(char *line){
int len = strlen(line);
char *result = (char *)calloc((len+1), sizeof(char));
int pos = 0;
for(int i=0; i<len;i++){
if (isalpha(line[i]) && strchr("aeiouAEIOU", line[i]) != NULL)
    {
        result[pos++]=line[i];
    }
    else if(isdigit(line[i]) || line[i] == ' '){
        result[pos++] = line[i];
    }
}
 result[pos]='\0';
 return result;
}

int main()
{
    int cases;
    puts("How many lines do you want to compute?");
    scanf("%d", &cases);
    getchar();
    int line_num=0;
    while(line_num < cases){
        char line[100];
        fgets(line, sizeof(line), stdin);
        char *result = delete_consonants(line);
        printf("%s\n", result);
        free(result);
        line_num++;

    }


    return EXIT_SUCCESS;

}