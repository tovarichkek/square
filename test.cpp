#include <stdio.h>
#include <math.h>
#include "square_functions.h"
void coeff_to_zero(double* x1, double* x2, int* count_of_roots_in_programm);
void print_err(int test_number, double a, double b, double c, int count_of_roots_in_programm, double x1, double x2, int count_of_roots_ref, double x1_ref, double x2_ref);

int main(){
    double a = NAN, b = NAN, c = NAN, x1_ref = NAN, x2_ref = NAN;
    double x1 = NAN, x2 = NAN;
    int count_of_roots_in_programm = INVALID, count_of_roots_ref = INVALID;    
    FILE* file;
    file = fopen("tests.txt", "r");
    for(int test_number = 1; fscanf(file, "%lf%lf%lf%d%lf%lf", &a, &b, &c, &count_of_roots_ref, &x1_ref, &x2_ref) != EOF; test_number++){
        coeff_to_zero(&x1, &x2, &count_of_roots_in_programm);
        count_of_roots_in_programm = solve_equasion(a, b, c, &x1, &x2);

        if(count_of_roots_in_programm != count_of_roots_ref){
            print_err(test_number, a, b, c, count_of_roots_in_programm, x1, x2, count_of_roots_ref, x1_ref, x2_ref);
            continue;
        }
        else if(count_of_roots_ref == ONE_ROOT){
            if(!std::isfinite(x1) || compare(x1, x1_ref) != EQUAL){   //!std::isfinite for no run assert(isfinite) in compare()
                print_err(test_number, a, b, c, count_of_roots_in_programm, x1, x2, count_of_roots_ref, x1_ref, x2_ref);
                continue;
            }
        }
        else if(count_of_roots_ref == TWO_ROOTS){
            if(!std::isfinite(x1) || !std::isfinite(x2) || (compare(x1, x1_ref) != EQUAL || compare(x2, x2_ref) != EQUAL) && (compare(x1, x2_ref) != EQUAL && compare(x2, x1_ref) != EQUAL)){
                print_err(test_number, a, b, c, count_of_roots_in_programm, x1, x2, count_of_roots_ref, x1_ref, x2_ref);
                continue;
            }
        }
        printf("Test №%d is OK\n", test_number);
    }
    fclose(file);
}

void coeff_to_zero(double* x1, double* x2, int* count_of_roots_in_programm){
    *x1 = 0;
    *x2 = 0;
    *count_of_roots_in_programm = 0;
}

void print_err(int test_number, double a, double b, double c, int count_of_roots_in_programm, double x1, double x2, int count_of_roots_ref, double x1_ref, double x2_ref){
    printf("ERROR in %d test a: %lf, b: %lf, c:%lf\n", test_number, a, b, c);
    printf("count_of_roots_in_programm: %d, x1: %lf, x2: %lf\n", count_of_roots_in_programm, x1, x2);
    printf("count_of_roots_ref : %d,  x1_ref : %lf, x2_ref: %lf\n", count_of_roots_ref, x1_ref, x2_ref);
}

