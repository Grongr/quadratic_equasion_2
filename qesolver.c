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

/*!
 * @brief If one of solutions is -0.
 *
 * It swaps coefficients so that x1 is less then x2 in
 * the end. If one of the solutions is -0, it becomes
 * 0.0.
 *
 * @param [out] <x1> Pointer to the first solution
 * @param [out] <x2> Pointer to the second solution
 *
 * @version 0.1
 */
static void minus_zero(double* x1, double *x2);


enum NumberOfRoots Solver(double a, double b, double c, double *x1, double *x2) {

    assert(x1 != NULL);
    assert(x2 != NULL);

    assert(x1 != x2 && "Pointers <x1> and <x2> are the same");

    if (infinite_solutions(a, b, c))
        return INFINITE_NUMBER_OF_ROOTS;

    if (is_linear(a, b)) {

        *x1 = -c / b;
        return ONE_SOLUTION;

    }

    if (zero_b_solution(a, b, c)) {

        *x1 = sqrt(-c / a);
        return ONE_SOLUTION;

    }

    if (zero_roots(a, b, c))
        return ZERO_SOLUTIONS;

    assert(isfinite(b * b) && "Too big or too small b value");
    assert(isfinite(4 * a * c) && "Too big or too small a or c value");

    double D = b * b - 4 * a * c;

    if (dcmp(D, 0.0) == -1)
        return ZERO_SOLUTIONS;
    
    double sqrtD = sqrt(D);

    *x1 = (-b - sqrtD) / 2 / a;

    if (dcmp(D, 0.0) == 0)
        return ONE_SOLUTION;

    *x2 = (-b + sqrtD) / 2 / a;

    minus_zero(x1, x2);

    return TWO_SOLUTIONS;
}

void print_answere(int RootsNumber, double x1, double x2) {

    switch (RootsNumber) {

        case ZERO_SOLUTIONS:
            printf("There are no roots :(\n");
        break;

        case ONE_SOLUTION:
            printf("There is only one answere: %.6lg\n", x1);
        break;

        case TWO_SOLUTIONS:
            printf("Answeres:\n%.6lg %.6lg\n", x1, x2);
        break;

        case INFINITE_NUMBER_OF_ROOTS:
            puts("Infinite number of roots :)");
        break;

        default:
            puts("Something went wrong, could not find, what happened");
        break;
    }

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

static void minus_zero(double* x1, double* x2) {

    *x1 = (dcmp(*x1, 0.0)) ? *x1 : 0.0;
    *x2 = (dcmp(*x2, 0.0)) ? *x2 : 0.0;
    
    if (dcmp(*x1, *x2) == 1) {

        double temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }

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
