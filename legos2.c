#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
   char code[6];
   char name[51];
   char theme[31];
   int bricks;
}LEGOS;


int cmp(const void *a, const void *b)
{
    LEGOS * left = (LEGOS *)a;
    LEGOS * right = (LEGOS *)b;

    if(left -> bricks != right -> bricks)
    {
        return -(left -> bricks - right -> bricks);
    }
    int theme_cmp = strcmp(left -> theme, right-> theme);
    if(theme_cmp != 0)
    {
        return theme_cmp;
    }
    int name_cmp = strcmp(left -> name, right -> name);
    if(name_cmp != 0)
    {
        return name_cmp;
    }
    return strcmp(left -> code, right -> code);
}

int main(int argc, char *argv[])
{
    if(argc==1)
    {
        fprintf(stderr, "There is no input file\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        fprintf(stderr, "This file cannot be opened\n");
        return 2;
    }

    char line[102];
    int length = 0;
    LEGOS lego[20];

    while(1)
    {
    fgets(line, sizeof(line),file);
    line[strlen(line)-1] = '\0';
    if(strcmp(line, "END") == 0)
    {
        break;
    }
    strcpy(lego[length].code, strtok(line, ";"));
    strcpy(lego[length].name, strtok(NULL, ";"));
    strcpy(lego[length].theme, strtok(NULL, ";"));
    lego[length].bricks = atoi(strtok(NULL, ";"));
    length++;
    }

    fclose(file);
    qsort(lego, length, sizeof(LEGOS), cmp);

    if(argc == 2)
    {
        fprintf(stderr, "There is no output file\n");
        return 3;
    }
    file = fopen(argv[2], "w");
    if(!file)
    {
        fprintf(stderr, "This file cannot be opened.\n");
        return 4;
    }

    for(int i=0;i<length;i++)
    {
        fprintf(file, "%s;%s;%s;%d\n", lego[i].code, lego[i].name, lego[i].theme, lego[i].bricks);
    }
    fclose(file);





    return EXIT_SUCCESS;
}