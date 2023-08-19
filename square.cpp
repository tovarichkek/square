#include <stdio.h>
#include <math.h>

int count_of_numbers_after_point;     //кол-во чисел после запятой среди выводимых чисел

void enter_of_args_from_user(double* a, double* b, double* c);
bool is_double(char str[]);
bool is_int(char str[]);
void print_one_root(double x);
void print_two_roots(double x1, double x2);
void print_no_roots();
void print_infinity_of_roots();
bool is_zeros_in_args(double a, double b, double c);    //проверка на нули среди аргументов, если есть то ещё и их обработка

int main(){
    double a = 0, b = 0, c = 0, D = 0;
    char ch_new_problem = 'N';    //Флаг, хочет ли юзер решить новое уравнение
    printf("Hello, It's solver of square equation. Want to try?(Y/N, default N) ");
    scanf("%c", &ch_new_problem);
    while(ch_new_problem == 'Y' || ch_new_problem == 'y'){
        enter_of_args_from_user(&a, &b, &c);
        D = b*b - 4*a*c;
        if(!is_zeros_in_args(a, b, c)){
            if(D < 0){
                print_no_roots();
            }
            else if(!(abs(D) > 0)){
                print_one_root((-b) / (2*a));
            }
            else if(D > 0){
                print_two_roots(((-b) + sqrt(D)) / (2*a), ((-b) - sqrt(D)) / (2*a));
            }
        }
        printf("Want to try again?(Y/N, default N) ");
        scanf("%c", &ch_new_problem);
    }
    printf("Okey, exit\n");    
    return 0;
}

void enter_of_args_from_user(double* a, double* b, double* c){
    while(getchar() != '\n'){}  //Заглушка, для того чтобы не влиял первый '\n' после scanf, а также вероятные ошибки(доп. символы) при вводе Y/N 
    char str[100];
    printf("Please, enter three arguments in your equation in next lines\n");
    do{
        printf("The first argument:\t");
        for(int i=0;(str[i] = getchar()) != '\n';i++){}        
        if(!is_double(str)){
            printf("You write something wrong, try again\n");
        }
    }while(!is_double(str));
    *a = atof(str);
    do{
        printf("The second argument:\t");
        for(int i=0;(str[i] = getchar()) != '\n';i++){}        
        if(!is_double(str)){
            printf("You write something wrong, try again\n");
        }
    }while(!is_double(str));
    *b = atof(str);
    do{
        printf("The third argument:\t");
        for(int i=0;(str[i] = getchar()) != '\n';i++){}        
        if(!is_double(str)){
            printf("You write something wrong, try again\n");
        }
    }while(!is_double(str));
    *c = atof(str);
    do{
        printf("And the count of numbers after point:\t");
        for(int i=0;(str[i] = getchar()) != '\n';i++){}
        if(!is_int(str)){
            printf("You write something wrong, try again\n");
        }
    }while(!is_int(str));
    count_of_numbers_after_point = atoi(str);
    
}
bool is_int(char str[]){
    if(str[0] == '\n'){
        return false;
    }
    for(int i=0;i<100;i++){
        if(str[i] == '\n'){
            return true;
        }
        if(str[i] == '-' && i != 0){
            return false;
        }
        else if(str[i]<'0' || str[i]>'9'){
            return false;
        }
    }
    return true;
}
bool is_double(char str[]){
    int count_of_points = 0;
    int index_of_point = 0;
    if(is_int(str)){
        return true;
    }
    if(str[0] == '.'){
        return false;
    }
    for(int i=0;i<100;i++){
        if(str[i] == '-' && i != 0){
            return false;
        }
        else if(str[i] == '.' && str[i-1] != '-'){
            count_of_points++;
            index_of_point = i;        
        }
        else if(str[i] == '\n'){
            if((count_of_points == 1) && ((i - index_of_point) > 1) && ((index_of_point > 1 && str[0] == '-') || (index_of_point > 0 && str[i] != '-')) ){
                return true;
            }
            else{
                return false;
            }
        }
        else if((str[i]<'0' || str[i]>'9') && str[i] != '-'){
            return false;
        }
    }
    return false;
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
    if(!(abs(a) > 0) && (abs(b) > 0) && (abs(c) > 0)){     //если есть где-то нули в аргументах, то обрабатываем
        print_one_root((-c) / b);
    }
    else if((abs(a) > 0) && !(abs(b) > 0) && (abs(c) > 0)){
        if(((-c) / a) < 0){
            print_no_roots();
        }
        else{
            print_two_roots(sqrt((-c) / a), -sqrt((-c) / a));
        }
    }
    else if((abs(a) > 0) && (abs(b) > 0) && !(abs(c) > 0)){
        print_two_roots(0, (-b) / a);
    }
    else if(!(abs(a) > 0) && !(abs(b) > 0) && (abs(c) > 0)){
        print_no_roots();
    }
    else if(!(abs(a) > 0) && (abs(b) > 0) && !(abs(c) > 0)){
        print_one_root(0);
    }
    else if((abs(a) > 0) && !(abs(b) > 0) && !(abs(c) > 0)){
        print_one_root(0);
    }
    else if(!(abs(a) > 0) && !(abs(b) > 0) && !(abs(c) > 0)){
        print_infinity_of_roots();
    }
    if((abs(a) > 0) && (abs(b) > 0) && (abs(c) > 0)){     //если нет нулей, то возвращаемся в main и решаем обычное квадратное уравнение
        return false;
    }
    else{
        return true;
    }
}

