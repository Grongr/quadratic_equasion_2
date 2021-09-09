#include "stdio.h"
#include "qesolver.h"
#include "unitests.h"

/* #define UNITEST */

int main() {

#ifdef UNITEST
    printf("%d\n", unit_test());
#endif

#ifndef UNITEST
    printf("Quadratic equasion solver.\n");
    printf("(c) Egor Osipov.\n");
    printf("Enter a, b, c coefficients:\n");

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    get_coefficients(&a, &b, &c);

    int RootsNumber = Solver(a, b, c, &x1, &x2);

    switch (RootsNumber) {

        case 0:
            printf("There is no roots :(\n");
        break;

        case 1:
            printf("There is only one answere: %.6lg\n", x1);
        break;

        case 2:
            printf("Answeres:\n%.6lg %.6lg\n", x1, x2);
        break;

        case INFINITE_NUMBER_OF_ROOTS:
            printf("Infinite number of roots :)\n");
    }
#endif // UNITEST

    return 0;
}
