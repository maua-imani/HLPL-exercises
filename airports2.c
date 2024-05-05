#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct //define the structure to store the information about airports.
{
    char name[31];
    char city[31];
    int runway;
    int time;
}AIRPORTS;

int cmp(const void *a, const void *b){
    AIRPORTS * left = (AIRPORTS *) a;
    AIRPORTS * right = (AIRPORTS *) b;
    if(left -> runway != right -> runway){
        return -(left -> runway - right -> runway);
    }
    if(left -> time != right -> time)
    {
        return -(left -> time - right -> time);
    }
    return (strcmp(left -> name, right -> name));

/*This function does not care so much about the actual value being returned but rather about the value of the  number ie
whether it is -ve, +ve, or 0. If it is -ve, it means that the left element is less than the right element, and vice versa if the 
returned value is +ve. If the returned value is 0, it means that the left and the right values are the same. However the if
statement clearly defines that the  sorting should only be done if left and right are not same.*/
}

int main()
{
    char line[102]; //this is a line from the user which will contain the data we need
    AIRPORTS airports[20]; //using the defined struct AIRPORT which now acts as a data type of type struct (instead of having to type typedef struct everytime)
    //this means that we will have information for at most 20 airports.
    int len = 0;
    //len plays a dual role: it acts as an index for us to access the structs, and also keeps track of the number of structs added to the program.
    while(fgets(line, sizeof(line), stdin)!= NULL){
        line[strlen(line)-1] = '\0'; //fgets read upto a \n character. Replace it with a null terminating character.
        strcpy(airports[len].name, strtok(line, ";"));
        strcpy(airports[len].city, strtok(NULL, ";"));
        airports[len].runway = atoi(strtok(NULL, ";"));
        airports[len].time = atoi(strtok(NULL, ";"));
        len++;
    }

    qsort(airports,len,sizeof(AIRPORTS), cmp);

    for(int i =0; i<len; i++){
        printf("%s (%s): %d\n", airports[i].name, airports[i].city, airports[i].time);
        printf("\n");
    }
    return EXIT_SUCCESS;
}