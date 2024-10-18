#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {

    private:
        int row, col;
        int arr[100][100];

    public:
        Matrix() {
            cout << "Enter the number of rows: ";
            cin >> row;
            cout << "Enter the number of columns: ";
            cin >> col;

            // initialize the array with all zeros;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    arr[i][j] = 0;
                }
            }
        }

        Matrix(int r, int c) {
            row = r;
            col = c;

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
                    cout << right << setw(10) << arr[i][j];
                }
                cout << endl;
            }
        }

        Matrix operator +(Matrix m2) {
            Matrix m(row, col);
            if (row != m2.row || col != m2.col) {
                cout << "Error! Matrices cannot be added" << endl;
                return m;
            }
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
    int r1, c1, r2, c2;

    cout << "Enter values for matrix 1" << endl;
    Matrix m1;
    m1.read();

    cout << endl << "Enter values for matrix 2" << endl;
    Matrix m2;
    m2.read();

    Matrix m3(r1, c1), m4(r1, c2);

    cout << endl << "Matrix 1 + Matrix 2" << endl;
    m3 = m1 + m2;
    m3.show();

    cout << endl << "Matrix 1 x Matrix 2" << endl;
    m4 = m1 * m2;
    m4.show();

    return 0;
}
