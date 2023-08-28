# square solver
Hello, It's solver of square equation.


Write next lines in your command line to execute this programm:

make -f makefile_square_solver

./square_solver.out

# Test of square solver
Tests are in tests.txt, it has format: a b c count_of_roots (x1ref) (x2ref)

brackets - may not be if root isn't exist

To run programm with tests compile like:

make -f makefile_square_solver square_solver_test.out

./square_solver_test.out

# Square solver without debug
If you want run programm without debug(my_assert):

make -f makefile_square_solver square_solver_no_debug.out

./square_solver_no_debug.out

# Documentation 
To get documentation:

xdg-open documentation/html/index.html
