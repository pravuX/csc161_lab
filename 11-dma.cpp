#include <iostream>

using namespace std;

class Matrix {

    private:
        int row, col;
        int **arr;

    public:
        Matrix(int r, int c) {
            row = r;
            col = c;

            // first create an array of pointers i.e. columns
            arr = new int*[r];
            // next create a row for each pointer
            for (int i = 0; i < c; i++) {
                arr[i] = new int[r];
            }
            // initialize the array with all zeros;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    arr[i][j] = 0;
                }
            }
        }

        void read() {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    printf("arr[%d][%d] = ", i, j);
                    cin >> arr[i][j];
                }
            }
        }

        void show() {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        Matrix operator +(Matrix m2) {
            Matrix m(row, col);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    m.arr[i][j] += arr[i][j] + m2.arr[i][j];
                }
            }
            return m;
        }

        Matrix operator *(Matrix m2) {
            Matrix m(row, m2.col);
            if (col != m2.row) {
                cout << "Error! Matrices cannot be multiplied" << endl;
                return m;
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < m2.col; j++) {
                    for (int k = 0; k < col; k++) {
                        m.arr[i][j] += arr[i][k] * m2.arr[k][j];
                    }
                }
            }
            return m;
        }
};

int main() {
    Matrix m1(2, 2), m2(2, 2), m3(2, 2), m4(2, 2);
    cout << "Enter values for matrix 1" << endl;
    m1.read();
    cout << endl << "Enter values for matrix 2" << endl;
    m2.read();
    m3 = m1 + m2;
    cout << endl << "Matrix 1 + Matrix 2" << endl;
    m3.show();
    m4 = m1 * m2;
    cout << endl << "Matrix 1 * Matrix 2" << endl;
    m4.show();
    return 0;
}
