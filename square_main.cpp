#include <stdio.h>
#include <math.h>
#include "square_functions.h"

#ifdef TEST
    #include "square_test.h"
#endif

/*!
 * @brief The main function.
 *
 * If option -DTEST on, go to TEST MODE - directive #else, otherwise #ifndef TEST.
 */
int main(){
    #ifndef TEST
        double coeffs[] = {NAN, NAN, NAN};
        double roots[] = {NAN, NAN};
        int count_roots = INVALID, count_of_coeffs = INVALID;

        printf("Hello, It's solver of square equation. If you want to use tests, write option -DTEST when compiling\n");

        while(ask_to_solve_new_equation()){
            count_of_coeffs = 3;
            get_args_from_user(coeffs, count_of_coeffs);
            count_roots = solve_equation(coeffs, roots, count_of_coeffs);
            print_roots(roots, count_roots);
        }
        printf("Okey, exit\n");
    #else
        TEST();
    #endif // TEST


    return 0;
}
