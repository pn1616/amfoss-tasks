#include <iostream>
#include <fstream>
#include <string>

int read_number_from_file(const std::string &filename) {
    int num;
    std::ifstream inputfile(filename);
    if (!inputfile.is_open()) {
        std::cerr << "Could not open " << filename << std::endl;
        exit(1);
    }
    inputfile >> num;
    inputfile.close();
    return num;
}

void write_number_to_file(const std::string &filename, int content) {
    std::ofstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Could not open " << filename << std::endl;
        exit(1);
    }
    infile << content;
    infile.close();
}

std::string generate_pattern(int n) {
    std::string pattern;

    for (int i = 0; i < n; i++) {
        pattern += std::string(n - i - 1, ' ') + std::string(2 * i + 1, '*') + "\n";
    }

    for (int i = n - 2; i >= 0; i--) {
        pattern += std::string(n - i - 1, ' ') + std::string(2 * i + 1, '*') + "\n";
    }

    return pattern;
}

void write_pattern_to_file(const std::string &filename, const std::string &pattern) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Could not open " << filename << std::endl;
        exit(1);
    }
    outfile << pattern;
    outfile.close();
}

int main() {
    int n;
    
    std::cout << "Enter the number: ";
    std::cin >> n;

    write_number_to_file("input2.txt", n);
    n = read_number_from_file("input2.txt");
    std::string result = generate_pattern(n);
    write_pattern_to_file("output2.txt", result);

    return 0;
}
