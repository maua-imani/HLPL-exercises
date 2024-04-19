//Write a program that reads input for the user and for any digit, doubles it. The user should be able to continue entering data
//until they input "END"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//A few things to note about this function:
//- This function returns a character array that takes a character array as an argument
//-Since we want to duplicate the digits, we have to assign memory dynamically.
//-When you assign memory dynamically, you always have to use pointers.
//-Assigning memory dynamically means that we are assigning memory at runtime and therefore we are also responsible for freeing up the memory afterwards.
//-Think of this function as a function that is building a whole new character array from scratch, because that is what it is literally doing.

char * double_digits(char * original){
    int len = strlen(original); 
    //len takes the length of the array that will be passed here/
    //Remember that we are building the array from scratch, but based on the length of the array that will be passed here.
    char * result = (char *)calloc((len*2)+1, sizeof(char));
    //this is a very important line of code.
    //This is where we are assigning memory dynamically. We want to duplicate digits, rights? so in the event that every input
    //for 100 characters is a digit and requires to be doubled, we are gonna need double the size of the original array
    //that is why we have (len*2), another point to remember is that we have to account for the null terminating character hence the +1
    //calloc takes two arguments calloc(number of elements, size of elements)
    int pos=0;
    //this is going to be the index for the new array that we are building.
    for(int i=0; i<len;i++){
    //loop through the original array
        if(isdigit(original[i])){//if the element in the original array is a digit, print it
            result[pos++]=original[i];
        }
        result[pos++]=original[i];//whether or not the element is a digit, print it. In this way, we have doubled the digits
    }

    result[pos++] = '\0';//At the end of the array, add a null terminating character
    //Watch Jenny's Lectures on Strings to better ubderstand this concept.

    return result; //return your resulting character array. Return control to main.
}


int main(){
while(1){
    char line[101]; 
    //initialize a character array that takes up to 100 characters. Remember that you also have to account for the null terminating character.
    fgets(line, sizeof(line), stdin);
    //read the line from the user infinitely
    if(strcmp(line, "END\n")==0){
        break;
    }
    //This is the looping condition that is used to break out of the infinite loop. If you enter END, then you leave the loop. Again, you have to account for the null terminating character

    char * final = double_digits(line);//it is at this point that the program shifts control to the other function.
    //initialize a character array that will store the result from double_digits()
    puts(final);//print out the resulting string
    free(final);//remember to free memory
}
}