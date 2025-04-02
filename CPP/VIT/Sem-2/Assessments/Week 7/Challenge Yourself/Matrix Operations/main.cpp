#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    int rows, cols;
    vector<vector<int>> data;

    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c)) {}

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void print() const {
        for (const auto &row : data) {
            for (int val : row) {
                cout << val << " ";
            }
        }
        cout << endl;
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }

    Matrix multiply(const Matrix &other) const {
        if (cols != other.rows) {
            throw invalid_argument("Invalid matrix dimensions for multiplication");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int rows1, cols1, rows2, cols2;
    cin >> rows1 >> cols1;
    Matrix mat1(rows1, cols1);
    mat1.input();
    
    cin >> rows2 >> cols2;
    Matrix mat2(rows2, cols2);
    mat2.input();
    
    if (cols1 == rows2) {
        cout << "Matrix product: ";
        mat1.multiply(mat2).print();
    } else {
        cout << "Matrix multiplication not possible" << endl;
    }
    
    cout << "Transpose of the first matrix: ";
    mat1.transpose().print();
    
    return 0;
}