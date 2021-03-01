# Makefile for Quiz 1c in Chapter 11.15

a.out : main.cpp Vector3d.o Point3d.o
	clang++ -g -O main.cpp Vector3d.o Point3d.o
Vector3d.o : Vector3d.cpp
	clang++ -g -c -O Vector3d.cpp
Point3d.o : Point3d.cpp
	clang++ -g -c -O Point3d.cpp

clean :
	rm *.out
	rm *.o