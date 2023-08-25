#include <stdio.h>
#include <math.h>
#include "my_asserts.h"

#ifdef NDEBUG
    #define my_assert_is_p_null(expr) ERROR{NO_ERROR, __FILE__, __FUNCTION__, __LINE__}
#else
    #define my_assert_is_p_null(expr) my_assert_fail_is_p_null(#expr, __FILE__, __FUNCTION__, __LINE__)
#endif // NDEBUG

struct ERROR{
    int code_of_error;
    const char* name_file;
    const char* name_func;
    int line;
};

ERROR my_assert_fail_isfinite(double x, const char* name_file, const char* name_func, int line){
    if(std::isfinite(x)){
        return ERROR{ISFINITE_ERROR, name_file, name_func, line};
    }
    return ERROR{NO_ERROR, name_file, name_func, line};
}

ERROR my_assert_fail_is_p_null(const void* p, const char* name_file, const char* name_func, int line){
    if(p == NULL){
        return ERROR{IS_P_NULL_ERROR, name_file, name_func, line};
    }
    return ERROR{NO_ERROR, name_file, name_func, line};
}

ERROR my_assert_fail_is_p1_eq_p2(const void* p1, const void *p2, const char* name_file, const char* name_func, int line){
    if(p1 == p2){
        return ERROR{IS_P1_EQ_P2_ERROR, name_file, name_func, line};
    }
    return ERROR{NO_ERROR, name_file, name_func, line};
}

void print_error_in_my_assert_fail(ERROR err){
    switch(err.code_of_error){
        case NO_ERROR:
            break;
        case ISFINITE_ERROR:
            printf("Error in %s : %s : line %d\nNumber is NAN or infinite\n", err.name_file, err.name_func, err.line);
            break;
        case IS_P_NULL_ERROR:
            printf("Error in %s : %s : line %d\nPointer has addr NULL\n", err.name_file, err.name_func, err.line);
            break;
        case IS_P1_EQ_P2_ERROR:
            printf("Error in %s : %s : line %d\nPointer №1 is equal to pointer №2\n", err.name_file, err.name_func, err.line);
            break;
        default:
            printf("Unknown error in %s : %s : line %d\n", err.name_file, err.name_func, err.line);









    }
}
