#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "quadratka.h"

double test_counting_roots[11][6] =     // a b c nRoots x1 x2
{
    {1, 2, 1, 1, -1, -1},
    {1, 0, -4, 2, 2, -2},
    {0, 23, 526, 1, -22.8695, -22.8695},
    {0, 0, 0, -1, 0, 0},
    {0, 0, 999, 0, 0, 0},
    {5, 43, -4, 2, 0.0920, -8.6920},
    {25, 43, 555, 0, 0, 0},
    {25, -2552, 0, 2, 102.08, 0},
    {25, 2552, 0, 2, 0, -102.08},
    {1, 4, 4, 1, -2,-2},
    {465, -45, 463, 0, 0, 0},
};

double test_linear[5][5] =             // b c nRoots x1 x2
{
    {23, 526, 1, -22.8695, -22.8695},
    {0, 0, -1, 0, 0},
    {0, 84576, 0, 0, 0},
    {-5, 0, 1, 0, 0},
    {4, -100, 1, 25, 25}

};

/**
 * \brief - test function 'counting_roots'
 *
 * \note display errors on tests and number of errors
 */
void testing_counting_roots();

/**
 * \brief - test function 'linear_equation'
 *
 * \note display errors on tests and number of errors
 */
void testing_linear();

/**
 * \brief - checks correctness of input
 *
 * \return input - right value
 *
 * \note allows you to enter only the correct values, else it outputs an error
 */
double check_input();


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



void testing_linear()
{
    int counter = 0;

    for (int i = 0; i < 5; i++)
    {
        double b = 0, c = 0, x1 = 0, x2 = 0;

        b = test_linear[i][0];
        c = test_linear[i][1];
        int rightRoots = test_linear[i][2];
        double rightX1 = test_linear[i][3];
        double rightX2 = test_linear[i][4];

        int roots = linear_equation(b, c, &x1, &x2);

        if (!(check_equality(roots, rightRoots) && check_equality(x1, rightX1) && check_equality(x2, rightX2)))
        {
            counter++;
            printf("ERROR: Number of roots = %d, x1 = %lf, x2 = %lf\n" "Expected: Number of roots = %d, x1 = %lf, x2 = %lf\n", \
            roots, x1, x2, rightRoots, rightX1, rightX2);
        }
    }

    printf("Number of incorrect answers in 'testing_linear' is %d / 5\n", counter);
}


void testing_counting_roots()
{
    int counter = 0;

    for (int i = 0; i < 11; i++)    //sizeof(test)/(sizeof(double)*6)
    {
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        a = test_counting_roots[i][0];
        b = test_counting_roots[i][1];
        c = test_counting_roots[i][2];
        int rightRoots = test_counting_roots[i][3];
        double rightX1 = test_counting_roots[i][4];
        double rightX2 = test_counting_roots[i][5];

        /*printf("%lg %lg", rightX1, rightX2);

        printf("\n-----------\na=%lg\nb=%lg\nc=%lg\n", a,b,c);
        */

        int roots = counting_roots(a, b, c, &x1, &x2);

        if (!(check_equality(roots, rightRoots) && check_equality(x1, rightX1) && check_equality(x2, rightX2)))
        {
            counter++;
            printf("ERROR: Number of roots = %d, x1 = %lf, x2 = %lf\n" "Expected: Number of roots = %d, x1 = %lf, x2 = %lf\n", \
            roots, x1, x2, rightRoots, rightX1, rightX2);
        }
    }

    printf("Number of incorrect answers in 'testing_counting_roots' is %d / 11\n", counter);
}


double check_input()
{
    int flag = 1;
    char c = 'a';
    double input = 0;

    int n = scanf("%lf", &input);
    while ((c = getchar()) and !(c == '\n'))
    {
        if (!isspace(c))
            flag = 0;
    }
    if (n != 1 || flag == 0)
    {
        printf("Input error\n");
        input = check_input();
    }
    return input;
}