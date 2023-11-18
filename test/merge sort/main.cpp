#include <iostream>
#include <cstdlib>
using namespace std;

void Merge(int *A, int *L, int leftCount, int *R, int rightCount) {
    
    int i,j,k;
    i = 0; j = 0; k =0;
    
    while(i < leftCount && j < rightCount) {  
        
        if(L[i] < R[j]) 
            A[k++] = L[i++];
        
        else 
            A[k++] = R[j++];
            
    }

    while(i < leftCount)
        A[k++] = L[i++];
    
    while(j < rightCount)
        A[k++] = R[j++];
}


void MergeSort(int *A, int n) {
    
    int mid, i, *L, *R;  
    
    if(n < 2) return;  

    mid = n/2;
    
    L = (int*) malloc(mid * sizeof(int));
    R = (int*) malloc((n - mid) * sizeof(int));

    for(i = 0; i<mid; i++)
        L[i] = A[i];
    for(i = 0; i<n-mid; i++)
        R[i] = A[i+mid];

    // ----------------
    cout << endl << "Before: " << endl;
    cout << "A: ";
    for (int i=0; i<n; i++) cout << A[i] << ", ";
    cout << endl;
    cout << "L: ";
    for (int i=0; i<mid; i++) cout << L[i] << ", ";
    cout << endl;
    cout << "R: ";
    for (int i=0; i<n-mid; i++) cout << R[i] << ", ";
    cout << endl;
    // ----------------

    MergeSort(L, mid);  
    MergeSort(R, n-mid);  

    // ----------------
    cout << endl << "After: " << endl;
    cout << "A: ";
    for (int i=0; i<n; i++) cout << A[i] << ", ";
    cout << endl;
    cout << "L: ";
    for (int i=0; i<mid; i++) cout << L[i] << ", ";
    cout << endl;
    cout << "R: ";
    for (int i=0; i<n-mid; i++) cout << R[i] << ", ";
    cout << endl;
    cout << "leftC = " << mid << " rightC = " << n-mid << endl;
    // ----------------
    
    Merge(A, L, mid, R, n - mid);
    
    // ----------------
    cout << "A: ";
    for (int i=0; i<n; i++) cout << A[i] << ", ";
    cout << endl;
    // ----------------

    free(L);
    free(R);
}

int main() {

    int arr[] = {10,2, 8, 4, 1, 14, 12, 15};

    MergeSort(arr, 8);

    cout << endl << "FINAL: ";
    for (int i=0; i<8; i++) {
        cout << arr[i] << ", ";
    }

    return 0;
}