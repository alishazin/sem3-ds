// Find maximum and minimum element in an array.

#include <iostream>
using namespace std;

void findMinMax(int arr[], int size) {
	
	int i, min = arr[0], max = arr[0];
	
	for (i=1; i<size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
		
	};
	
	cout << "Minimum value is : " << min << endl;
	cout << "Maximum value is : " << max << endl;
	
	cout << endl;
	
}

int main() {
	
	int size, i;
	
	cout << "Enter size of array: ";
	cin >> size;
	
	int arr[size];
	
	for (i=0; i<size; i++) {
		cout << "Enter element " << i + 1 << " : ";
		cin >> arr[i]; 
	}
	
	cout << endl;
	
	findMinMax(arr, size);
	
	cout << "--------- Author ----------------" << endl;
	cout << "Ali Izzath Shazin" << endl;
	cout << "220071601028" << endl;
	cout << "B. Tech CSE A" << endl;
	
	return 0;
}
