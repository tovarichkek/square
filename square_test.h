#pragma once

//Prototypes--------------------------------------------------------------------------

/*!
    * Main test function, run another functions
 */
void TEST();

/*!
    * Read args in one line in file with tests and set args in variebles
    *
    * @param count_of_coeffs Count of coeffs in equation
    * @param file Link to file from function read information
    * @param coeffs[] Array of coeffs in equation
    * @param count_of_roots_ref Link to right count of roots in equation of test
    * @param roots_ref[] Array of right roots in equation of test
    *
    * @return Flag true if data is readed or false if reach EOF
*/
bool input_test(int count_of_coeffs, FILE* file, double coeffs[], int* count_of_roots_ref, double roots_ref[]);    //If EOF, return false, else true

/*!
    * Check, was results of programm and tests equal
    *
    * @param count_of_coeffs Count of coeffs in equation
    * @param roots[] Array of roots, where are roots from programm
    * @param count_of_roots_ref Count of roots in test(fourth argument in line of test)
    * @param roots_ref[] Array of right roots from tests
    *
    * @return True if results in programm and in tests equal, false if no
*/
bool check_results(int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]);

/*!
    * Print error
    *
    * @param test_number Number of test in that moment
    * @param count_of_coeffs Count of coeffs in equation
    * @param coeffs[] Array of coeffs from equation
    * @param count_of_roots Count of roots, that was find, in programm
    * @param roots[] Array of roots, that were find,
    * @param count_of_roots_ref Right count of roots from test(fourth argument in line of test)
    * @param roots_ref[] Array of right roots from test(fiv)
*/
void print_err(int test_number, int count_of_coeffs, double coeffs[], int count_of_roots, double roots[], int count_of_roots_ref, double roots_ref[]);
