#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "quadratka.h"
#include "test.h"
// static
static const double test_solving_quadratic[][6] =     // a b c nRoots x1 x2
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
    {465, -45, 463, 0, 0, 0}
};

static const double test_linear[][5] =             // b c nRoots x1 x2
{
    {23, 526, 1, -22.8695, -22.8695},
    {0, 0, -1, 0, 0},
    {0, 84576, 0, 0, 0},
    {-5, 0, 1, 0, 0},
    {4, -100, 1, 25, 25}

}; // const

void testing_linear()
{
    int counter = 0;
    int nTest = sizeof(test_linear)/sizeof(test_linear[0]);

    for (int test = 0; test < nTest; test++)
    {
        double b = 0, c = 0, x1 = 0, x2 = 0;

        b = test_linear[test][0];
        c = test_linear[test][1];
        int rightRoots = test_linear[test][2];
        double rightX1 = test_linear[test][3];
        double rightX2 = test_linear[test][4];

        int roots = linear_equation(b, c, &x1, &x2);

        if (!(check_equality(roots, rightRoots) && check_equality(x1, rightX1) && check_equality(x2, rightX2)))
        {
            counter++;
            printf("ERROR: Number of roots = %d, x1 = %lf, x2 = %lf\n" "Expected: Number of roots = %d, x1 = %lf, x2 = %lf\n", \
            roots, x1, x2, rightRoots, rightX1, rightX2);
        }
    }

    printf("Number of incorrect answers in 'testing_linear' is %d / %d\n", counter, nTest);
}


void testing_solving_quadratic()
{
    int counter = 0;
    int nTest = sizeof(test_solving_quadratic)/sizeof(test_solving_quadratic[0]);

    for (int test = 0; test < nTest; test++)
    {
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        a = test_solving_quadratic[test][0];
        b = test_solving_quadratic[test][1];
        c = test_solving_quadratic[test][2];
        int rightRoots = test_solving_quadratic[test][3];
        double rightX1 = test_solving_quadratic[test][4];
        double rightX2 = test_solving_quadratic[test][5];

        int roots = solving_quadratic(a, b, c, &x1, &x2);

        if (!(check_equality(roots, rightRoots) && check_equality(x1, rightX1) && check_equality(x2, rightX2)))
        {
            counter++;
            printf("ERROR: Number of roots = %d, x1 = %lf, x2 = %lf\n" "Expected: Number of roots = %d, x1 = %lf, x2 = %lf\n", \
            roots, x1, x2, rightRoots, rightX1, rightX2);
        }
    }
    printf("Number of incorrect answers in 'testing_counting_roots' is %d / %d\n", counter, nTest);
}
