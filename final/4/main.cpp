#include <iostream>
using namespace std;

class Matrix {

    public:

    int **mat;
    int rows;
    int cols;

    Matrix(int r, int c, int askInput) {

        this->rows = r;
        this->cols = c;

        this->mat = new int*[r];
        for (int i=0; i<r; i++) {
            this->mat[i] = new int[c];
        }

        if (askInput) {

            for (int i=0; i<this->rows; i++) {
                for (int j=0; j<this->cols; j++) {
                    cout << "Enter element (" << i+1 << ", " << j+1 << "): ";
                    cin >> this->mat[i][j];
                }
            }

        }

    }

    Matrix operator+(Matrix obj) {

        Matrix matRes(this->rows, this->cols, 0);
        
        if (this->rows != obj.rows || this->cols != obj.cols) {
            cout << "Addition not possible" << endl;
            return matRes;
        }

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<this->cols; j++) {
                matRes.mat[i][j] = this->mat[i][j] + obj.mat[i][j];
            }
        }
        
        return matRes;

    }

    Matrix operator-(Matrix obj) {

        Matrix matRes(this->rows, this->cols, 0);
        
        if (this->rows != obj.rows || this->cols != obj.cols) {
            cout << "Addition not possible" << endl;
            return matRes;
        }

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<this->cols; j++) {
                matRes.mat[i][j] = this->mat[i][j] - obj.mat[i][j];
            }
        }
        
        return matRes;

    }

    Matrix operator*(Matrix obj) {

        Matrix matRes(this->rows, obj.cols, 0);
        
        if (this->cols != obj.rows) {
            cout << "Multiplication not possible" << endl;
            return matRes;
        }

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<obj.cols; j++) {

                matRes.mat[i][j] = 0;
                for (int k=0; k<this->cols; k++) {
                    matRes.mat[i][j] += this->mat[i][k] * obj.mat[k][j];
                }
            }
        }
        
        return matRes;

    }

    void Display() {

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<this->cols; j++) {
                cout << this->mat[i][j] << "\t";
            }
            cout << endl;
        }

    }

};

int main() {

    Matrix mat1(2, 2, 1);
    Matrix mat2(1, 3, 1);

    (mat1 + mat2).Display();
    cout << endl;

    (mat1 - mat2).Display();
    cout << endl;

    (mat1 * mat2).Display();
    cout << endl;

    return 0;
}