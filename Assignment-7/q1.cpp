#include <iostream>
using namespace std;

const int MAX = 100;

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
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

    selectionSort(arr1, n);
    cout << "Selection Sort: "; printArray(arr1, n);
    return 0;
}