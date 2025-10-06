#include <iostream>
using namespace std;

class Qarr {
    int arr[10];
    int size = 10;
    int start = -1;
    int end = -1;
    int cnt = 0;

public:
    void push(int x) {
        if (end == size - 1) {
            cout << "Queue Full!" << endl;
        } else {
            if (start == -1) start = 0;
            arr[++end] = x;
            cnt++;
        }
    }

    void pop() {
        if (cnt == 0) {
            cout << "Queue Empty!" << endl;
        } else {
            if (start == end) {
                start = -1;
                end = -1;
            } else {
                start++;
            }
            cnt--;
        }
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return end == size - 1;
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
            for (int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Qarr q;
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
