#include <stdio.h>

float hor, val, sal, inss;

int main()
{
    while (1)
    {
        printf("Enter the number of monthly hours worked: ");
        scanf("%f", &hor);
        printf("Enter the hour value: ");
        scanf("%f", &val);
        sal = hor * val;
        printf("The gross salary is %.2f \n", sal);

        /* solução inteligente, a qual não usa estruturas condicionais
        encadeadas mas sim o auxílio de operadores lógicos. */
        if (sal <= 1412)
            inss = sal * 0.075;

        if (sal >= 1412.01 && sal <= 2666.68)
            inss = 1412 * 0.075 + (sal - 1412) * 0.09;

        if (sal >= 2666.69 && sal <= 4000.03)
            inss = 1412 * 0.075 + 1254.67 * 0.09 + (sal - 2666.68) * 0.12;

        if (sal >= 4000.04 && sal <= 7786.02)
            inss = 1412 * 0.075 + 1254.67 * 0.09 + 1333.34 * 0.12 + (sal - 4000.03) * 0.14;

        if (sal > 7786.02)
            inss = 1412 * 0.075 + 1254.67 * 0.09 + 1333.34 * 0.12 + 3785.98 * 0.14;
        /* existe um teto, independente de qualquer salário acima de R$ 7786,02. */

        printf("The INSS discount is %.2f\n", inss);
    }
    return 0;
}