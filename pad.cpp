#include <iostream>
#include <cstring>
#include <string.h>

#define V 8

using namespace std;

void runTable() {
     int a = 5;
    int b = 6;
    
    // First row of the table
    for (int i = 0; i < V; ++i) {
        cout << "+-------";
    }
    cout << "+" << endl;

    // Fill values in the first row
    cout << "| Index |";   //  first cell
    for (int i = 0; i < V - 1; ++i) {
        printf(" %-4d  |", i + 5);
    }
    printf("\n");

    for (int i = 0; i < V; ++i) {
        cout << "+-------";
    }
    cout << "+";
}


void runPointer() {
    const char* text = "Hello";
    cout << text << endl;
    cout << &text << endl;


    void passArgument(const char* text) {
        cout << text;
    }
}


int main() {
    runPointer();
   


    return 0;
}