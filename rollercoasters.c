#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
char name[31];
char world[31];
int height;
int time;

}COASTER;

int cmp(const void *a, const void *b){
COASTER * left = (COASTER *) a;
COASTER * right = (COASTER *) b;

if(left -> time != right -> time){
    return left -> time - right -> time;
}
if(left -> height != right -> height){
    return -(left -> height - right ->height);
}

return strcmp(left->name, right->name);
}

int main(int argc, char *argv[]){
    if(argc == 1){ //This means that there is no input file added.
        fprintf(stderr, "Argument is missing.\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r"); //open a file for reading. This returns a pointer called FILE, so rename it to something user friendly
    if(!input ){ //==NULL - this means that the file cannot be opened.
    fprintf(stderr, "The file cannot be opened.\n"); //print the error message to the stderr error channel
    //
    return 2;
    }
    char line[102];
    COASTER coasters[20];
    int length = 0;
    while(fgets(line,sizeof(line), input))
    { //fgets reads the line upto \n therefore it reads one more character than gets
        line[strlen(line)-1]= '\0';
        strcpy(coasters[length].name, strtok(line, ";"));
        strcpy(coasters[length].world, strtok(NULL, ";"));
        coasters[length].height = atoi(strtok(NULL, ";"));
        coasters[length].time = atoi(strtok(NULL, ";"));
        length++;

    }

    fclose(input); //You have to close the file after you are done reading and manipulating it.

    qsort(coasters, length, sizeof(COASTER), cmp);


    if(argc == 2)
    {
        fprintf(stderr, "The second argument is missing.\n");
        return 3;
    }
    input = fopen(argv[2], "w");
    if(!input)
    {
        fprintf(stderr, "File cannot be opened.\n");
        return 4;
    }
    for(int i=0; i<length; i++)
    {
        fprintf(input,"%s (%s): %d\n", coasters[i].name, coasters[i].world, coasters[i].time);
    }
    fclose(input);
    return EXIT_SUCCESS;
}