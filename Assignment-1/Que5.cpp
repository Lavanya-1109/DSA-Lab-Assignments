//Sum of each row and column of a matrix
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

int main(){
    int r,c ;
    int arr[MAX][MAX];
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    cout << "Enter elements of the matrix: " << endl;
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cin >> arr[i][j];
        }
    }
    cout << "The matrix is: " << endl;
    print(arr, r, c);

    cout << "Sum of each row: " << endl;
    for(int i=0 ; i<r ; i++){
        int sum = 0;
        for(int j=0 ; j<c ; j++){
            sum += arr[i][j];
        }
        cout << "Row " << i+1 << ": " << sum << endl;
    }

    cout << "Sum of each column: " << endl;
    for(int j=0 ; j<c ; j++){
        int sum = 0;
        for(int i=0 ; i<r ; i++){
            sum += arr[i][j];
        }
        cout << "Column " << j+1 << ": " << sum << endl;
    }
    
}