#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "quadratka.h"
#include "test.h"

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

    for (int i = 0; i < 11; i++)
    {
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        a = test_counting_roots[i][0];
        b = test_counting_roots[i][1];
        c = test_counting_roots[i][2];
        int rightRoots = test_counting_roots[i][3];
        double rightX1 = test_counting_roots[i][4];
        double rightX2 = test_counting_roots[i][5];

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
