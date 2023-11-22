#include <iostream>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n) {

    int i, j, temp, swapped;
    
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

        if (swapped == 0) return;

    }

}

void selectionSort(int arr[], int n) {

    int i, j, temp, minIndex, minValue;

    for (i=0; i<n; i++) {

        minValue = arr[i];
        minIndex = i;

        for (j=i+1; j<n; j++) {

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

void insertionSort(int arr[], int n) {

    int i, index, value;

    for (i=1; i<n; i++) {

        index = i;
        value = arr[i];

        while (index > 0 && arr[index - 1] > value) {
            arr[index] = arr[index - 1];
            index--;
        }

        arr[index] = value;

    }

}

void Merge(int* arr, int* leftArr, int leftSize, int* rightArr, int rightSize) {

    int i=0, j=0, k=0;

    while (i < leftSize && j < rightSize) {

        if (leftArr[i] < rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];

    }

    while (i < leftSize) arr[k++] = leftArr[i++];
    while (j < rightSize) arr[k++] = rightArr[j++];

}

void MergeSort(int* arr, int size) {

    int mid, i, *leftArr, *rightArr;

    if (size < 2) return;
    
    mid = size / 2;

    leftArr = (int*) malloc(sizeof(int) * size);
    rightArr = (int*) malloc(sizeof(int) * (size - mid));

    for (i=0; i<mid; i++) leftArr[i] = arr[i];
    for (i=0; i<size - mid; i++) rightArr[i] = arr[i + mid];

    MergeSort(leftArr, mid);
    MergeSort(rightArr, size - mid);

    Merge(arr, leftArr, mid, rightArr, size - mid);

    free(leftArr);
    free(rightArr);

}

int main() {

    int arr[] = {10,4,2,7,5,8};

    // bubbleSort(arr, 6);
    // selectionSort(arr, 6);
    // insertionSort(arr, 6);
    MergeSort(arr, 6);

    cout << "[ ";
    for(int i=0; i<6; i++) cout << arr[i] << ", ";
    cout << "] " << endl;

    return 0;
}