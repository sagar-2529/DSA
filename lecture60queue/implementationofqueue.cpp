#include <iostream>
using namespace std;

class MyQueue {
public:
    int *arr;
    int size; 
    int rear;
    int front;

    MyQueue() {
        size = 100001;
        arr = new int[size];
        rear = 0;
        front = 0;
    }

    ~MyQueue() {
        delete[] arr; // Free allocated memory
    }

    void push(int data) {
        if (rear == size) {
            cout << "Queue is full." << endl; 
        } else {
            arr[rear++] = data;
        }
    }

    void pop() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
        } else {
            front++;
        }
    }

    int frontValue() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
            return -1; // Indicate an error
        }
        return arr[front];
    }

    bool isempty() {
        return rear == front;
    }

    int sizeQueue() {
        return rear - front; // Returns the number of elements in the queue
    }
};

int main() {
    MyQueue q; // Create an instance of MyQueue
    q.push(5);
    cout << "Front element: " << q.frontValue() << endl; // Should output 5
    q.pop();
    cout << "Is queue empty? " << (q.isempty() ? "Yes" : "No") << endl; // Should output Yes

    return 0;
}
