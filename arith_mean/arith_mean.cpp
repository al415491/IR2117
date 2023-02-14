#include <iostream>
int main(int argc, char** argv) {
	double m = 0, s = 0;
	int n = argc -1;
	for ( int i=0; i<argc; i++) {
		s+= atoi(argv[i]); // atoi convierte en int
	}
	m = s/n; 
	std::cout << "Arithmetic mean: " << m << std::endl;
	return 0;
}
