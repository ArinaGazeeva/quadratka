#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "quadratka.h"

int solving_quadratic(const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert((isfinite(a)) || (isfinite(b)) || (isfinite(c)));

    if (check_equality(a, 0))
        return linear_equation(b, c, x1, x2);

    else if (check_equality(b, 0))
        return zero_b(a, c, x1, x2);

    else if (check_equality(c, 0))
        return zero_c(a, b, x1, x2);

    double D = b*b - 4*a*c;

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
    const double INACCURACY = 1e-4;

    return fabs(a - b) < INACCURACY;
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

double check_input()
{
    int check_space = 1;
    char checked_symbol;
    double input = 0;

    int nInput = scanf("%lf", &input); // n -> ???????????? ???? ??????
    while ((checked_symbol = getchar()) and !(checked_symbol == '\n'))
    {
        if (!isspace(checked_symbol))
            check_space = 0;
    }

    if (nInput != 1 || check_space == 0)
    {
        printf("Input error\n");
        input = check_input();
    }

    return input;
}

double enter_coefficient(char name_coef)
{
    printf("Enter the coefficient %c\n", name_coef);
    return check_input();
}

int zero_b(const double a, const double c, double* const x1, double* const x2)
{
    double check_sqrt = (- c) / a;

    if (check_sqrt < 0)
        return NO_ROOTS;

    else if (check_equality(check_sqrt, 0))
    {
        *x1 = 0;
        *x2 = *x1;
        return ONE_ROOT;
    }

    *x1 = sqrt(check_sqrt);
    *x2 = -*x1;
    return TWO_ROOTS;
}

int zero_c(const double a, const double b, double* const x1, double* const x2)
{
    *x1 = 0;
    *x2 = (- b) / a;

    if (*x2 > *x1)
    {
        double h = *x1;
        *x1 = *x2;
        *x2 = h;
    }
    return TWO_ROOTS;
}
