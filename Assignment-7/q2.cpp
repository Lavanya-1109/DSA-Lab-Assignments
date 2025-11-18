#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIdx = start, maxIdx = start;

        for (int i = start; i <= end; ++i) {
            if (arr[i] < arr[minIdx]) minIdx = i;
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }

        swap(arr[start], arr[minIdx]);

        if (maxIdx == start) maxIdx = minIdx;

        swap(arr[end], arr[maxIdx]);

        ++start;
        --end;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}