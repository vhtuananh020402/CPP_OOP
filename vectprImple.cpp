// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    vector<int> g1;
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
 
    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";
 


    vector<int> v1;

    for (int i = 1; i <= 5; i++)
        v1.push_back(i);

    for (auto i = v1.begin(); i != v1.end(); ++i)
        cout << *i << " ";

    int valueToBeDeleted = 3;
    auto it = find(vector.begin(), vector.end(),
                   valueToBeDeleted);
 
    if (it != vector.end()) {
        vector.erase(it);
    }

    return 0;
}