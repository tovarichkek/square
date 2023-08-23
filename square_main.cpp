#include <stdio.h>
#include <math.h>
#include "square_functions.h"

int main(){
    double coeffs[] = {NAN, NAN, NAN, NAN, NAN, NAN};
    double roots[] = {NAN, NAN, NAN, NAN, NAN};
    int count_roots = INVALID, count_of_coeffs = INVALID;
    printf("Hello, It's solver of square equation.\n");
    while(ask_to_solve_new_equation()){
        count_of_coeffs = 3;
        get_args_from_user(coeffs, count_of_coeffs);
        count_roots = solve_equasion(coeffs, roots, count_of_coeffs);
        print_roots(roots, count_roots);
    }
    printf("Okey, exit\n");
    return 0;
}
