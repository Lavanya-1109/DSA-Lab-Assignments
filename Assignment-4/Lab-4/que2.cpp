#include <iostream>
using namespace std;

class CQueue {
    int arr[10];
    int size = 10;
    int start = -1;
    int end = -1;

public:
    void push(int x) {
        if ((start == 0 && end == size - 1) || (end + 1) % size == start) {
            cout << "Queue Full!" << endl;
        } else {
            if (start == -1) {
                start = 0;
                end = 0;
            } else {
                end = (end + 1) % size;
            }
            arr[end] = x;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
        } else if (start == end) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % size;
        }
    }

    bool isEmpty() {
        return start == -1;
    }

    bool isFull() {
        return (start == 0 && end == size - 1) || (end + 1) % size == start;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
            return -1;
        }
        return arr[start];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
        } else {
            int i = start;
            while (true) {
                cout << arr[i] << " ";
                if (i == end) break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
};

int main() {
    CQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    cout << "Peek: " << q.peek() << endl;
    q.pop();
    q.display();
    cout << "Peek: " << q.peek() << endl;
    return 0;
}