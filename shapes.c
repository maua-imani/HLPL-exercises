#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int rectangle_perimeter(int a, int b){
return 2 * (a + b);
}

int rectangle_area(int a,int b){
return a * b;
}

int square_perimeter(int a){
return rectangle_perimeter(a, a);
}

int square_area(int a){
return rectangle_area(a, a);

}

double circumfrence(double r){
return M_PI * 2 * r;

}

double circle_area(double r){
return M_PI * r * r;

}

int main(){
    puts("Enter the sides of a rectange:");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The perimeter of the rectange with sides %d x %d is %d cm\n", a, b, rectangle_perimeter(a, b));
    printf("The area of the rectange with sides %d x %d is %d cm\n", a, b, rectangle_area(a, b));

    puts("====");

    puts("Enter the sides of a square:\n");
    scanf("%d", &a);
    printf("The perimeter of the square with sides %d is %d cm\n", a, square_perimeter(a));
    printf("The area of the square with sides %d is %d cm\n", a, square_area(a));


    puts("====");

    puts("Enter the length of the radius of a circle\n");
    double r;
    scanf("%lf", &r);
    printf("The circumfrence of a cirlce whose radius is %.2lf is %.2lf cm\n", r,circumfrence(r));
    printf("The area of a circle whose radius is %.2lf is %.2lf cm\n", r, circle_area(r));


    return EXIT_SUCCESS;
}