#ifndef QESOLVER_INCLUDED
#define QESOLVER_INCLUDED


enum NumberOfRoots {
    ZERO_SOLUTIONS = 0,             //< Name says all you need
    ONE_SOLUTION   = 1,             //< Name says all you need
    TWO_SOLUTIONS  = 2,             //< Name says all you need
    INFINITE_NUMBER_OF_ROOTS = 3    //< Name says all you need
};

/*!
 * @brief This struct is needed to avoid a lot of
 *        comparations between double coefs.
 * 
 * If coef <name> is zero then <_name> becomes 0,
 * if it is less then <_name> becomes -1 and if
 * it is bigger, then 1. 
 */
struct CoefsZeroCmp {
    int _a; //< Param for <a> coef
    int _b; //< Param for <b> coef
    int _c; //< Param for <c> coef
};

typedef struct CoefsZeroCmp CoefsZeroCmp;

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
enum NumberOfRoots Solver(double a, double b, double c,
                          double* x1, double *x2);

/*!
 * @brief Prints answere in normal way
 *
 * In case how many solutions there are,
 * prints answere. x1 < x2
 *
 * @param [in] <RootsNumber> number of roots (check
 *                           NumberOfRoots enum)
 * @param [in] <x1>          first solution
 * @param [in] <x2>          second solution
 */
void print_answere(enum NumberOfRoots RootsNumber, double x1, double x2);

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
