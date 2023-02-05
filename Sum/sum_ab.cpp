#include <iostream>

int main() {
	int a,b, suma=0;
	std::cout << "Enter  a: ";
	std::cin >> a;
	std::cout << "Enter  b: ";
	std::cin >> b;

	for (int i=a; i<=b; i++) {
		suma+=i;
		}

	std::cout << "The sum is " << suma << std::endl;
	return 0;
}
