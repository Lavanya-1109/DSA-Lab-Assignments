#include <iostream>
using namespace std;

//binary search

int findMissingBinary(int arr[], int n) {
    int start = 0, end = n - 2;  
    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] != mid + 1) {
            
            end = mid - 1;
        } else {
            
            start = mid + 1;
        }
    }
    return start + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = 8;

    cout << "Missing number (Binary): " << findMissingBinary(arr, n);
    return 0;
}
