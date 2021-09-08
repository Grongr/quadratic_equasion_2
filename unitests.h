#ifndef UNTITESTS_INCLUDED
#define UNTITESTS_INCLUDED

#include "stdio.h"

#define TEST(num, a, b, c, x1, x2, scount)                      \
{                                                               \
    double xx1 = 0, xx2 = 0;                                    \
    int count = Solver(a, b, c, &xx1, &xx2);                    \
    if ((xx1 != x1 || xx2 != x2) && count != 0)                 \
        return num;                                             \
    else if (count != scount)                                   \
        return num;                                             \
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
