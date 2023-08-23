#pragma once

//--------------------------------------------------------------- //TODO

enum COUNT_OF_ROOTS {
    INVALID = -2,
    INFINITY_OF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    THREE_ROOTS = 3,
    FORE_ROOTS = 4,
    FIVE_ROOTS = 5,
};

enum COMPARISON{
    MORE = 1,
    EQUAL = 0,
    LESS = -1
};

//---------------------------------------------------------------

bool ask_to_solve_new_equation();
void get_args_from_user(double coeffs[], int count_of_coeffs);
double* constructor_mass_double(size_t len, double ex);
void buff_clean();
int compare(double x1, double x2);    //compare x1 with x2, MORE(1), EQUAL(0), LESS(-1)
int solve_equasion(double coeffs[], double roots[], int count_of_coeffs);    //call functions solve_linear_equation, solve_square_equation, depending on roots
int solve_square_equasion(double a, double b, double c, double* x1, double* x2);
int solve_linear_equasion(double b, double c, double* x1);
void print_roots(double roots[], int how_many_roots);

//For test mode--------------------------------------------------------------

#ifdef TEST
    bool input_test(int count_of_coeffs, FILE* file, double coeffs[], int* count_of_roots_ref, double roots_ref[]);    //If EOF, return false, else true
    bool check_results(int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]);
    void print_err(int test_number, int count_of_coeffs, double coeffs[], int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]);
#endif // TEST
