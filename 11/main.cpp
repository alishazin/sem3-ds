#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n) {
    
    int i, j, swapped, temp;

    for (i=0; i<n; i++) {

        swapped = 0;

        for (j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                swapped = 1;
            }
        }

        if (swapped == 0) {
            return;
        }
    }

}

void selectionSort(int *arr, int length) {

    int i, j, minIndex, minValue, temp;

    for (i=0; i<length; i++) {

        minValue = arr[i];
        minIndex = i;

        for (j=i+1; j<length; j++) {
            if (arr[j] < minValue) {
                minValue = arr[j];
                minIndex = j;
            }
        }

        // swapping
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

    }

}

void insertionSort(int *arr, int length) {

    int i, value, index;

    for (i=1; i<length; i++) {

        value = arr[i];
        index = i;

        while (index > 0 && arr[index - 1] > value) {
            arr[index] = arr[index - 1];
            index--;
        }

        arr[index] = value;

    }

}

int main() {

    int length, choice;

    cout << "Enter length of array: ";
    cin >> length;

    int *arr = (int*) malloc(length * sizeof(int));

    for (int i=0; i<length; i++) {
        cout << "Enter item " << i+1 << " : ";
        cin >> arr[i];
    }

    cout << "Before Sorting: " << endl;
    for (int i=0; i<length; i++) cout << arr[i] << ", ";
    cout << endl;

    cout << "--------- Sorting Methods ---------" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        bubbleSort(arr, length);
    } else if (choice == 2) {
        selectionSort(arr, length);
    } else if (choice == 3) {
        insertionSort(arr, length);
    }

    cout << "After Sorting: " << endl;
    for (int i=0; i<length; i++) cout << arr[i] << ", ";
    cout << endl;


    return 0;
}