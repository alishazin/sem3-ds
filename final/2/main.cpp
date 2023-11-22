#include <iostream>
using namespace std;

int main() {

    int i, flag=0, value, prevValue;
    string text;

    cout << "Enter the text: ";
    cin >> text;

    int length = text.length();

    for (i=1; i<length; i++) {

        value = text[i];
        prevValue = text[i-1];

        if (value - prevValue == 1 || value - prevValue == 33 || prevValue - value == 31) {
            if (flag == 0) {
                cout << (char) prevValue << (char) value;
                flag = 1;
            } else {
                cout << (char) value;
            }
        } else {
            if (flag == 1) {
                cout << endl;
                flag = 0;
            }
        }

    }

    return 0;
}