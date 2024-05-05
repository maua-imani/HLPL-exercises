#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    char city[31];
    int runways;
    int time;
}AIRPORTS;

int cmp(const void * a, const void * b)
{
    AIRPORTS * left = (AIRPORTS *)a;
    AIRPORTS * right = (AIRPORTS *)b;

    if(left -> runways != right -> runways){
        return -(left -> runways - right -> runways);
    }
    if(left -> time != right -> time)
    {
        return -(left -> time - right -> time);
    }
    return strcmp(left->name, right -> name);

}


int main()
{
    char line[102];
    AIRPORTS airport[20];
    int len = 0;

    while(1)
    {
        fgets(line, sizeof(line), stdin);
        line[strlen(line)-1] = '\0';
        if(strcmp(line, "END")== 0){
            
            break;
            
        }
        strcpy(airport[len].name, strtok(line, ";"));
        strcpy(airport[len].city, strtok(NULL, ";"));
        airport[len].runways = atoi(strtok(NULL, ";"));
        airport[len].time = atoi(strtok(NULL,";"));
        len++;   
    }

    qsort(airport, len, sizeof(AIRPORTS), cmp);
          
          
    for(int i = 0; i< len; i++)
        {
            printf("%s (%s) %d\n", airport[i].name, airport[i].city, airport[i].time);
        }
    return EXIT_SUCCESS;
}
