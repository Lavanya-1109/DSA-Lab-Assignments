//Transpose of an array
#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[10][10], int m,int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j=0;j<n ;j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void transpose(int arr[10][10],int m,int n){
    int B[10][10];
    for (int i = 0; i < m ; i++)
    {
        for (int j=0; j < n ;j++){
            B[j][i]=arr[i][j];
        }
    }
    cout << "Transpose :" << endl;
    print(B,n,m);
}

int main(){
    int m=2,n=3;
    int A[10][10] = {{10, 14, 7},{12, 8, 6}};
    cout << "Before :" << endl;
    print(A,m,n);
    transpose(A,m,n);
}
