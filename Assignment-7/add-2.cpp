#include <iostream>
#include <vector>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}
void countingSort(int arr[], int n, int place) {
    const int range = 10; 
    vector<int> output(n);
    vector<int> count(range, 0);

    for (int i = 0; i < n; ++i)
        ++count[(arr[i] / place) % 10];

    for (int i = 1; i < range; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / place) % 10;
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    int X = 0, temp = maxVal;
    while (temp > 0) {
        ++X;
        temp /= 10;
    }

    cout << "Maximum element: " << maxVal << endl;
    cout << "Number of digits (X): " << X << endl;

    for (int place = 1; maxVal / place > 0; place *= 10)
        countingSort(arr, n, place);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}