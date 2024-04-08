#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * double_even_digits(char *line)
{
int len = strlen(line);
char *double_evens = (char *)calloc((len*2)+1, sizeof(char));
int pos=0;
for(int i=0; i<len;i++){
    if(isdigit(line[i]) && line[i]%2 == 0){
        double_evens[pos++] = line[i];
    }
    double_evens[pos++] = line[i];
}
double_evens[pos++] = '\0';
return double_evens;
}
int main()
{
    int cases;
    puts("How many operations do you want to perform?");
    scanf("%d", &cases);
    getchar();
    int line_num = 0;
    while(line_num < cases){
        char line[100];
        fgets(line, sizeof(line), stdin);
        char *evens = double_even_digits(line);
        printf("%s", evens);
        free(evens);
        line_num++;
    }

    return EXIT_SUCCESS;
}