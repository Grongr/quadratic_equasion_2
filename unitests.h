#ifndef UNTITESTS_INCLUDED
#define UNTITESTS_INCLUDED

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
int solver_test();

/*!
 * @brief Checks if test is passed correctly
 *
 * Depends on coefs a, b and c solves quadratic equation
 * and then compare answere to correct (x1, x2, scount)
 *
 * @prarm [in] <num>    Number of test
 * @param [in] <a>      First coefficient
 * @param [in] <b>      Second coefficient
 * @param [in] <c>      Therd coefficient
 * @param [in] <x1>     First correct answere
 * @param [in] <x2>     Second correct answere
 * @prarm [in] <scount> Correct number of roots
 *
 * @return 0 if test is passed, <num> if not
 *
 * @version 0.1
 */
int is_correct(int num, double a, double b, double c,
               double x1, double x2, int scount);

#endif // UNTITESTS_INCLUDED
