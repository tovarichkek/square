#pragma once

//Enums--------------------------------------------------------------------------

enum ERROR_CODE{
    NO_ERROR = 0,
    ISFINITE_ERROR = 1,
    IS_P_NULL_ERROR = 2,
    IS_P1_EQ_P2_ERROR = 3
};

//Struct--------------------------------------------------------------------------

struct ERROR;

//Prototypes--------------------------------------------------------------------------

ERROR my_assert_fail_isfinite(double x, const char* name_file, const char* name_func, int line);
ERROR my_assert_fail_is_p_null(const void* p, const char* name_file, const char* name_func, int line);
ERROR my_assert_fail_is_p1_eq_p2(const void* p1, const void* p2, const char* name_file, const char* name_func, int line);
void print_error_in_my_assert_fail(ERROR err);
