#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square_functions.h"

bool ask_to_solve_new_equation(){
    char flag_to_solve_new_problem = 'N';    //Flag, do user want to solve new equation

    printf("Want to solve new equation?(Y/N, default N) ");
    scanf("%c", &flag_to_solve_new_problem);

    if(flag_to_solve_new_problem != '\n'){      //check last symbol, for default N
        buff_clean();
    }
    if(flag_to_solve_new_problem == 'Y' || flag_to_solve_new_problem == 'y'){
        return true;
    }
    else{
        return false;
    }
}

void get_args_from_user(double coeffs[], int count_of_coeffs){
    int count_of_right_enters = 0;

    while(count_of_right_enters != count_of_coeffs){
        printf("Please, enter arguments in your equation in next line like a b...\n");

        for(int i=0; i<count_of_coeffs; i++){
            if(scanf("%lf", &coeffs[i]) != 0){
                count_of_right_enters++;
            }
        }

        if(count_of_right_enters != count_of_coeffs or getchar() != '\n'){
            count_of_right_enters = 0;
            buff_clean();
            printf("You write something wrong, try again\n");
        }
    }
}

void buff_clean(){
    while(getchar() != '\n'){}
}

int compare(double x1, double x2){
    const double EXP = 1e-8;

    assert(std::isfinite(x1));
    assert(std::isfinite(x2));

    if(fabs(x1 - x2) > EXP && (x1 - x2) > 0){
        return MORE;
    }
    if(fabs(x1 - x2) < EXP){
        return EQUAL;
    }
    return LESS;
}

int solve_equation(double coeffs[], double roots[], int count_of_coeffs){
    for(int i = 0; i < count_of_coeffs; i++){
//TODO        my_assert(std::isfinite(coeffs[i]), INFINITE_ARG_PASSED);
    }

    if(compare(coeffs[0], 0) != EQUAL){
        return solve_square_equation(coeffs[0], coeffs[1], coeffs[2], &roots[0], &roots[1]);
    }
    else if(compare(coeffs[1], 0) != EQUAL){
        roots[1] = NAN;
        return solve_linear_equation(coeffs[1], coeffs[2], &roots[0]);
    }
    else if(compare(coeffs[2], 0) != EQUAL){
        roots[0] = NAN;
        roots[1] = NAN;
        return NO_ROOTS;
    }
    else{
        roots[0] = NAN;
        roots[1] = NAN;
        return INFINITY_OF_ROOTS;
    }
}

int solve_square_equation(double a, double b, double c, double* x1, double* x2){    //return roots in ascending order
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    double D = b*b - 4*a*c;

    if(compare(D, 0) == LESS){     //Discriminant < 0, no roots
        *x1 = NAN;
        *x2 = NAN;
        return NO_ROOTS;
    }
    else if(compare(D, 0) == EQUAL){     //Discriminant == 0, one root
        *x1 = (-b) / (2*a);
        *x2 = NAN;
        return ONE_ROOT;
    }
    else{                        //Discriminant > 0, two roots
        double sqrt_D = sqrt(D), pr = NAN;

        *x1 = (-b + sqrt_D) / (2*a);
        *x2 = (-b - sqrt_D) / (2*a);
        if(*x1 > *x2){
            pr = *x1;
            *x1 = *x2;
            *x2 = pr;
        }
        return TWO_ROOTS;
    }
}

int solve_linear_equation(double a, double b, double* x1){
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(x1 != NULL);

    if(compare(b, 0) == EQUAL){
        *x1 = 0;
        return ONE_ROOT;
    }
    *x1 = (-b) / a;
    return ONE_ROOT;
}

void print_roots(double roots[], int how_many_roots){
    switch(how_many_roots){
        case INFINITY_OF_ROOTS :
            printf("There are infinity of roots\n");
            break;
        case NO_ROOTS :
            printf("Sorry, but there aren't any roots\n");
            break;
        case ONE_ROOT :
            printf("There is only one root:\t%.12lf\n", roots[0]);
            break;
        case TWO_ROOTS :
            printf("There are two roots:\t%.12lf\t%.12lf\n", roots[0], roots[1]);
            break;
        case THREE_ROOTS :
            printf("There are three roots:\t%.12lf\t%.12lf\t%.12lf\n", roots[0], roots[1], roots[2]);
            break;
        case FORE_ROOTS :
            printf("There are fore roots:\t%.12lf\t%.12lf\t%.12lf\t%.12lf\n", roots[0], roots[1], roots[2], roots[3]);
            break;
        case FIVE_ROOTS :
            printf("There are five roots:\t%.12lf\t%.12lf\t%.12lf\t%.12lf\t%.12lf\n", roots[0], roots[1], roots[2], roots[3], roots[4]);
            break;
        default :
            printf("ERROR in how_many_roots");
            break;
    }
}

