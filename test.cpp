#include <stdio.h>
#include <math.h>
#include "square_functions.h"
void coeff_to_nan(double* x1, double* x2, int* count_of_roots_in_my_programm);
void coeff_to_nan(double* x1, double* x2, int* count_of_roots_in_my_programm){
    *x1 = 0;
    *x2 = 0;
    *count_of_roots_in_my_programm = 0;
}

int main(){
    double a = NAN, b = NAN, c = NAN, right_answer1 = NAN, right_answer2 = NAN;
    double x1 = NAN, x2 = NAN;
    int count_of_roots_in_my_programm = INVALID, count_of_right_answers = INVALID;    
    FILE* file;
    file = fopen("tests.txt", "r");
    while(fscanf(file, "%lf%lf%lf%d%lf%lf", &a, &b, &c, &count_of_right_answers, &right_answer1, &right_answer2) != EOF){
        coeff_to_nan(&x1, &x2, &count_of_roots_in_my_programm);
        count_of_roots_in_my_programm = solve_equasion(a, b, c, &x1, &x2);

        if(count_of_roots_in_my_programm != count_of_right_answers){
            printf("ERROR in test:\t%lf %lf %lf %d %lf %lf \n", a, b, c, count_of_right_answers, right_answer1, right_answer2);
        }
        if(count_of_right_answers == ONE_ROOT){
            if(compare(x1, right_answer1) != EQUAL){
                printf("ERROR in test:\t%lf %lf %lf %d %lf %lf\n", a, b, c, count_of_right_answers, right_answer1, right_answer2);
            }
        }
        if(count_of_right_answers == TWO_ROOTS){
            if((compare(x1, right_answer1) != EQUAL || compare(x2, right_answer2) != EQUAL) && (compare(x1, right_answer2) != EQUAL && compare(x2, right_answer1) != EQUAL)){
                printf("ERROR in test:\t%lf %lf %lf %d %lf %lf\n", a, b, c, count_of_right_answers, right_answer1, right_answer2);
            }
        }
    }
    fclose(file);
}
