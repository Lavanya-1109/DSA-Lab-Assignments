#include <iostream>
using namespace std;

const int MAX = 100;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (!swapped) break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int original[] = {64, 25, 12, 22, 11};
    int n = sizeof(original) / sizeof(original[0]);

    int arr1[MAX], arr2[MAX], arr3[MAX], arr4[MAX], arr5[MAX];
    copy(original, original + n, arr1);
    copy(original, original + n, arr2);
    copy(original, original + n, arr3);
    copy(original, original + n, arr4);
    copy(original, original + n, arr5);

    bubbleSort(arr1, n);
    cout << "Bubble Sort: "; printArray(arr1, n);
    return 0;
}