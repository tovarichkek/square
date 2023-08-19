#include <stdio.h>
#include <math.h>
#define BUFF_CLEAN while(getchar() != '\n') {}    //очистка буфера

void enter_of_args_from_user(double* a, double* b, double* c);
int compare_with_zero(double x);    //сравнение x с нулём, если больше возвращает 1, если равно - 0, меньше - -1
void dispatcher(double a, double b, double c);    //вызывает функции square, linear или print_of_roots в зависимости от нулей в аргументах
void square(double a, double b, double c);
void linear(double b, double c);
void print_of_roots(double x1, double x2, bool flag_infinity_of_roots, int how_many_roots);


int main(){
    double a = NAN, b = NAN, c = NAN;
    char flag_to_solve_new_problem = 'N';    //Флаг, хочет ли юзер решить новое уравнение

    printf("Hello, It's solver of square equation. Want to try?(Y/N, default N) ");
    scanf("%c", &flag_to_solve_new_problem);
    BUFF_CLEAN;
    while(flag_to_solve_new_problem == 'Y' || flag_to_solve_new_problem == 'y'){
        enter_of_args_from_user(&a, &b, &c);
        dispatcher(a, b, c);
        printf("Want to try again?(Y/N, default N) ");
        scanf("%c", &flag_to_solve_new_problem);
        BUFF_CLEAN;
    }
    printf("Okey, exit\n");
    return 0;
}

void enter_of_args_from_user(double* a, double* b, double* c){
    int count_of_right_enters = 0;      //
    while(count_of_right_enters != 3){
        printf("Please, enter three arguments in your equation in next line like a b c\n");
        count_of_right_enters = scanf("%lf%lf%lf", a, b, c);
        if(count_of_right_enters != 3 or getchar() != '\n'){
            count_of_right_enters = 0;
            BUFF_CLEAN;
            printf("You write something wrong, try again\n");
            continue;
        }
    }
}

int compare_with_zero(double x){
    if(abs(x) > 1e-16 && x > 0){    //можно сравнить с 0, т.к. до этого была проверка модуля с 1e-16
        return 1;
    }
    if(abs(x) < 1e-16){
        return 0;
    }
    return -1;
}

void dispatcher(double a, double b, double c){
    if(compare_with_zero(a) != 0){
        square(a, b, c);
    }
    else if(compare_with_zero(b) != 0){
        linear(b, c);
    }
    else if(compare_with_zero(c) != 0){
        print_of_roots(NAN, NAN, false, 0);
    }
    else{
        print_of_roots(NAN, NAN, true, NAN);
    }
}

void square(double a, double b, double c){
    double D = b*b - 4*a*c;
    if(compare_with_zero(D) == -1){     //дискриминант меньше нуля, корней нет
        print_of_roots(NAN, NAN, false, 0);
    }
    else if(compare_with_zero(D) == 0){     //дискриминант равен нулю, один корень
        print_of_roots((-b) / (2*a), NAN, false, 1);
    }
    else{
        print_of_roots((-b + sqrt(D)) / (2*a), (-b - sqrt(D)) / (2*a), false, 2);
    }
}

void linear(double b, double c){
    if(compare_with_zero(c) == 0){
        print_of_roots(NAN, NAN, false, 0);
    }
    else{
        print_of_roots((-c) / b, NAN, false, 1);
    }
}

void print_of_roots(double x1, double x2, bool flag_infinity_of_roots, int how_many_roots){
    if(flag_infinity_of_roots){
        printf("There are infinity of roots\n");
    }
    else if(how_many_roots == 0){
        printf("Sorry, but there aren't any roots\n");
    }
    else if(how_many_roots == 1){
        printf("There are only one root:\t%lf\n", x1);
    }
    else if(how_many_roots == 2){
        printf("There are two roots:\t%lf\t%lf\n", x1, x2);
    }
}

