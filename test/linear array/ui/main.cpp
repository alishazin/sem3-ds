#include <iostream>
using namespace std;

void Display(int arr[], int &n, int &size) {
    cout << endl;
    cout << "[";
    for (int i=0; i<n; i++) {
        if (i == n - 1) cout << arr[i];
        else cout << arr[i] << ", ";
    }
    cout << "] Size = " << size << endl << endl;
}

void Insert(int arr[], int &n, int size, int index, int item) {
    /* 
        [1, 2, 3, 4] 
         0  1  2  3
        index = 1
        3, 2, 1 { (n - 1) to index } 
    */

    if (n == size) {
        cout << "Array overflow!" << endl << endl;
        return;
    }

    if (index > n || index < 0) {
        cout << "Array out of bound" << endl << endl;
        return;
    }

    for (int i=n-1; i>= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = item;
    n++;

}

void Delete(int arr[], int &n, int index) {
    /* 
        [1, 2, 3, 4] 
         0  1  2  3
        index = 1
        1, 2 { index to n - 2 } 
    */

    if (index > n - 1 || index < 0) {
        cout << endl;
        cout << "Array out of bound" << endl;
        return;
    }

    for (int i=index; i<n-1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void Search(int arr[], int &n, int item) {

    for (int i=0; i<n; i++) {
        if (arr[i] == item) {
            cout << "Element found in (" << i << ")th index." << endl << endl;
            return;
        }
    }
    cout << "Element not found!" << endl << endl;

}

void Sort(int arr[], int &n) {

    int i, j, temp, swapped_flag = 0;
    
    for (i=0; i<n-1; i++) {

        for (j=0; j<n-i-1; j++) {

            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped_flag = 1;
            }

        }

        // If no swaps in one traversal.
        if (swapped_flag == 0) break;

    }
    
}

void Resize(int arr[], int &n, int &size, int newSize) {

    int *newArr = new int[newSize];

    for (int i=0; i<newSize; i++) {
        if (i < n) {
            newArr[i] = arr[i];
        } else {
            break;
        }
    }

    arr = newArr;
    size = newSize;

    if (newSize < n) {
        n = newSize;
    }

    cout << "Resizing completed." << endl << endl;

}

int main() {

    int size, n, i, choice, temp1, temp2;

    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];

    while (true) {
        cout << "Enter number of elements to insert: ";
        cin >> n;

        if (n > size) {
            cout << "Number of elements to insert should be lesser than or equal to the given size!" << endl;
            continue;
        }
        break;
    }

    for (i=0; i<n; i++) {
        cout << "Enter (" << i + 1 << ")th element: ";
        cin >> arr[i];
    }

    while (true) {

        cout << "----------- Array Operation -----------" << endl;
        cout << "1. Display Array." << endl;
        cout << "2. Insert Array." << endl;
        cout << "3. Delete Array." << endl;
        cout << "4. Search In Array." << endl;
        cout << "5. Sort Array." << endl;
        cout << "6. Resize Array." << endl;
        cout << "7. Exit." << endl;
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) {

            Display(arr, n, size);

        } else if (choice == 2) {

            cout << endl;
            cout << "Enter element to insert: ";
            cin >> temp1;

            cout << "Enter index to insert to: ";
            cin >> temp2;
            cout << endl;

            Insert(arr, n, size, temp2, temp1);

        } else if (choice == 3) {

            cout << endl;
            cout << "Enter index to delete: ";
            cin >> temp1;

            Delete(arr, n, temp1);
            cout << endl;
            
        } else if (choice == 4) {
            
            cout << endl;
            cout << "Enter element to find: ";
            cin >> temp1;

            Search(arr, n, temp1);

        } else if (choice == 5) {
        
            Sort(arr, n);
            cout << endl << "Sorting completed." << endl << endl;

        } else if (choice == 6) {
            
            cout << endl;
            cout << "Enter the size to resize to: ";
            cin >> temp1;
            Resize(arr, n, size, temp1);

        } else if (choice == 7) {
            
            cout << endl;
            cout << "Thank you. Exiting.." << endl;
            return 0;

        } else {
            
            cout << endl;
            cout << "Invalid choice" << endl << endl;
            continue;

        }

    }

    return 0;
}