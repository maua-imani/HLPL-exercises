#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char city[31];
    int runways;
    int time;
}AIRPORT;
//this is a struct data structure which we have used to define the structure of the information about the airports that we want to store.


int cmp(const void * a, const void * b)
{
    AIRPORT * left = (AIRPORT *)a;
    AIRPORT * right = (AIRPORT *)b;
    if(left -> runways != right -> runways)
    {
        return -(left->runways - right-> runways);
    }

    if(left -> time != right -> time)
    {
        return -(left -> time - right -> time);
    }
    return strcmp(left -> name, right -> name);
}


int main()
{
    char line[101]; //initialize a char variable called line which will store the information from the input - could be from the user or a file.
    int len = atoi(fgets(line, sizeof(line), stdin));//fgets is used to read inputs.
    //the input is in character format therefore we need to change the type of len from string to int using atoi
    AIRPORT airports[len]; // we are declaring an array called airports of type AIRPORT. AIRPORT is a struct that we have defined above.
    for(int i=0; i<len; i++)
    {
        fgets(line,sizeof(line), stdin);
        strcpy(airports[i].name, strtok(line, ";"));
        strcpy(airports[i].city, strtok(NULL, ";"));
        airports[i].runways = atoi(strtok(NULL, ";"));
        airports[i].time = atoi(strtok(NULL, ";"));
    }
    //the for loop reads from the standard input and tokenizes into the respective elements as described in the struct.

    qsort(airports,len, sizeof(AIRPORT), cmp);
    //syntax of qsort is qsort(pointer to the array to be sorted, number of elements in the array, size of elements in the array,)

    for(int i =0; i<len; i++){
        printf("%s (%s): %d\n", airports[i].name, airports[i].city, airports[i].time);
        printf("\n");
    }
    return EXIT_SUCCESS;
}