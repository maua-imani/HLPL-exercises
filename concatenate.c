#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    

 //Notes on string concatenation - with strcat()
//-Concatenation means that you append S1 and S2
//-Basically, we are appending a copy of one string to another.
//-The string that is being appended to must be big enough to accomodate the second one.
//- the syntax is strcat(s1, s2)
//-The first string is the string being appended to.
//-To use strcat(), we need to use the header file string.h which has strcat() described
//-The problem with strcat() is that it does not check the size of s1 before it performs the concatenation.
//-You can also, as a third argument of strcat(),add how many characters of s2 you wish to concatenate to s1.

//char s1[30]="Jenny";
//char s2[7]= "Khatri";
//strcat(s1, s2);
//printf("%s", s1);

//WITHOUT strcat()
int len1, len2;
char s1[30]="Jenny";
char s2[7]= "Khatri";
len1 = strlen(s1);
len2 = strlen(s2);

for(int i =0; i<=len2;i++){
    s1[len1+i]=s2[i];
    //Here, we are adding the characters in s2 to s1, one by one.
    //the first character of s2, ie 'K' is added where the newline character of s1 is.
    //that means length of Jenny ie 5+index of k, ie 0 5+0 is 5
    //therefore, k is concatenated at index 5.
    //the next character at index 1 is added at 5+1=6 
}
printf("%s", s1);
}