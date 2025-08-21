//Remove duplicate elements

#include <iostream>
using namespace std;

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

void deletion(int arr[], int len, int index)
{
    for (int i = index + 1; i < len ; i++ )
    {
        arr[i-1] = arr[i];
    }
    len--;
}

void unique(int arr[], int len, int index)
{
    for (int i = 0; i < len ; i++ ){
        for(int j = i+1; j < len; j++){
            if(arr[i]==arr[j]){
                deletion(arr,len,j);
            }
        }
    }
    
}

int main()
{
    int a, b, n;
    int arr1[10] = {10, 14, 7, 14, 8, 6};
    n = 6;
    print(arr1, n);
    unique(arr1, n, a);
    print(arr1,n-1);
}


