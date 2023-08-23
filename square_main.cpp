#include <stdio.h>
#include <math.h>
#include "square_functions.h"



int main(){
    #ifndef TEST
        double coeffs[] = {NAN, NAN, NAN};
        double roots[] = {NAN, NAN};
        int count_roots = INVALID, count_of_coeffs = INVALID;

        printf("Hello, It's solver of square equation. If you want to use tests, write option -DTEST when compiling\n");

        while(ask_to_solve_new_equation()){
            count_of_coeffs = 3;
            get_args_from_user(coeffs, count_of_coeffs);
            count_roots = solve_equasion(coeffs, roots, count_of_coeffs);
            print_roots(roots, count_roots);
        }
        printf("Okey, exit\n");
    #else
        printf("TESTS\n");

        int count_of_coeffs = 3;

        double coeffs[] = {NAN, NAN, NAN}, roots[] = {NAN, NAN}, roots_ref[] = {NAN, NAN};
        int count_of_roots = INVALID, count_of_roots_ref = INVALID;
        FILE* file;

        file = fopen("tests.txt", "r");

        for(int test_number = 1; true; test_number++){
            if(!input_test(count_of_coeffs, file, coeffs, &count_of_roots_ref, roots_ref)){
                break;
            }

            count_of_roots = solve_equasion(coeffs, roots, count_of_coeffs);

            if(!check_results(count_of_roots, roots, count_of_roots_ref, roots_ref)){
                print_err(test_number, count_of_coeffs, coeffs, count_of_roots, roots, count_of_roots_ref, roots_ref);
                continue;
            }
            printf("Test №%d is OK\n", test_number);
        }
        fclose(file);
    #endif // TEST


    return 0;
}
