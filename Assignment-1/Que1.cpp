#include <iostream>
using namespace std;

void print(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

void insertion(int arr[], int &len, int element, int index) {
    for (int i = len - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    len++;
    print(arr, len);
}

void deletion(int arr[], int &len, int index) {
    for (int i = index + 1; i < len; i++) {
        arr[i - 1] = arr[i];
    }
    len--;
    print(arr, len);
}

bool search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (key == arr[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    bool x = true;
    int opt;

    int arr[100];  // Fixed max size
    int len = 0;   // Current number of elements

    cout << " ---- Menu Driven Program ---- \n";
    cout << " 1.  Create \n 2.  Display \n 3.  Insert" << endl;
    cout << " 4.  Delete \n 5.  Linear Search \n 6.  Quit " << endl;

    while (x == true) {
        cout << "Enter ur choice: ";
        cin >> opt;
        cout << endl;

        switch (opt) {
        case 1: // Create
            cout << "Number of elements: ";
            cin >> len;
            cout << "Enter elements: ";
            for (int i = 0; i < len; i++) {
                cin >> arr[i];
            }
            cout << endl;
            break;

        case 2: // Display
            if (len == 0) cout << "Array is empty!\n";
            else print(arr, len);
            break;

        case 3: // Insert
            int a, p;
            cout << "Enter element to insert: ";
            cin >> a;
            cout << "Enter position (0-based index): ";
            cin >> p;
            if (p >= 0 && p <= len) {
                insertion(arr, len, a, p);
            } else {
                cout << "Invalid position!\n";
            }
            break;

        case 4: // Delete
            cout << "Enter position to delete (0-based index): ";
            cin >> p;
            if (p >= 0 && p < len) {
                deletion(arr, len, p);
            } else {
                cout << "Invalid position!\n";
            }
            break;

        case 5: // Linear Search
            int key;
            cout << "Enter element to search: ";
            cin >> key;
            if (search(arr, len, key)) {
                cout << "Key is present" << endl;
            } else {
                cout << "Key is absent" << endl;
            }
            break;

        case 6:
            x = false;
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }
    }
    return 0;
}
