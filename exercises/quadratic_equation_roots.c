#include <stdio.h>
#include <math.h>

float a, b, c, d, r_1, r_2, real, imag;

int main()
{
    while(1){
        /*
        calculates roots of the quadratic equation ax^2 +bx +c = 0
        */
        printf("Enter the coefficient a: ");
        if (scanf("%f", &a) == 0)
        {
            printf("Not a numeric type!");
            return 0;
        };

        printf("Enter the coefficient b: ");
        if (scanf("%f", &b) == 0)
        {
            printf("Not a numeric type!");
            return 0;
        };

        printf("Enter the coefficient c: ");
        if (scanf("%f", &c) == 0)
        {
            printf("Not a numeric type!");
            return 0;
        };

        d = pow(b, 2) - 4 * a * c;
        if (d < 0)
        {
            real = -b / (2 * a);
            imag = sqrt(-d) / (2 * a);
            printf("Root 1 is: %.2f +j%.2f\a\n", real, imag);
            printf("Root 2 is: %.2f -j%.2f\a\n", real, imag);
        }
        else
        {
            r_1 = (-b + sqrt(d)) / (2 * a);
            r_2 = (-b - sqrt(d)) / (2 * a);
            printf("Root 1 is: %.2f\a\n", r_1);
            printf("Root 2 is: %.2f\a\n", r_2);
        }
    }
}