#pragma once

void get_args_from_user(double* a, double* b, double* c);
void buff_clean();
int compare_with_zero(double x);    //сравнение x с нулём, если больше возвращает 1, если равно - 0, меньше - -1
int solve_equasion(double a, double b, double c, double* x1, double* x2);    //вызывает функции solve_square_equasion, solve_linear_equasion или print_roots в зависимости от нулей в аргументах
int solve_square_equasion(double a, double b, double c, double* x1, double* x2);
int solve_linear_equasion(double b, double c, double* x1, double* x2);
void print_roots(double x1, double x2, int how_many_roots);
