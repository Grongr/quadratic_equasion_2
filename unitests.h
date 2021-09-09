#ifndef UNTITESTS_INCLUDED
#define UNTITESTS_INCLUDED

#include "stdio.h"

#define TEST(num, a, b, c, x1, x2, scount)                           \
{                                                                    \
    double xx1 = 0, xx2 = 0;                                         \
    int count = Solver(a, b, c, &xx1, &xx2);                         \
    if ((xx1 != x1 || xx2 != x2) && count != 0) {                    \
                                                                     \
        printf("It should be <%d>, and it is <%d>", scount, count);  \
        printf("Roots should be: %lg %lg\n", x1, x2);                \
        printf("Your solution: %lg %lg\n", xx1, xx2);                \
                                                                     \
        return num;                                                  \
    }                                                                \
    else if (count != scount) {                                      \
                                                                     \
        printf("Number of roots are not the same.\n");               \
        printf("It should be <%d>, but it is <%d>", scount, count);  \
        return num;                                                  \
    }                                                                \
}

/*!
 * @brief Unit tests for quadratic equation
 *
 * This func checks if solutions of some
 * simple quadratic equation are correct.
 * Checks boundary values:
 * 0 0  0
 * 0 b  c
 * a 0  c
 * a 0 -c
 * a b  0
 * - and some examples without solution.
 * 
 * @return number of test, which failed
 *
 * @version 0.1
 * @authors Egor Osipov
 */
int unit_test();

#endif // UNTITESTS_INCLUDED
