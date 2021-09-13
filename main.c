#include "stdio.h"
#include "qesolver.h"
#include "unitests.h"

#define UNITEST

int main() {

#ifdef UNITEST
    solver_test();
#endif

#ifndef UNITEST
    puts("Quadratic equasion solver.");
    puts("(c) Egor Osipov.");
    puts("Enter a, b, c coefficients:");

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    get_coefficients(&a, &b, &c);

    int RootsNumber = Solver(a, b, c, &x1, &x2);

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
#endif // UNITEST

    return 0;
}
