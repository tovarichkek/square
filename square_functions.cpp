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

void get_args_from_user(double* a, double* b, double* c){
    assert(a != b && a != c && b != c);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int count_of_right_enters = 0; 
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

int compare(double x1, double x2){
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

int solve_equasion(double a, double b, double c, double* x1, double* x2){
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL); 

    if(compare(a, 0) != EQUAL){
        return solve_square_equasion(a, b, c, x1, x2);
    }
    else if(compare(b, 0) != EQUAL){
        return solve_linear_equasion(b, c, x1, x2);
    }
    else if(compare(c, 0) != EQUAL){
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
    else{
        double s = sqrt(D);         //Discriminant > 0, two roots
        *x1 = (-b + s) / (2*a);
        *x2 = (-b - s) / (2*a);
        return TWO_ROOTS;
    }
}

int solve_linear_equasion(double b, double c, double* x1, double* x2){
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if(compare(c, 0) == EQUAL){
        *x1 = 0;
        *x2 = NAN;
        return ONE_ROOT;
    }
    else{
        *x1 = (-c) / b;
        *x2 = NAN;
        return ONE_ROOT;
    }
}

void print_roots(double x1, double x2, int how_many_roots){
    assert(how_many_roots > INVALID);
    
    switch(how_many_roots){
        case INFINITY_OF_ROOTS : 
            printf("There are infinity of roots\n"); 
            break;
        case NO_ROOTS : 
            printf("Sorry, but there aren't any roots\n"); 
            break;
        case ONE_ROOT :
            printf("There are only one root:\t%.12lf\n", x1); 
            break;
        case TWO_ROOTS :
            printf("There are two roots:\t%.12lf\t%.12lf\n", x1, x2);  
            break;
        default :
            printf("ERROR IN how_many_roots");
    }
}
