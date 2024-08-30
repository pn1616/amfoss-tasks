#include <iostream>
#include <fstream>
#include <string>

void subtask2() {
    std::string content;
    std::ifstream infile("input.txt");
    std::getline(infile, content);
    infile.close();

    std::ofstream outfile("output.txt");
    outfile << content;
    outfile.close();

    std::ifstream readfile("output.txt");
    std::getline(readfile, content);
    readfile.close();

    std::cout << content << std::endl;
}

int main() {
    std::string inputcontent;
    std::cout << "Content of the file: " << std::endl;
    std::getline(std::cin, inputcontent);

    std::ofstream infile("input.txt");
    infile << inputcontent;
    infile.close();

    std::cout << "printing output.txt..." << std::endl;
    subtask2();

    return 0;
}
