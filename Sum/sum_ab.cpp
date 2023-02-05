#include <iostream>

int main() {
	int a,b, suma=0;
	std::cout << "Enter  a: ";
	std::cin >> a;
	std::cout << "Enter  b: ";
	std::cin >> b;

	while ( a<1 ){
		std::cout << "Enter  a: ";
		std::cin >> a;
	}
	while ( b<a ){
		std::cout << "Enter  b: ";
		std::cin >> b;
	}
	for (int I=a; I<=b; I++) {
		suma+=I;
		}

	std::cout << "The sum is " << suma << std::endl;
	return 0;}
