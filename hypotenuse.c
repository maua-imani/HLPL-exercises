 //calculate the hypotenuse of a right triangle given the lengths of its two perpendicular sides

 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>

 float pythagorean(float a, float b){
    return sqrt((a*a)+(b*b));
 }

 int main(){
    float a, b;

    while(scanf("%f %f", &a, &b) != EOF){
        printf("The hypotenuse of this triangle is: %.2lf\n", pythagorean(a, b));
    }

return EXIT_SUCCESS;
 }