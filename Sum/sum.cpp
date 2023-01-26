#include <iostream>
#include <cassert>

int sum(int num){
	int suma = ((1+num)*num)/2 ;
	return suma;
}


int main() {
int num, suma;
std::cout << "Enter a number: ";
std::cin >> num;

if (num<1) {
	std::cout << "ValueError --> Number must be equal or greater than 1\n";
	return 0;
	}

suma = sum(num);
std::cout << "The sum from 1 to " << num << " is " << suma << std::endl;
return 0;
}
