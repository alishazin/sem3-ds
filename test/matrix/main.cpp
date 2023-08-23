#include <iostream>
using namespace std;

class InvalidSize {
    public:
    string msg = "Size should be greater than zero.";
};

class OperationFailed {
    public:
    string msg = "Both matrix should be of same size.";
};

class MultiplicationFailed {
    public:
    string msg = "Number of columns in the 1st matrix must be equal to the rows in the 2nd matrix.";
};

class Matrix {

    int _rows, _cols;
    int **mat;

    Matrix doAddOrSub(Matrix obj, int instance) {
        if (this->_rows != obj._rows || this->_cols != obj._cols) throw OperationFailed();
        Matrix returnMat = Matrix(this->_rows, this->_cols);
        returnMat.mat = new int*[this->_rows];
        for(int i = 0; i < this->_rows; ++i) {
            returnMat.mat[i] = new int[this->_cols];
        }

        for (int i=0; i<this->_rows; i++) {
            for (int j=0; j<this->_cols; j++) {
                if (instance == 0) {
                    returnMat.mat[i][j] = this->mat[i][j] + obj.mat[i][j];
                } else if (instance == 1) {
                    returnMat.mat[i][j] = this->mat[i][j] - obj.mat[i][j];
                }
            }
        }

        return returnMat;
    }

    void initializeMatrix(int rows, int cols) {
        this->mat = new int*[rows];
        for(int i = 0; i < rows; i++) {
            this->mat[i] = new int[cols];
        }
    }

    public:
        
        Matrix(int rows, int cols) {
            if (rows <= 0 || cols <= 0) throw InvalidSize();
            this->_rows = rows;
            this->_cols = cols;

            initializeMatrix(rows, cols);
        }

        Matrix operator+(Matrix obj) {
            return doAddOrSub(obj, 0);
        }

        Matrix operator-(Matrix obj) {            
            return doAddOrSub(obj, 1);
        }

        Matrix operator*(Matrix obj) {
            if (this->_cols != obj._rows) throw MultiplicationFailed();
            
            Matrix returnMat = Matrix(this->_rows, obj._cols);
            returnMat.initializeMatrix(this->_rows, obj._cols);

            for(int i=0; i<this->_rows; i++) {    
                for(int j=0; j<obj._cols; j++) {  
                    
                    returnMat.mat[i][j]=0;   
                    for(int k=0; k<this->_cols; k++) {   
                        returnMat.mat[i][j] += this->mat[i][k] * obj.mat[k][j]; 
                    }    
                }    
            } 
            return returnMat;
        }

        Matrix operator*(int scalar) {            
            Matrix returnMat = Matrix(this->_rows, this->_cols);
            returnMat.initializeMatrix(this->_rows, this->_cols);

            for(int i=0; i<this->_rows; i++) {    
                for(int j=0; j<this->_cols; j++) {  
                    returnMat.mat[i][j] = scalar * this->mat[i][j];      
                }    
            } 
            return returnMat;
        }

        void askElements() {
            for (int i=0; i<this->_rows; i++) {
                for (int j=0; j<this->_cols; j++) {
                    cout << "Enter element (" << i+1 << ", " << j+1 << "): ";
                    cin >> this->mat[i][j];
                }
            }
        }

        void display() {
            for (int i=0; i<this->_rows; i++) {
                for (int j=0; j<this->_cols; j++) {
                    cout << this->mat[i][j] << "\t";
                }
                cout << endl;
            }
            cout << "(" << this->_rows << ", " << this->_cols << ")" << endl;
        }

        int rows() {
            return this->_rows;
        }

        int cols() {
            return this->_cols;
        }

};

ostream& operator<<(ostream &out, Matrix obj) {
    obj.display();
    return out;
}

int main() {

    Matrix m1 = Matrix(2, 1);
    m1.askElements();
    cout << m1 << endl;

    Matrix m2 = Matrix(1, 3);
    m2.askElements();
    cout << m2 << endl;

    // Matrix m3 = m1 + m2;
    // cout << m3 << endl;
    // cout << m1 - m2 << endl;
    cout << (m1 * m2).rows() << endl;
    cout << (m1 * m2).cols() << endl;
    // cout << m1 * 10 << endl;

    return 0;
}