#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char title[41];
    int length;
    int plays;
}TRACKS;

int cmp(const void *a, const void *b)
{
    TRACKS * left = (TRACKS *)a;
    TRACKS * right = (TRACKS *)b;
    if(left->plays != right -> plays)
    {
        return -(left-> plays - right -> plays);
    }
    if(left -> length != right -> length)
    {
        return left -> length - right -> length;
    }
    return (strcmp(left -> title, right -> title));
}

int main()
{
    char line[62];
    TRACKS tracks[20];
    int len = 0;

    while(1)
    {
        fgets(line, sizeof(line), stdin);
        line[strlen(line)-1] ='\0';
        if(strcmp(line,"END")== 0)
        {
            break;
        }
        strcpy(tracks[len].title, strtok(line, ";"));
        tracks[len].length = atoi(strtok(NULL,";"));
        tracks[len].plays = atoi(strtok(NULL, ";"));
        len++;
    }

    qsort(tracks, len, sizeof(TRACKS), cmp);
    for(int i=0; i< len; i++){
        printf("#%d %s: %d (%d)\n", i+1, tracks[i].title, tracks[i].length, tracks[i].plays);

    }
}
