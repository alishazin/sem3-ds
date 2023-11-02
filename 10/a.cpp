#include <iostream>
using namespace std;

int count(int value) {
    
    if (value == 10)
        return 10;

    value++;
    value = count(value);

    cout << "Print " << value << endl;
    return value;
}

int main() {

    count(0);

    return 0;
}