#include <iostream>
#include "larray.cpp"
using namespace std;

int main() {

    LinearArray arr = LinearArray();   

    arr.append(10, true);
    arr.append(12, true);
    arr.append(16, true);
    arr.insert(1, 9, true);
    arr.set(0, 100);
    
    cout << arr << endl;
    arr.collapse();
    cout << arr << endl;

    return 0;
}