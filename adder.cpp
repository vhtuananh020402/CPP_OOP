#include <iostream>

using namespace std;

int main() {
    unsigned int a;
    unsigned int b;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    unsigned int sum;
    unsigned int carry;

    sum     = a ^ b; 
    carry   = a & b;

    while (carry != 0) {
        carry = carry << 1;
        a = sum;
        b = carry;
        sum = a ^ b;
        carry = a & b;
    }

    cout << a << " + " << b << " = " << sum;
    return 0;
}