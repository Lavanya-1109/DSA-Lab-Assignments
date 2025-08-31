#include <iostream>
using namespace std;
//linear time
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = 8; 

    cout << "Missing number (Linear): " << findMissingLinear(arr, n);
    return 0;
}
