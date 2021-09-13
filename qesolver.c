#include "qesolver.h"
#include "stdio.h"
#include "math.h"

/* #define NDEBUG //< define this if if don't want my asserts to work */
#include "assert.h"

#define epsilon 1e-7 //< Uses in dcmp to compare doubles

/*!
 * @brief Checks if equation is linear
 *
 * It is equation if it has a or b coefficient
 * not zero.
 *
 * @param [in] <a> First coef
 * @param [in] <b> Second coef
 *
 * @return 1 if it is linear
 *         and 0 if not
 *
 * @version 0.1
 */
static char is_linear(double a, double b);

/*!
 * @brief Checks if there is no solutions.
 *
 * It checks if there may be solutions
 * based on coefs, not discriminant
 *
 * @param [in] <a> First coef
 * @param [in] <b> Second coef
 * @param [in] <c> Therd coef
 *
 * @return 1 if there is no solutions
 *
 * @version 0.1
 */
static char zero_roots(double a, double b, double c);


/*!
 * @brief Checks if there are more then two roots
 *
 * a, b and c must be zero coefs
 *
 * @param [in] <a> First coef
 * @param [in] <b> Second coef
 * @param [in] <c> Therd coef
 *
 * @return 1 if infinit number
 *         0 if not
 * 
 * @version 0.1
 */
static char infinite_solutions(double a, double b, double c);

/*!
 * @brief Checks if there are solution with zero coef b
 *
 * If b coef is zero c coef must be less than zero
 *
 * @param [in] <a> First coef
 * @param [in] <b> Second coef
 * @param [in] <c> Therd coef
 *
 * @return 1 b is zero and c is less than zero
 *         0 if not
 *
 * @version 0.1
 */
static char zero_b_solution(double a, double b, double c);


int Solver(double a, double b, double c, double *x1, double *x2) {

    assert(x1 != NULL);
    assert(x2 != NULL);

    assert(x1 != x2 && "Pointers <x1> and <x2> are the same");

    int RootsNumber = 0;

    if (infinite_solutions(a, b, c))
        return INFINITE_NUMBER_OF_ROOTS;

    if (is_linear(a, b)) {

        *x1 = -c / b;
        return 1;

    }

    if (zero_b_solution(a, b, c)) {

        *x1 = sqrt(-c / a);
        return 1;

    }

    if (zero_roots(a, b, c))
        return 0;

    assert(isfinite(b * b) && "Too big or too small b value");
    assert(isfinite(4 * a * c) && "Too big or too small a or c value");

    double D = b * b - 4 * a * c;

    if (dcmp(D, 0.0) == -1)
        return 0;
    
    double sqrtD = sqrt(D);

    *x1 = (-b - sqrtD) / 2 / a;

    if (dcmp(D, 0.0) == 0)
        return 1;

    *x2 = (-b + sqrtD) / 2 / a;

    return 2;
}

void get_coefficients(double *a, double *b, double *c) {

    assert(a != b);
    assert(b != c);

    int input_size = scanf("%lg %lg %lg", a, b, c);

    while (input_size != 3) {

        while (getchar() != '\n');

        printf("Wrong input, try again:\n");
        input_size = scanf("%lg %lg %lg", a, b, c);

    }

    assert(isfinite(*a));
    assert(isfinite(*b));
    assert(isfinite(*c));

    if (dcmp(*a, 0.0) == -1) {

        *a *= -1;
        *b *= -1;
        *c *= -1;
    }

}

int dcmp(double a, double b) {

    if (fabs(a - b) <= epsilon)
        return 0;
    else if (b < a)
        return 1;
    else if (b > a)
        return -1;

    return 3;
}

static char is_linear(double a, double b) {

    return (!dcmp(a, 0.0) && dcmp(b, 0.0));
}

static char zero_roots(double a, double b, double c) {

    return (dcmp(a, 0.0) == 0 && dcmp(b, 0.0) == 0 && dcmp(c, 0.0) != 0);
}

static char zero_b_solution(double a, double b, double c) {

    return (dcmp(b, 0.0) == 0 && dcmp(a, 0.0) != 0 && dcmp(c, 0.0) == -1);
}

static char infinite_solutions(double a, double b, double c) {

    return (dcmp(a, 0.0) == 0 && dcmp(b, 0.0) == 0 && dcmp(c, 0.0) == 0);
}

#undef epsilon
