#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "quadratka.h"

int counting_roots(const double a, const double b, const double c, double* const x1, double* const x2)
{
    double D = 0;

    if (check_equality(a, 0))
        return linear_equation(b, c, x1, x2);

    D = b*b - 4*a*c;

    if (D < 0)
        return NO_ROOTS;

    else if (check_equality(D, 0))
    {
        *x1 = -b/(2*a);
        *x2 = *x1;
        return ONE_ROOT;
    }

    else if (D > 0)
    {
        D = sqrt(D);
        *x1 = (-b + D)/(2 * a);
        *x2 = (-b - D)/(2 * a);
        if (*x2 > *x1)
        {
            double h = *x1;
            *x1 = *x2;
            *x2 = h;
        }
        return TWO_ROOTS;
    }
}

bool check_equality(const double a, const double b)
{
    const double inaccuracy = 1e-4;

    return fabs(a - b) < inaccuracy;
}

void output(const int roots, const double x1, const double x2)
{
    switch(roots)
        {
        case NO_ROOTS :
            printf("There are no solutions\n");
            break;

        case ONE_ROOT :
            printf("There is one solution: %lf\n", x1);
            break;

        case TWO_ROOTS :
            printf("There are two solutions: %lf, %lf\n", x1, x2);
            break;

        case INFIFNITY_ROOTS :
            printf("Infinite number of roots\n");
            break;

        default:
            assert(0 && "Undefined behavior");
        }
}

int linear_equation(const double b, const double c, double* const x1, double* const x2)
{
    if (check_equality(b, 0))
    {
        if (check_equality(c, 0))
            return INFIFNITY_ROOTS;

        else
            return NO_ROOTS;
    }
    else
    {
        *x1 = -c/b;
        *x2 = -c/b;
        return ONE_ROOT;
    }
}

