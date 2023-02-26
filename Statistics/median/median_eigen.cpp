#include <iostream>
#include <Eigen/Dense>

using Eigen::VectorXd;

int main() {
    double m = 0, input;
    int n = 0;
    VectorXd elements(1);
    std::cout << "Give me a number (0 to finish): " << std::endl;
    std::cin >> input;

    while (input != 0) {
        elements.conservativeResize(n+1);
        elements(n) = input;
        n++;
        std::cout << "Give me a number (0 to finish): " << std::endl;
        std::cin >> input;
    }

    std::sort(elements.data(), elements.data() + elements.size());
    int middle = elements.size()/2;
    if (n % 2 == 0) {  // par
        std::cout << "Even " << std::endl;
        m = double(elements(middle-1) + elements(middle))/2.0;
    } else {  // impar
        std::cout << "Odd " << std::endl;
        m = elements(middle);
    }

    std::cout << "Median: " << m << std::endl;
    return 0;
}

