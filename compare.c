#include <stdio.h>
#include <string.h>

int main(){


    //WITH STRCMP
    //strcmp compares two strings character by character to check if they are similar ie lexical comparison
    //ensure you use string.h header file to describe strcmp to the compiler.
    //SYNTAX:
    //strcmp(const char *str1, const char *str2)
    //strcmp returns an integer value 
    //0 if the strings are the same
    //+ve if the the first differing character in the first string has a higher ASCII value than the character in the second
    //string
    //-ve if the first differing character in the second string has a lower ASCII value than the character in the second string.
    //change te values of s1 and s2 to see the difference
    //int value;
    //char s1[]= "Hello";
    //char s2[]= "Hello";   
    //value = strcmp(s1, s2);
    //printf("%d", value);

    //WITHOUT STRCMP
    

    int flag = 0;
    char s1[] = "Hello";
    char s2[] = "Hi";

    for(int i=0; s1[i]!= '\0'||s2[i]!='\0';i++){
        if(s1[i]!=s2[i]){
            flag =1;
            break;
        }
    }

    if(flag == 1){
        printf("Not same");
    }



}