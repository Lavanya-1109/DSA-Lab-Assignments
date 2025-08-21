#include <iostream>
using namespace std;

#define MAX 10

void print(int arr[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout << "Enter rows and columns for first : ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second : ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << " multiplication not possible!" << endl;
        return 0;
    }

    cout << "Enter elements of first :" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter elements of second :" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    multiply(A, B, C, r1, c1, c2);

    cout << "Resultant :" << endl;
    print(C, r1, c2);

    return 0;
}