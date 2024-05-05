#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
   char code[6];
   char name[51];
   char theme[31];
   int bricks;
}LEGO;

int cmp(const void *a, const void *b)
{
    LEGO * left = (LEGO *)a;
    LEGO * right = (LEGO *)b;
    if(left->bricks != right->bricks)
    {
        return -(left->bricks - right -> bricks);
    }
    int theme_cmp = strcmp(left -> theme, right -> theme);
    if(theme_cmp!= 0)
    {
        return theme_cmp;
    }
    int name_cmp = strcmp(left -> name, right -> name);
    if(name_cmp!= 0)
    {
        return name_cmp;
    }
    return strcmp(left -> code, right -> code);

}

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        fprintf(stderr, "There is no input file\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if(!input)
    {
        fprintf(stderr, "This file cannot be opened\n");
        return 2;
    }
    char line[102];
    int length = 0;
    LEGO lego[20];
   
    while(fgets(line, sizeof(line), input)!= NULL)
    {
        line[strlen(line)-1] = '\0';
        strcpy(lego[length].code, strtok(line, ";"));
        strcpy(lego[length].name, strtok(NULL, ";"));
        strcpy(lego[length].theme, strtok(NULL, ";"));
        lego[length].bricks = atoi(strtok(NULL, ";"));
        length++;
    }
    fclose(input);
    qsort(lego, length, sizeof(LEGO), cmp);

    if(argc == 2)
    {
        fprintf(stderr, "There is no output file\n");
        return 3;
    }
    input = fopen(argv[2], "w");
    if(!input)
    {
        fprintf(stderr, "This file cannot be opened.\n");
        return 4;
    }
    for(int i=0; i<length; i++)
    {
        fprintf(input, "%s;%s;%s;%d\n", lego[i].code, lego[i].name, lego[i].theme, lego[i].bricks);
    }
    fclose(input);
    return EXIT_SUCCESS;
}