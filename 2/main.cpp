// Find consecutive letters if they appear in the given character array.

#include <iostream>
using namespace std;

int main() {

	int i, current, flag=0;
	string text;
	
	cout << "Enter the text to check : ";
	cin >> text;
	
	int length = text.length();
	
	for (i=1; i<length; i++) {

        if (text[i] - 1 == text[i-1] || text[i] - text[i-1] - 1 == 32 || text[i-1] - text[i] + 1 == 32) {
            if (flag == 0) {
                cout << text[i - 1] << text[i]; 
                flag = 1;
            } else {
                cout << text[i]; 
            }
        } else {
            if (flag == 1) {
                cout << endl;
                flag = 0;
            }
        }
    }
	
    cout << endl;

    cout << "--------- Author ----------------" << endl;
	cout << "Ali Izzath Shazin" << endl;
	cout << "220071601028" << endl;
	cout << "B. Tech CSE A" << endl;
	
	return 0;
}
