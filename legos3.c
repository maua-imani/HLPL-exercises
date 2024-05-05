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
    LEGOS *left = (LEGOS*)a;
    LEGOS * right = (LEGOS *)b;
    if(left -> bricks != right -> bricks)
    {
        return -(left -> bricks - right -> bricks);
    }
    int theme_cmp = strcmp(left ->theme, right->theme);
    if(theme_cmp != 0)
    {
        return theme_cmp;
    }
    int name_cmp = strcmp(left ->name, right->name);
    if(name_cmp != 0)
    {
        return name_cmp;
    }
    return strcmp(left->code, right->code);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        fprintf(stderr, "There is no input file\n");
        return 1;
    }
    FILE * file = fopen(argv[1], "r");
    if(!file)
    {
        fprintf(stderr, "This file cannot be opened.\n");
        return 2;
    }
    char line[102];
    int len = atoi(fgets(line, sizeof(line),file));
    LEGOS lego[len];
   for(int i=0; i< len; i++)
   {
    fgets(line, sizeof(line), file);
    line[strlen(line)-1] = '\0';
    strcpy(lego[i].code, strtok(line, ";"));
    strcpy(lego[i].name, strtok(NULL, ";"));
    strcpy(lego[i].theme, strtok(NULL, ";"));
    lego[i].bricks = atoi(strtok(NULL, ";"));
   }


   fclose(file);
   qsort(lego, len, sizeof(LEGOS), cmp);

   if(argc == 2)
   {
    fprintf(stderr, "There is no output file.\n");
    return 3;
   }
   file = fopen(argv[2], "w");
   if(!file)
   {
    fprintf(stderr,"This file cannot be opened");
    return 4;
   }

   for(int i=0; i<len;i++)
   {
    fprintf(file, "%s;%s;%s;%d\n", lego[i].code, lego[i].name, lego[i].theme, lego[i].bricks);
   }

   fclose(file);
   return EXIT_SUCCESS;

}
