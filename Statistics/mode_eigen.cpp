#include <iostream>
#include <Eigen/Dense>

using Eigen::VectorXd;

int main() {
    double m = 0;
    int n = 0, input;
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

    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (elements[j] == elements[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            m = elements[i];
        }
    }

    std::cout << "Mode: " << m << std::endl;
    return 0;
}
