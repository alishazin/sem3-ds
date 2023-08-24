#include <iostream>
using namespace std;

class Exception {
    public:
    virtual string msg() = 0;
};

class InvalidSize: public Exception {
    public:
    string msg() {
        return "Size should be greater than zero.";
    }
};

class OperationFailed: public Exception {
    public:
    string msg() {
        return "Both matrix should be of same size.";
    }
};

class MultiplicationFailed: public Exception {
    public:
    string msg() {
        return "Number of columns in the 1st matrix must be equal to the rows in the 2nd matrix.";
    }
};

class Matrix {

    int _rows, _cols;
    int **mat;

    Matrix doAddOrSub(Matrix obj, int instance) {
        if (this->_rows != obj._rows || this->_cols != obj._cols) throw OperationFailed();
        
        Matrix returnMat = Matrix(this->_rows, this->_cols);
        returnMat.initializeMatrix();

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

    void initializeMatrix() {
        this->mat = new int*[this->_rows];
        for(int i = 0; i < this->_rows; i++) {
            this->mat[i] = new int[this->_cols];
        }
    }

    public:
        
        Matrix(int rows, int cols) {
            if (rows <= 0 || cols <= 0) throw InvalidSize();
            this->_rows = rows;
            this->_cols = cols;

            this->initializeMatrix();
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
            returnMat.initializeMatrix();

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
            returnMat.initializeMatrix();

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