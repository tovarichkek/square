#include <stdio.h>
#include <math.h>
#include "square_functions.h"

#define EXP 1e-16
enum COUNT_OF_ROOTS{ NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2, INFINITY_OF_ROOTS = 1000 };
enum COMPARISON{ MORE = 1, EQUAL = 0, LESS = -1 };

void get_args_from_user(double* a, double* b, double* c){
    int count_of_right_enters = 0;      //
    while(count_of_right_enters != 3){
        printf("Please, enter three arguments in your equation in next line like a b c\n");
        count_of_right_enters = scanf("%lf%lf%lf", a, b, c);
        if(count_of_right_enters != 3 or getchar() != '\n'){
            count_of_right_enters = 0;
            buff_clean();
            printf("You write something wrong, try again\n");
        }
    }
}

void buff_clean(){
    while(getchar() != '\n'){}
}

int compare_with_zero(double x){
    if(abs(x) > EXP && x > 0){    //можно сравнить с 0, т.к. до этого была проверка модуля с EXP
        return MORE;
    }
    if(abs(x) < EXP){
        return EQUAL;
    }
    return LESS;
}

int solve_equasion(double a, double b, double c, double* x1, double* x2){
    if(compare_with_zero(a) != EQUAL){
        return solve_square_equasion(a, b, c, x1, x2);
    }
    else if(compare_with_zero(b) != EQUAL){
        return solve_linear_equasion(b, c, x1, x2);
    }
    else if(compare_with_zero(c) != EQUAL){
        *x1 = NAN;
        *x2 = NAN;
        return NO_ROOTS;
    }
    else{
        *x1 = NAN;
        *x2 = NAN;
        return INFINITY_OF_ROOTS;
    }
}

int solve_square_equasion(double a, double b, double c, double* x1, double* x2){
    double D = b*b - 4*a*c;
    if(compare_with_zero(D) == LESS){     //дискриминант меньше нуля, корней нет
        *x1 = NAN;
        *x2 = NAN;
        return NO_ROOTS;
    }
    else if(compare_with_zero(D) == EQUAL){     //дискриминант равен нулю, один корень
        *x1 = (-b) / (2*a);
        *x2 = NAN;
        return ONE_ROOT;
    }
    else{
        *x1 = (-b + sqrt(D)) / (2*a);
        *x2 = (-b - sqrt(D)) / (2*a);
        return TWO_ROOTS;
    }
}

int solve_linear_equasion(double b, double c, double* x1, double* x2){
    if(compare_with_zero(c) == EQUAL){
        *x1 = NAN;
        *x2 = NAN;
        return NO_ROOTS;
    }
    else{
        *x1 = (-c) / b;
        *x2 = NAN;
        return ONE_ROOT;
    }
}

void print_roots(double x1, double x2, int how_many_roots){
    switch(how_many_roots){
        case INFINITY_OF_ROOTS : printf("There are infinity of roots\n"); break;
        case NO_ROOTS : printf("Sorry, but there aren't any roots\n"); break;
        case ONE_ROOT : printf("There are only one root:\t%lf\n", x1); break;
        case TWO_ROOTS : printf("There are two roots:\t%lf\t%lf\n", x1, x2); break;
        default : printf("ERROR IN how_many_roots");
    }
}
