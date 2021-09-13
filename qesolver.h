#ifndef QESOLVER_INCLUDED
#define QESOLVER_INCLUDED

#define INFINITE_NUMBER_OF_ROOTS 3

/*!
 * @brief Quadratic equasion solver
 *
 * Not as simple function to solve quadratic equasion
 * Also it has checks for many cases of
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

#endif // QESOLVER_INCLUDED
