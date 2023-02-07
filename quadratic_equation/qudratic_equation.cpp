#include <iostream>
#include <cmath>

int main() {
	double a,b,c, solution1 , solution2;
	std::cout << "Enter  a: ";
	std::cin >> a;
	std::cout << "Enter  b: ";
	std::cin >> b;
	std::cout << "Enter  c: ";
	std::cin >> c;
	
	double discriminant = b*b - 4*a*c;
	if (discriminant > 0) { 
		solution1= (-b  + std::sqrt(discriminant))/(2*a);
		solution2= (-b  - std::sqrt(discriminant))/(2*a);
	}

	std::cout << "Solutions are " << solution1 << ", " << solution2 << std::endl;
	return 0;}
