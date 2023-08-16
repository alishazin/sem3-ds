// Find consecutive letters if they appear in the given character array.

#include <iostream>
using namespace std;

void printTextPart(string text, int start, int end) {
	for (int i=start; i<=end; i++) {
		cout << text[i];
	}
	cout << endl;
}

int main() {

	int i, last, current, flag=0, count=0;
	string text;
	
	cout << "Enter the text to check : ";
	cin >> text;
	
	last = (int) text[0];
	
	int length = text.length();
	
	int startIndexes[length], endIndexes[length];
	
	for (i=1; i<length; i++) {
		
		current = (int) text[i];

        if (i == length - 1) {

            if (flag == 1) {
                if (current - 1 == last || current - last - 1 == 32 || last - current + 1 == 32) {
                    endIndexes[count] = i;
                } else {
                    endIndexes[count] = i - 1;
                }
            } else {
                if (current - 1 == last || current - last - 1 == 32 || last - current + 1 == 32) {
                    startIndexes[count] = i - 1;
                    endIndexes[count] = i;
                }
            }
        }
		
		else if (current - 1 == last || current - last - 1 == 32 || last - current + 1 == 32) {
            if (flag == 0) {
                startIndexes[count] = i - 1;
                flag = 1;
            }
        } else {
            if (flag == 1) {
                endIndexes[count] = i - 1;
                count++;
                flag = 0;
            }
        }
        
        last = current;
			
	}
	
	for (i=0; i<=count; i++) {
		printTextPart(text, startIndexes[i], endIndexes[i]);
	}

    cout << "--------- Author ----------------" << endl;
	cout << "Ali Izzath Shazin" << endl;
	cout << "220071601028" << endl;
	cout << "B. Tech CSE A" << endl;
	
	return 0;
}
