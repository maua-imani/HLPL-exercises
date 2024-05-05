#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct{
    char title[40];
    int length;
    int plays;

}TRACK;


int cmp(const void * a, const void * b)
{
    TRACK * left = (TRACK *)a;
    TRACK * right = (TRACK *)b;
    if(left -> plays != right -> plays)
    {
        return -(left -> plays - right -> plays);
    }
    if(left -> length != right -> length)
    {
        return left -> length - right -> length;
    }
    return (strcmp(left->title, right -> title));
}


int main(int argc, char * argv[]){
    if (argc== 1){
        fprintf(stderr, "There is no file to read from.");
        return 1;
    }
    FILE *input =fopen(argv[1], "r");
    if(input == NULL){
        fprintf(stderr, "The file cannot be opened");
        return 2;
    }
    char line[62];
    TRACK tracks[20];
    int len = 0;
    while(fgets(line, sizeof(line), input)!= NULL){
        line[strlen(line)-1] = '\0';
        strcpy(tracks[len].title, strtok(line, ";"));
        tracks[len].length = atoi(strtok(NULL, ";"));
        tracks[len].plays = atoi(strtok(NULL, ";"));
        len++;
    }


fclose(input);
qsort(tracks, len, sizeof(TRACK), cmp);

if(argc == 2)
{
    fprintf(stderr, "The is no file to write into");
    return 3;
}
input = fopen(argv[2], "w");
if(!input)
{
    fprintf(stderr, "This file cannot be opened");
    return 4;
}
for(int i=0; i< len;i++)
{
    char name[20];
    char song[20];
    strcpy(name, strtok(tracks[i].title, "-"));
    strcpy(song, strtok(NULL, "-"));
    fprintf(input,"%s;%s;%d;%d\n", name, song,tracks[i].length, tracks[i].plays);
}
fclose(input);


    return EXIT_SUCCESS;
}