#include "qesolver.h"
#include "assert.h"
#include "stdio.h"
#include "math.h"

#define DEBUG //< Define this if you are not sure all is ok


int Solver(double a, double b, double c, double *x1, double *x2) {

    assert(x1 != NULL);
    assert(x2 != NULL);

    assert(x1 != x2 && "Pointers <x1> and <x2> are the same");

    assert(isfinite(b * b) && "Too big or too small b value");
    assert(isfinite(4 * a * c) && "Too big or too small b value");

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

    double D = b * b - 4 * a * c;

    if (dcmp(D, 0.0) == -1)
        return 0;
    
    double sqrtD = sqrt(D);

    *x1 = (-b + sqrtD) / 2 / a;

    if (dcmp(D, 0.0) == 0)
        return 1;

    *x2 = (-b - sqrtD) / 2 / a;

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

}

int dcmp(double a, double b) {

    if (fabs(a - b) <= epsilon)
        return 0;
    else if (b + epsilon < a)
        return 1;
    else if (b - epsilon > a)
        return -1;

    return 3;
}

char is_linear(double a, double b) {

    if (!dcmp(a, 0.0) && dcmp(b, 0.0))
        return 1;
    else
        return 0;
}

char zero_roots(double a, double b, double c) {

    if (dcmp(a, 0.0) == 0 && dcmp(b, 0.0) == 0 && dcmp(c, 0.0) != 0)
        return 1;
    else
        return 0;
}

char zero_b_solution(double a, double b, double c) {

    if (dcmp(b, 0.0) == 0 && dcmp(a, 0.0) != 0 && dcmp(c, 0.0) == -1)
        return 1;
    else
        return 0;
}

char infinite_solutions(double a, double b, double c) {

    if (dcmp(a, 0.0) == 0 && dcmp(b, 0.0) == 0 && dcmp(c, 0.0) == 0)
        return 1;
    else
        return 0;
}
