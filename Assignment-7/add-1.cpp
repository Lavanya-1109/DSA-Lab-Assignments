#include <iostream>
#include <vector>
using namespace std;
void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    std::vector<int> count(maxVal + 1); 
    for (int i = 0; i < n; ++i)
        ++count[arr[i]];

    int index = 0;
    for (int i = 0; i <= maxVal; ++i)
        while (count[i]--)
            arr[index++] = i;
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

    countingSort(arr, n);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}