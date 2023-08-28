# square solver
Hello, It's solver of square equation.


Write next lines in your command line to execute this programm:

g++ square_functions.cpp square_main.cpp $(cat dedflags.txt)

./a.out

# Test of square solver
Tests are in tests.txt, it has format: a b c count_of_roots (x1ref) (x2ref)

brackets - may not be if root isn't exist

To run programm with tests add file square_test.cpp and option -DTEST when compile like:

g++ square_functions.cpp square_main.cpp square_test.cpp $(cat dedflags.txt) -DTEST

# Square solver without debug
If you want run programm without debug(my_assert) add option -DNDEBUG when compile

