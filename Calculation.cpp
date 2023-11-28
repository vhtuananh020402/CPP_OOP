#include <iostream>
#include <regex>
#include <limits> 

class Calculation {
    private:
        unsigned int a;
        unsigned int b;
        unsigned result;
    
    public:
        Calculation() {
            this->a = 0;
            this->b = 0;
            this->result = 0;
        }

        Calculation(const std::string &equation) {
            // regex pattern(R"( (\d+) \s* ([+\-*/]) \s* (\d+))");
            std::regex pattern(R"((\d+)\s*([+\-*/])\s*(\d+))");

            std::smatch match;

            if (std::regex_match(equation, match, pattern)) {
                // Extract matched components
                unsigned int number1    = std::stoi(match[1]);
                char op                 = match[2].str()[0];
                unsigned int number2    = std::stoi(match[3]);

                switch (op)
                {
                case '+':
                    this->result = addTwoNumber(number1, number2);
                    break;
                
                default:
                    break;
                }


            } else {
                std::cout << "Wrong equation format" << std::endl;
            }

        }

        unsigned int addTwoNumber(unsigned int a, unsigned int b) {
            unsigned sum = a ^ b;
            unsigned carry = a & b;

            while (!(carry == 0)) {
                carry = carry << 1;
                a = sum;
                b = carry;
                sum = a ^ b;
                carry = a & b;
            }

            return sum;
        }

        unsigned int getResult() {
            return this->result;
        }


};

int main() {
    // std::string equationStr;
    // std::cout << "Enter your equation: ";
    // std::getline(std::cin, equationStr);

    // // Ignore any remaining characters in the input buffer, including the newline
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Calculation *cal1 = new Calculation("12 + 15");

    std::cout << cal1->getResult();

    delete cal1;

    return 0;
}