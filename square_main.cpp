#include <stdio.h>
#include <math.h>
#include "square_functions.h"

int main(){
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    int count_roots = INVALID; 
    printf("Hello, It's solver of square equation.\n");
    while(ask_to_solve_new_equation()){
        get_args_from_user(&a, &b, &c);
        count_roots = solve_equasion(a, b, c, &x1, &x2);
        print_roots(x1, x2, count_roots);
    }
    printf("Okey, exit\n");
    return 0;
}
