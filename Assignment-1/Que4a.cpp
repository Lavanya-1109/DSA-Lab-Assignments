//Reverse elements of an array
#include <iostream>
#include<algorithm>
using namespace std;

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}
void reverse(int arr[],int len){
    for(int i=0,j=len-1;i<len/2&& j>=i;i++,j--)
    {
        swap(arr[i],arr[j]);
    }
    print(arr,len);
}

int main(){
    int a, b, n;
    int arr1[10] = {10, 14, 7, 12, 8, 6};
    n = 6;
    print(arr1, n);
    
    reverse(arr1, n);
}