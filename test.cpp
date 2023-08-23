#include <stdio.h>
#include <math.h>
#include "square_functions.h"

bool input_test(int count_of_coeffs, FILE* file, double coeffs[], int* count_of_roots_ref, double roots_ref[]);    //If EOF, return false, else true
bool check_results(int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]);
void print_err(int test_number, int count_of_coeffs, double coeffs[], int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]);


int main(){
    int count_of_coeffs = 3;

    double coeffs[] = {NAN, NAN, NAN, NAN, NAN, NAN}, roots[] = {NAN, NAN, NAN, NAN, NAN}, roots_ref[] = {NAN, NAN, NAN, NAN, NAN};
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
}

bool input_test(int count_of_coeffs, FILE* file, double coeffs[], int* count_of_roots_ref, double roots_ref[]){
    for(int i = 0; i < count_of_coeffs; i++){
        if(fscanf(file, "%lf", &coeffs[i]) == EOF){
            return false;
        }
    }
    fscanf(file, "%d", count_of_roots_ref);
    for(int i = 0; i < *count_of_roots_ref; i++){
        fscanf(file, "%lf", &roots_ref[i]);
    }
    return true;
}

bool check_results(int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]){
    if(count_of_roots != count_of_roots_ref){
        return false;
    }
    if(count_of_roots == ONE_ROOT){
        if(compare(roots[0], roots_ref[0]) != EQUAL){
            return false;
        }
    }
    if(count_of_roots == TWO_ROOTS){
        if(compare(roots[0], roots_ref[0]) != EQUAL || compare(roots[1], roots_ref[1]) != EQUAL){
            return false;
        }
    }
    return true;
}

void print_err(int test_number, int count_of_coeffs, double coeffs[], int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]){
    printf("ERROR in %d test, coeffs:", test_number);
    for(int i = 0; i < count_of_coeffs; i++){
        printf("% lf,", coeffs[i]);
    }
    printf("\ncount_of_roots: %d, roots:", count_of_roots);
    for(int i = 0; i < count_of_roots; i++){
        printf(" %lf,", roots[i]);
    }
    printf("\ncount_of_roots_ref: %d, roots_ref:", count_of_roots_ref);
    for(int i = 0; i < count_of_roots_ref; i++){
        printf(" %lf,", roots_ref[i]);
    }
    printf("\n");
}

