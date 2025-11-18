#include <iostream>
using namespace std;

const int MAX = 100;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[MAX], R[MAX];
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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

    mergeSort(arr4, 0, n - 1);
    cout << "Merge Sort: "; printArray(arr4, n);
    return 0;
}