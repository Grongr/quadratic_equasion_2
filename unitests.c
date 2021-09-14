#include "stdio.h"
#include "unitests.h"
#include "qesolver.h"

#define TEST(num, a, b, c, x1, x2, scount) \
    if (is_correct(num, a, b, c, x1, x2, scount)) return num;

int solver_test() {

    //   num   a    b    c   x1    x2                RootsCount
    TEST(1,    0,   0,   0,  0.0,  0.0, INFINITE_NUMBER_OF_ROOTS)
    TEST(2,    1,   1,   1,  0.0,  0.0,                        0)
    TEST(3,    1,   0,   0,  0.0,  0.0,                        1)
    TEST(4,    1,  -5,   6,  2.0,  3.0,                        2)
    TEST(5,    1,   1,   0, -1.0,  0.0,                        2)
    TEST(6,   -1,  -1,   0, -1.0,  0.0,                        2)

    return 0;
}

int is_correct(int num, double a, double b, double c,
               double x1, double x2, int scount) {

    double xx1 = 0, xx2 = 0;
    int count = Solver(a, b, c, &xx1, &xx2);
    if ((dcmp(xx1, x1) != 0 || dcmp(xx2, x2) != 0) && count != 0) {

        printf("In test number %d\n", num);
        printf("It should be <%d>, and it is <%d>\n", scount, count);
        printf("Roots should be: %lg %lg\n", x1, x2);
        printf("Your solution: %lg %lg\n", xx1, xx2);

        return num;
    }
    else if (count != scount) {

        printf("Number of roots are not the same.\n");
        printf("It should be <%d>, but it is <%d>", scount, count);
        return num;
    }
    return 0;
}

#undef TEST
