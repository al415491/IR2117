#include <iostream>
#include <vector>
int main() {
	double m = 0, s = 0;
	int n = 0, input;
	std::vector<int> elements;
	std::cout << "Give me a number (0 to finish): " << std::endl;
	std::cin >> input;
	
	while( not std::cin.eof() ) {  // Ctrl + D para indicar end of file
		elements.push_back(input);
		n++;
		std::cout << "Give me a number (0 to finish): " << std::endl;
		std::cin >> input;
	}
	
	sort(elements.begin(), elements.end()); 
	
	std::cout << "Median: " << m << std::endl;
	return 0;
}
