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

while (num<1) {
	std::cout << "Enter a number equal or greater than 1: ";
	std::cin >> num;
	}

suma = sum(num);
std::cout << "The sum from 1 to " << num << " is " << suma << std::endl;
return 0;
}
