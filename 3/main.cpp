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
        cout << "4. Exit." << endl;
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) {

            Display(arr, n, size);

        } else if (choice == 2) {

            cout << endl << "Enter element to insert: ";
            cin >> temp1;

            cout << "Enter index to insert to: ";
            cin >> temp2;
            cout << endl;

            Insert(arr, n, size, temp2, temp1);

        } else if (choice == 3) {

            cout << endl << "Enter index to delete: ";
            cin >> temp1;

            Delete(arr, n, temp1);
            cout << endl;
            
        } else if (choice == 4) {

            cout << endl << "Thank you. Exiting.." << endl;
            cout << "--------- Author ----------------" << endl;
    		cout << "Ali Izzath Shazin" << endl;
    		cout << "220071601028" << endl;
    		cout << "B. Tech CSE A" << endl;
            return 0;

        } else {
            
            cout << endl << "Invalid choice" << endl << endl;
            continue;

        }

    }

    return 0;
}