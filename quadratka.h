/// all possible variants of the number of roots of the quadratic equation
enum nRoots {
    NO_ROOTS,               ///< no one root
    ONE_ROOT,               ///< one root
    TWO_ROOTS,              ///< two roots
    INFIFNITY_ROOTS = -1    ///< infinity number of roots
};

/**
 * \brief - checks if parameters are equal
 *
 * \param [in] a, b checked numbers
 *
 * \return true if equal false if not
 *
 * \note inaccuracy is 1e-4
 */
bool check_equality(const double a, const double b);

/**
 * \brief - count roots of quadratic equation and find them
 *
 * \param [in] a - x^2 coefficient
 * \param [in] b - x   coefficient
 * \param [in] c - free term
 * \param [out] x1 - 1 st root of quadratic equation
 * \param [out] x2 - 2 st root of quadratic equation
 *
 * \return number of roots
 *
 * \note equation a * x^2 + b * x + c = 0
 */
int counting_roots(double a, double b, double c, double* x1, double* x2);

/**
 * \brief - outputs the results of solving the equation
 *
 * \param [in] roots - number of roots
 * \param [in] x1 - 1 st root of quadratic equation
 * \param [in] x2 - 2 st root of quadratic equation
 *
 * \note equation a * x^2 + b * x + c = 0
 */
void output(const int roots, const double x1, const double x2);

/**
 * \brief - count roots of linear equation and find them
 *
 * \param [in] b - x^1 coefficient
 * \param [in] c - x^0 coefficient
 * \param [out] x1 - 1 st root of equation
 * \param [out] x2 - 2 st root of equation
 *
 * \return number of roots
 *
 * \note equation b * x + c = 0 (a = 0)
 */
int linear_equation(const double b, const double c, double* const x1, double* const x2);

/**
 * \brief - checks correctness of input
 *
 * \return input - right value
 *
 * \note allows you to enter only the correct values, else it outputs an error
 */
double check_input();
