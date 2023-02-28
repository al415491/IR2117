all: arith_mean median mode summatrix

arith_mean: arith_mean.cpp
	g++ -o arith_mean arith_mean.cpp
	
mode: mode_eigen.cpp
	g++ -I/usr/include/eigen3/ -o mode mode_eigen.cpp

median: median_eigen.cpp
	g++ -I/usr/include/eigen3/ -o median median_eigen.cpp
	
summatrix: summatrix.cpp
	g++ -I/usr/include/eigen3/ -o summatrix summatrix.cpp
