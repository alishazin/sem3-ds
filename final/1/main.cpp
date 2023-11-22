#include <iostream>
using namespace std;

void findMinAndMax(int arr[], int size) {

    int i;
    int min = arr[0];
    int max = arr[0];

    for (i=1; i<size; i++) {

        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }

    }

    cout << "Maximum number in array: " << max << endl;
    cout << "Minimum number in array: " << min << endl;

}

int main() {

    int arr[] = {8, 9, 4, 12, 34, 5, 6};
    findMinAndMax(arr, 7);

    return 0;
}