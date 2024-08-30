#include <iostream>

int main() {
    int n;

    std::cout << "Enter the number: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            std::cout << " ";
        }
        int k; 
        for (k = 0; k < i; k++) {
            std::cout << "*";
        }
        for (int l = 0; l < k - 1; l++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i; j++) {
            std::cout << " ";
        }
        int k; 
        for (k = 0; k < i; k++) {
            std::cout << "*";
        }
        for (int l = 0; l < k - 1; l++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
