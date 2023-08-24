#include <iostream>
#include "larray.cpp"
using namespace std;

int main() {

    // LinearArray arr = LinearArray();   
    // LinearArray<char> arr = LinearArray<char>();   
    LinearArray<string> arr = LinearArray<string>();   

    // arr.append(10, true);
    // arr.append(12, true);
    // arr.append(16, true);
    // arr.insert(1, 9, true);
    // arr.set(0, 100);

    // arr.append('a', true);
    // arr.append('b', true);
    // arr.append('c', true);
    // arr.insert(1, 'd', true);
    // arr.set(0, 'e');

    arr.append("AA", true);
    arr.append("BB", true);
    arr.append("CC", true);
    arr.insert(1, "DD", true);
    arr.set(0, "EE");
    
    cout << arr << endl;
    arr.reverse();
    cout << arr << endl;
    arr.sort();
    cout << arr << endl;

    return 0;
}