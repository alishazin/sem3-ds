#include <iostream>
using namespace std;

class Matrix {

    public:

    int **mat;
    int rows, cols;

    Matrix(int rows, int cols, int instance) {

        this->rows = rows;
        this->cols = cols;

        this->mat = new int*[this->rows];
        for (int i=0; i<this->rows; i++) {
            this->mat[i] = new int[this->cols];
        }

        if (instance == 1) return;

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<this->cols; j++) {
                cout << "Enter element (" << i+1 << ", " << j+1 << ") : ";
                cin >> this->mat[i][j];
            }
        }

    }

    Matrix operator+(Matrix obj) {

        Matrix returnMat = Matrix(this->rows, this->cols, 1);

        if (this->rows != obj.rows || this->cols != obj.rows) {
            cout << "Addition not possible" << endl;
            for (int i=0; i<this->rows; i++) {
                for (int j=0; j<this->cols; j++) {
                    returnMat.mat[i][j] = -1;
                }
            }
            return returnMat;
        }

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<this->cols; j++) {
                returnMat.mat[i][j] = this->mat[i][j] + obj.mat[i][j];
            }
        }

        return returnMat;

    }

    Matrix operator-(Matrix obj) {

        Matrix returnMat = Matrix(this->rows, this->cols, 1);

        if (this->rows != obj.rows || this->cols != obj.rows) {
            cout << "Subtraction not possible" << endl;
            for (int i=0; i<this->rows; i++) {
                for (int j=0; j<this->cols; j++) {
                    returnMat.mat[i][j] = -1;
                }
            }
            return returnMat;
        }

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<this->cols; j++) {
                returnMat.mat[i][j] = this->mat[i][j] - obj.mat[i][j];
            }
        }

        return returnMat;

    }

    Matrix operator*(Matrix obj) {

        Matrix returnMat = Matrix(this->rows, obj.cols, 1);

        if (this->cols != obj.rows) {
            cout << "Multiplication not possible" << endl;
            for (int i=0; i<this->rows; i++) {
                for (int j=0; j<this->cols; j++) {
                    returnMat.mat[i][j] = -1;
                }
            }
            return returnMat;
        }

        for (int i=0; i<this->rows; i++) {
            for (int j=0; j<obj.cols; j++) {

                returnMat.mat[i][j] = 0;
                for (int k=0; k<this->cols; k++) {
                    returnMat.mat[i][j] += this->mat[i][k] * obj.mat[k][j];
                }
                
            }
        }

        return returnMat;

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

    Matrix mat1(1,2,0);
    Matrix mat2(2,3,0);

    // Matrix mat3 = mat1 + mat2;
    // Matrix mat4 = mat1 - mat2;
    Matrix mat5 = mat1 * mat2;

    // mat3.Display();
    // cout << endl;

    // mat4.Display();
    // cout << endl;

    mat5.Display();
    cout << endl;

    return 0;
}