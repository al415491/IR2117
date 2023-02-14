#include <iostream>
#include <vector>
#include <algorithm>



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
	
	std::sort(elements.begin(), elements.end()); 
	int middle = elements.size()/2;
	if ( n % 2  == 0) { 	// par
		m = double(elements[middle]+elements[middle+1])/2;
	}else{ 			// impar
		m = elements[middle];
	}
	
	std::cout << "Median: " << m << std::endl;
	return 0;
}
