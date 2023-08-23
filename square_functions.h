#pragma once

enum COUNT_OF_ROOTS { 
    INVALID = -1,
    NO_ROOTS = 0, 
    ONE_ROOT = 1, 
    TWO_ROOTS = 2, 
    INFINITY_OF_ROOTS = 1000 
};
enum COMPARISON{
    MORE = 1, 
    EQUAL = 0, 
    LESS = -1 
};
const double EXP = 1e-8;

bool ask_to_solve_new_equation();
void get_args_from_user(double* a, double* b, double* c);
void buff_clean();
int compare(double x1, double x2);    //compare x1 with x2, MORE(1), EQUAL(0), LESS(-1)
int solve_equasion(double a, double b, double c, double* x1, double* x2);    //call functions solve_linear_equation, solve_square_equation, depending on roots
int solve_square_equasion(double a, double b, double c, double* x1, double* x2);
int solve_linear_equasion(double b, double c, double* x1, double* x2);
void print_roots(double x1, double x2, int how_many_roots);
void test();
