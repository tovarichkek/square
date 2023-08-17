#include <stdio.h>
#include <math.h>

int count_of_numbers_after_point;                                   /*кол-во чисел после запятой среди выводимых чисел*/

void enter_of_args_from_user(double* a, double* b, double* c);
void print_one_root(double x);
void print_two_roots(double x1, double x2);
void print_no_roots();
void print_infinity_of_roots();
bool is_zeros_in_args(double a, double b, double c);               /*проверка на нули среди аргументов, если есть то ещё и их обработка*/




void enter_of_args_from_user(double* a, double* b, double* c){
    printf("Please, enter three arguments in your equation in next lines\n");
    printf("The first argument: \t");
    scanf("%lf", a);
    printf("The second argument:\t");
    scanf("%lf", b);
    printf("The third argument: \t");
    scanf("%lf", c);
    printf("And the count of numbers after point:\t");
    scanf("%d", &count_of_numbers_after_point);
}
void print_one_root(double x){
    printf("There are only one root:\t%.*lf\n", count_of_numbers_after_point, x);
}
void print_two_roots(double x1, double x2){
    printf("There are two roots:\t%.*lf\t%.*lf\n", count_of_numbers_after_point, x1, count_of_numbers_after_point, x2);
}
void print_no_roots(){
    printf("Sorry, but there aren't any roots\n");
}
void print_infinity_of_roots(){
    printf("There are infinity of roots\n");
}
bool is_zeros_in_args(double a, double b, double c){
    if(a == 0 && b != 0 && c != 0){                             /*если есть где-то нули в аргументах, то обрабатываем*/
        print_one_root((-c) / b);
    }
    else if(a != 0 && b == 0 && c != 0){
        if(((-c) / a) < 0){
            print_no_roots();
        }
        else{
            print_two_roots(sqrt((-c) / a), -sqrt((-c) / a));
        }
    }
    else if(a != 0 && b != 0 && c == 0){
        print_two_roots(0, (-b) / a);
    }
    else if(a == 0 && b == 0 && c != 0){
        print_no_roots();
    }
    else if(a == 0 && b != 0 && c == 0){
        print_infinity_of_roots();
    }
    else if(a != 0 && b == 0 && c == 0){
        print_one_root(0);
    }
    else if(a == 0 && b == 0 && c == 0){
        print_infinity_of_roots();
    }


    if(a != 0 && b != 0 && c != 0){                             /*если нет нулей, то возвращаемся в main и решаем обычное квадратное уравнение*/
        return false;
    }
    else{
        return true;
    }

}

int main(){
    double a, b, c, D;
    char ch_new_problem;                                        /*Флаг, хочет ли юзер решить новое уравнение*/  
    printf("Hello, It's solver of square equation. Want to try?(Y/N) ");
    scanf("%c", &ch_new_problem);

    while(ch_new_problem == 'Y' || ch_new_problem == 'y'){
        enter_of_args_from_user(&a, &b, &c);
        D = b*b - 4*a*c;
        if(!is_zeros_in_args(a, b, c)){
            if(D < 0){
                print_no_roots();
            }
            else if(D == 0){
                print_one_root((-b) / (2*a));
            }
            else if(D > 0){
                print_two_roots(((-b) + sqrt(D)) / (2*a), ((-b) - sqrt(D)) / (2*a));
            }
        }
        printf("Want to try again?(Y/N) ");
        scanf(" %c", &ch_new_problem);
    }
    printf("Okey, exit\n");    
        

    return 0;
}
