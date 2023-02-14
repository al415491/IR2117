#include <iostream>
int main() {
	double m = 0, s = 0;
	int n = 0, input;
	
	std::cout << "Give me a number (0 to finish): " << std::endl;
	std::cin >> input;
	
	while( !std::cin.eof() ) {  // Ctrl + D para indicar end of file
		s+= input;
		n++;
		std::cout << "Give me a number (0 to finish): " << std::endl;
		std::cin >> input;
	}
	
	m = s/n; 
	std::cout << "Arithmetic mean: " << m << std::endl;
	return 0;
}
