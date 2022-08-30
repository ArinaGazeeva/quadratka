#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "quadratka.h"
#include "test.h"

// cmd argument
// file reading
int main()
{
    int work_mode = 1;// rename
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    do
    {
        if (work_mode == 1 || work_mode == 2 || work_mode == 3)
        {
            printf("If you want to solve your equation, write '1'\n" \
                    "if you want to start testing, write '2'\n"\
                    "if you want to stop the program, write '3'\n");
        }

        work_mode = check_input();

        if (work_mode == 1)
        {
            a = enter_coefficient('a');
            b = enter_coefficient('b');
            c = enter_coefficient('c');

            int roots = solving_quadratic(a, b, c, &x1, &x2);

            output(roots, x1, x2);
        }
        else if (work_mode == 2)
        {
            testing_solving_quadratic();
            testing_linear();
        }

        if (work_mode != 1 && work_mode != 2 && work_mode != 3)
            printf("Input error\n");



    } while (work_mode != 3);

    printf("Thanks for using!");

    return 0;
}
