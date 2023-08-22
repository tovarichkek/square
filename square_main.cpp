#include <stdio.h>
#include <math.h>
#include "square_functions.h"

int main(){
    double a = NAN, b = NAN, c = NAN;
    char flag_to_solve_new_problem = 'N';    //Флаг, хочет ли юзер решить новое уравнение
    double x1 = NAN, x2 = NAN;
    int count_roots = -1;
    printf("Hello, It's solver of square equation. Want to try?(Y/N, default N) ");
    scanf("%c", &flag_to_solve_new_problem);
    if(flag_to_solve_new_problem != '\n'){
        buff_clean();
    }
    while(flag_to_solve_new_problem == 'Y' || flag_to_solve_new_problem == 'y'){
        get_args_from_user(&a, &b, &c);
        count_roots = solve_equasion(a, b, c, &x1, &x2);
        print_roots(x1, x2, count_roots);
        printf("Want to try again?(Y/N, default N) ");
        scanf("%c", &flag_to_solve_new_problem);
        if(flag_to_solve_new_problem != '\n'){
            buff_clean();
        }
    }
    printf("Okey, exit\n");
    return 0;
}
