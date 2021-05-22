
PWD := $(shell pwd)

help :
	@echo 'Targets: '
	@echo '    clean     - Remove all binary files.'
	@echo '    static    - Compile main using static library.'
	@echo '    dynamic   - Compile main using dynamic library.'
	@echo ''

static : main.o lib_mylib.a
	clang++ main.o -L . -l _mylib -o main.out
	./main.out
# Another method:
#   clang++ main.o lib_mylib.a -o main.out
# Command explain: 
#   clang++ -L [path] -l [name]: compiler will search lib[name].a in [path] to link the library

dynamic : main.o lib_mylib.so
	clang++ main.o -L . -l _mylib -o main.out -Wl,-rpath,$(PWD)
	./main.out
# Another method
#   clang++ main.o lib_mylib.so -o main.out
#   And then append shared library path to global variable LD_LIBRARY_PATH
#       export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:[path]
# Command explain:
#	clang++ -Wl,[arg1],[arg2],... : pass the comma seperate arguments in [arg] to the linker

lib_mylib.so : mylib.o
	clang++ -shared mylib.o -o lib_mylib.so

lib_mylib.a : mylib.o
	ar rcs lib_mylib.a mylib.o

main.o : main.cpp
	clang++ -c main.cpp

mylib.o : mylib.cpp
	clang++ -c mylib.cpp

clean:
	rm -f *.so *.o *.a *.out