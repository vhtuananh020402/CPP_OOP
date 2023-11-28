#include <iostream>
#include <regex>

int main() {
    // Define the regular expression pattern
    std::regex pattern(R"((\d+)\s*([+\-*\/])\s*(\d+))");

    // Input expressions
    std::string expression1 = "12 + 121312";


    // Match the expressions using the regex pattern
    std::smatch match1;

    if (std::regex_match(expression1, match1, pattern)) {
        // Extract matched components
        int number1 = std::stoi(match1[1]);
        char op = match1[2].str()[0];
        int number2 = std::stoi(match1[3]);

        // Output the extracted values
        std::cout << "Expression 1:\n";
        std::cout << "Number 1: " << number1 << "\n";
        std::cout << "Operator: " << op << "\n";
        std::cout << "Number 2: " << number2 << "\n";
    } else {
        std::cout << "Expression 1 does not match the pattern.\n";
    }

    return 0;
}
