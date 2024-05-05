#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
   char name[16];
   int score;
   int wins;
}HOUSE;

int cmp( const void *a, const void *b)
{
    HOUSE * left = (HOUSE *)a;
    HOUSE * right = (HOUSE *)b;
    if(left -> score != right -> score)
    {
        return -(left -> score - right -> score);
    }
    if(left -> wins != right -> wins)
    {
        return left -> wins - right -> wins;
    }
    return strcmp(left->name, right->name);
}


int main(int argc, char * argv[]){
    if (argc == 1){
        fprintf(stderr, "There is no input file\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if(!input)
    {
        fprintf(stderr, "The file cannot be opened.\n");
        return 2;

    }
    char line[102];
    int length = atoi(fgets(line, sizeof(line), input));
    HOUSE house[length];
    for(int i=0; i < length; i++)
    {
        fgets(line, sizeof(line), input);
        strcpy(house[i].name, strtok(line, ";"));
        house[i].score = atoi(strtok(NULL, ";"));
        house[i].wins = atoi(strtok(NULL, ";"));

    }
    fclose(input);

    qsort(house, length, sizeof(HOUSE), cmp);
    
    if(argc == 2){
        fprintf(stderr, "There is no output file\n");
        return 3;
    }
    input = fopen(argv[2], "w");
    if(!input)
    {
        fprintf(stderr, "This file cannot be opened.\n");
        return 4;
    }
    for(int i = 0; i < length; i++)
    {
        fprintf(input, "%s;%d;%d\n", house[i].name, house[i].score, house[i].wins);
    }
    fclose(input);
    return EXIT_SUCCESS;
}