#ifndef QESOLVER_INCLUDED
#define QESOLVER_INCLUDED

#define epsilon 1e-7 //< Uses in dcmp to compare doubles
#define INFINITE_NUMBER_OF_ROOTS 3

/*!
 * @brief Quadratic equasion solver
 *
 * Not as simple function to solve quadratic equasion
 * if <DEBUG> is defined it does some input
 * checks. Also it has checks for many cases of
 * solutions.
 *
 * @param [in] <a>  first coefficient, it sould be zero
 * @param [in] <b>  second coefficient, it sould be zero
 * @param [in] <c>  therd coefficient, it sould be zero
 * @param [in] <x1> pointer to the first ans
 * @param [in] <x2> pointer to the second ans
 *
 * @return number of solutions
 *
 * @version 0.1
 */
int Solver(double a, double b, double c,
           double* x1, double *x2);

/*!
 * @brief Safely gets coefficients
 *
 * Checks if coefficients are finite and
 * input method is correct
 *
 * @param [in] <a> Pointer to the first coef
 * @param [in] <b> Pointer to the second coef
 * @param [in] <c> Pointer to the therd coef
 *
 * @version 0.1
 */
void get_coefficients(double* a, double* b, double* c);

/*!
 * @brief Compare doubles...
 *
 * Uses defined in the beginning qesort.h 
 * <epsilon> to compare two double numbers
 *
 * @param [in] <a> First number to compare
 * @param [in] <b> Second number to compare
 *
 * @return (-1 if a is less then b,
 *          0 if equal, 1 if bigger and
 *          3 if there was an error)
 */
int dcmp(double a, double b);

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
char infinite_solutions(double a, double b, double c);

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
char is_linear(double a, double b);

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
char zero_roots(double a, double b, double c);

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
char zero_b_solution(double a, double b, double c);

/*!
 * @brief Swap function
 *
 * It swaps two double variables
 *
 * @param [out] <a> first number to swap
 * @param [out] <b> second number to swap
 *
 * @version 0.1
 */
void swap(double* a, double* b);

#endif // QESOLVER_INCLUDED
