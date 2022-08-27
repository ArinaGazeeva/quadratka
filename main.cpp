#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "quadratka.h"
#include "test.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int answer = 1;

    do
    {
        if (answer == 1 || answer == 2 || answer == 3)
        {
            printf("If you want to solve your equation, write '1'\n" \
                    "if you want to start testing, write '2'\n"\
                    "if you want to stop the program, write '3'\n");
        }

        answer = check_input();

        if (answer == 1)
        {
            printf("Enter the coefficient a\n");
            a = check_input();
            printf("Enter the coefficient b\n");
            b = check_input();
            printf("Enter the coefficient c\n");
            c = check_input();

            int roots = counting_roots(a, b, c, &x1, &x2);

            output(roots, x1, x2);
        }
        else if (answer == 2)
        {
            testing_counting_roots();
            testing_linear();
        }

        if (answer != 1 && answer != 2 && answer != 3)
            printf("Input error\n");



    } while (answer != 3);

    printf("Thanks for using!");

    return 0;
}
