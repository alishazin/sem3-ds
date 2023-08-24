// Matrix addition, subtraction and multiplication.

#include <iostream>
#include "matrix.cpp"
using namespace std;

int main() {
    
    int mat1_r, mat1_c, mat2_r, mat2_c;

    cout << "Enter mat1 rows and columns: ";
    cin >> mat1_r >> mat1_c;
    Matrix mat1 = Matrix(mat1_r, mat1_c);

    cout << "Enter mat1 elements: " << endl;
    mat1.askElements();
    cout << mat1 << endl;

    cout << "Enter mat2 rows and columns: ";
    cin >> mat2_r >> mat2_c;
    Matrix mat2 = Matrix(mat2_r, mat2_c);

    cout << "Enter mat2 elements: " << endl;
    mat2.askElements();
    cout << mat2 << endl;

    try {
        Matrix mat3 = mat1 + mat2;
        cout << mat3 << endl;   
    } catch(Exception &e) {
        cout << "Addition Failed: " << e.msg() << endl;
    }

    try {
        cout << mat1 - mat2 << endl; 
    } catch(Exception &e) {
        cout << "Subtraction Failed: " << e.msg() << endl;
    }

    try {
        cout << mat1 * mat2 << endl;   
    } catch(Exception &e) {
        cout << "Multiplication Failed: " << e.msg() << endl;
    }

    cout << mat1 * 10 << endl;   

    return 0;
    
}