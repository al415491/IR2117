#include <iostream>

int main() {
int num, sum=0;
std::cout << "Enter a number: ";
std::cin >> num;

// arithmetic sum
sum = ((1+num)*num)/2 ;

std::cout << "The sum from 1 to " << num << " is " << sum << std::endl;
return 0;
}
