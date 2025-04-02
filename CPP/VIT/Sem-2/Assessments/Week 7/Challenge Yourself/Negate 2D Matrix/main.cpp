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

    Matrix operator-() const {
        Matrix negated(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                negated.data[i][j] = -data[i][j];
            }
        }
        return negated;
    }
};

int main() {
    int rows, cols;
    cin >> rows >> cols;
    Matrix mat(rows, cols);
    mat.input();

    cout << "Original Matrix: ";
    mat.print();

    cout << "Negated Matrix: ";
    (-mat).print();

    return 0;
}