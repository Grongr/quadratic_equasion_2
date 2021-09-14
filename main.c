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

    print_answere(RootsNumber, x1, x2);
#endif // UNITEST

    return 0;
}
