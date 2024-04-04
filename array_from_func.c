#include <stdio.h>
#include <stdlib.h>


int *assignValues(){
    //C does not allow you to return an array from a function, but you can return a pointer to an array.
    static int tens[10];
    //Static variables have the property of preserving their value even after they are out of their scope, and thet
    //are not initialized again in their new scope.
    //C does not allow to return the address of a local variable outside of the function, so you would havr to define the local 
    //variable as a static variable so that it can be executed in the main function

    for(int i =0; i<10; i++){
        tens[i]= i*10;
    }
    return tens;

}


int main(){
    int *p; //pointer to an integer variable
    p = assignValues(); //We have assigned p to assignValues()
                        //This means that the pointer p now points to the value returned by the function assignValues, not the 
                        //function itself.
    for(int i = 0; i < 10; i++){
        printf("*(p +%d): %d\n", i, *(p+i));
    }
//*(p+i) returns the values stored at the memory address *(p+i). 
//This format means p + (ix(size of the data type p points to)).
    return EXIT_SUCCESS;
}