#include <iostream>

int main() {
int num, sum=0;
std::cout << "Enter a number: ";
std::cin >> num;

for (int i=1; i<=num; i++) {
	sum+= i;
}

std::cout << "The sum from 1 to " << num << " is " << sum << std::endl;
return 0;
}
