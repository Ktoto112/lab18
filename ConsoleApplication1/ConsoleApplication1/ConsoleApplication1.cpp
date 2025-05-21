#include <iostream>

using namespace std;

class Matrix {
private:
    int data[3][3]; 

public:
    
    Matrix(int a11 = 0, int a12 = 0, int a13 = 0,
        int a21 = 0, int a22 = 0, int a23 = 0,
        int a31 = 0, int a32 = 0, int a33 = 0) {
        data[0][0] = a11; data[0][1] = a12; data[0][2] = a13;
        data[1][0] = a21; data[1][1] = a22; data[1][2] = a23;
        data[2][0] = a31; data[2][1] = a32; data[2][2] = a33;
    }

 
    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

   
    Matrix operator*(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
   
    Matrix A(1, 2, 3,
        4, 5, 6,
        7, 8, 9);

    Matrix B(9, 8, 7,
        6, 5, 4,
        3, 2, 1);

    cout << "Matrix A:\n"; A.print();
    cout << "\nMatrix B:\n"; B.print();

   
    Matrix C = A * B;
    cout << "\nA * B:\n"; C.print();

    return 0;
}