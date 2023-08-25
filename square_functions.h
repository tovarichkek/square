#pragma once

//Enums---------------------------------------------------------------

/**
    * Count of roots in equations
 */
enum COUNT_OF_ROOTS {
    INVALID = -2, ///-2
    INFINITY_OF_ROOTS = -1, ///-1
    NO_ROOTS = 0, ///0
    ONE_ROOT = 1, ///1
    TWO_ROOTS = 2, ///2
    THREE_ROOTS = 3, ///3
    FORE_ROOTS = 4, ///4
    FIVE_ROOTS = 5, ///5
};

/**
    * Enum for compare()
 */
enum COMPARISON{
    MORE = 1, ///1
    EQUAL = 0, ///0
    LESS = -1 ///-1
};

//Prototypes---------------------------------------------------------------

/*!
    *   ask user, does he want to solve new equation
    *
    *   @return bool flag, true - solve new equation, false - don't solve
    */
bool ask_to_solve_new_equation();

/*!
    * get coeffs of equation from user,
    * if user mistake, ask to try again
    *
    * @param coeffs[] Coeffs of equation
    * @param count_of_coeffs Count of coeffs in equation
 */
void get_args_from_user(double coeffs[], int count_of_coeffs);

/*!
    * Clean buffer to the end of line(to the "\n")
    */
void buff_clean();

/*!
    * Compare doubles x1 and x2 with precision 1e-8
    *
    * @param x1 First argument
    * @param x2 Second argument
    *
    * @return MORE(1) if x1 > x2, EQUAL(0) if x1 == x2, LESS(-1) if x1 < x2
 */
int compare(double x1, double x2);    //compare x1 with x2, MORE(1), EQUAL(0), LESS(-1)

/*!
    * @brief function-dispatcher
    *
    * Call another function(solve_square_equation, solve_linear_equation)
    * depend on zeros in args of equation
    *
    * @param coeffs[] Array of coeffs in equation
    * @param roots[] Array of roots of equation
    * @param count_of_coeffs Count of coeffs in the equation
    *
    * @return Count of roots in equation, like INFINITY_OF_ROOT(-1), NO_ROOT(0), ONE_ROOT(1), TWO_ROOTS(2) and etc
 */
int solve_equation(double coeffs[], double roots[], int count_of_coeffs);    //call functions solve_linear_equation, solve_square_equation, depending on roots

/*!
    * Solve square equation and find roots, first coeff mustn't be zero(It checks in solve_equation), roots x1 and x2 write in increasing order
    *
    * @param a First coeff
    * @param b Second coeff
    * @param c Third coeff
    * @param x1 Link to double, where would be write first root, if it doesn't exist, it would be NAN
    * @param x2 Like x1, but second root
    *
    * @return Count of roots in equation, like INFINITY_OF_ROOT(-1), NO_ROOT(0), ONE_ROOT(1), TWO_ROOTS(2)
 */
int solve_square_equation(double a, double b, double c, double* x1, double* x2);

/*!
    * Solve linear equation and find root, first coeff mustn't be zero(It checks in solve_equation), write root in Link x1
    *
    * @param a First coeff
    * @param b Second coeff
    * @param x1 Link to double, where would be write root, if it doesn't exist, it would be NAN
    *
    * @return Count of roots in equation, like INFINITY_OF_ROOT(-1), NO_ROOT(0), ONE_ROOT(1)
 */
int solve_linear_equation(double a, double b, double* x1);

/*!
    * Print roots in right format
    *
    * @param roots[] Array of roots that need to print
    * @param how_many_roots Count of roots that need to print
 */
void print_roots(double roots[], int how_many_roots);
